#include <iostream>
#include <fstream>
#include <sstream>
#include "productcatalog.h"
#include "inventory.h"
#include "userinterface.h"
#include "utils.h"
#include "Electronics.h"
#include "books.h"
#include "clothing.h"




int main() {

    ProductCatalog productCatalog;
    Inventory inventory(productCatalog);


    std::ifstream configFile("products.txt");
    if (!configFile.is_open()) {
        std::cerr << "Failed to open the configuration file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(configFile, line)) {
        std::istringstream iss(line);
        std::string category, name, author, brand, model, powerConsumption, genre, ISBN, size, color, material;
        double price;
        int quantity;


        std::vector<std::string> tokens;
        std::string token;
        while (std::getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() < 4) {
            std::cerr << "Error parsing line: " << line << std::endl;
            continue;
        }


        category = tokens[0];
        name = tokens[1];
        if (!parseDouble(tokens[2], price) || !parseInt(tokens[3], quantity)) {
            std::cerr << "Error parsing line: " << line << std::endl;
            continue;
        }

        std::cout << "Reading product information:\n";
        std::cout << "Category: " << category << "\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Price: " << price << "\n";
        std::cout << "Quantity: " << quantity << "\n";

        // Handle specific attributes based on the category
        if (category == "Electronics" && tokens.size() >= 7) {
            brand = tokens[4];
            model = tokens[5];
            powerConsumption = tokens[6];

            std::cout << "Brand: " << brand << "\n";
            std::cout << "Model: " << model << "\n";
            std::cout << "Power Consumption: " << powerConsumption << "\n";
        } else if (category == "Books" && tokens.size() >= 7) {
            author = tokens[4];
            genre = tokens[5];
            ISBN = tokens[6];

            std::cout << "Author: " << author << "\n";
            std::cout << "Genre: " << genre << "\n";
            std::cout << "ISBN: " << ISBN << "\n";
        } else if (category == "Clothing" && tokens.size() >= 7) {
            size = tokens[4];
            color = tokens[5];
            material = tokens[6];

            std::cout << "Size: " << size << "\n";
            std::cout << "Color: " << color << "\n";
            std::cout << "Material: " << material << "\n";
        } else {
            std::cerr << "Unknown product category in the configuration file." << std::endl;
            continue;
        }

        if (category == "Electronics") {
            auto product = std::make_shared<Electronics>(productCatalog.getNewProductID(), name, price, quantity, brand, model, powerConsumption);
            productCatalog.addProduct(product);
        } else if (category == "Books") {
            auto product = std::make_shared<Books>(productCatalog.getNewProductID(), name, price, quantity, author, genre, ISBN);
            productCatalog.addProduct(product);
        } else if (category == "Clothing") {
            auto product = std::make_shared<Clothing>(productCatalog.getNewProductID(), name, price, quantity, size, color, material);
            productCatalog.addProduct(product);
        }



        std::cout << "-----------------------------------" << std::endl;
    }

    configFile.close();


    UserInterface userInterface(productCatalog, inventory);


    userInterface.run();

    return 0;
}
