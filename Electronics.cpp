#include "electronics.h"

Electronics::Electronics(int productID, const std::string& name, double price, int quantityInStock,
                         const std::string& brand, const std::string& model, const std::string& powerConsumption)
        : Product(productID, name, price, quantityInStock), brand(brand), model(model), powerConsumption(powerConsumption) {}

std::string Electronics::getCategory() const {
    return "Electronics";
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
