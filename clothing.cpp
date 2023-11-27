#include "clothing.h"
#include <iostream>

Clothing::Clothing(int productID, const std::string& name, double price, int quantityInStock,
                   const std::string& size, const std::string& color, const std::string& material)
        : Product(productID, name, price, quantityInStock), size(size), color(color), material(material) {}

std::string Clothing::getCategory() const {
    return "Clothing";
}

std::string Clothing::getSize() const {
    return size;
}

std::string Clothing::getColor() const {
    return color;
}

std::string Clothing::getMaterial() const {
    return material;
}

void Clothing::displayDetails() const {
    std::cout << "Size: " << getSize() << "\n";
    std::cout << "Color: " << getColor() << "\n";
    std::cout << "Material: " << getMaterial() << "\n";
    Product::displayDetails();  // Assuming the base class has a displayDetails function
}
