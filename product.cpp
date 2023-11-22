#include "product.h"

// Implementation of the Product class

Product::Product(int productID, const std::string& name, double price, int quantityInStock)
        : productID(productID), name(name), price(price), quantityInStock(quantityInStock) {}

double Product::calculateTotalCost(int quantity) const {
    return price * quantity;
}

void Product::displayInfo() const {
    std::cout << "Product ID: " << getProductID() << "\n";
    std::cout << "Name: " << getName() << "\n";
    std::cout << "Price: $" << getPrice() << "\n";
    std::cout << "In Stock: " << getQuantityInStock() << "\n\n";
}

int Product::getProductID() const {
    return productID;
}

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantityInStock() const {
    return quantityInStock;
}

void Product::setName(const std::string& newName) {
    name = newName;
}

void Product::setPrice(double newPrice) {
    price = newPrice;
}

void Product::setQuantityInStock(int newQuantity) {
    quantityInStock = newQuantity;
}
