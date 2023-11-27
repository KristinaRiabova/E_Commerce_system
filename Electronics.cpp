#include "Electronics.h"  // Include the class header
#include <iostream>

Electronics::Electronics(int productID, const std::string& name, double price, int quantityInStock,
                         const std::string& brand, const std::string& model, const std::string& powerConsumption)
        : Product(productID, name, price, quantityInStock), brand(brand), model(model), powerConsumption(powerConsumption) {}

std::string Electronics::getCategory() const {
    return "Electronics";
}

void Electronics::displayDetails() const {

    std::cout << "Brand: " << getBrand() << "\n";
    std::cout << "Model: " << getModel() << "\n";
    std::cout << "Power Consumption: " << getPowerConsumption() << "\n";

    Product::displayDetails();
}

std::string Electronics::getBrand() const {
    return brand;
}

std::string Electronics::getModel() const {
    return model;
}

std::string Electronics::getPowerConsumption() const {
    return powerConsumption;
}
