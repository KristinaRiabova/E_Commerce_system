#include "clothing.h"

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
