#include "order.h"

Order::Order(int orderID, const std::string& customer)
        : orderID(orderID), customer(customer), totalCost(0.0), orderStatus("Pending") {}

void Order::addProduct(const std::shared_ptr<Product>& product, int quantity) {
    if (product->getQuantityInStock() >= quantity) {
        products.push_back(std::make_pair(product, quantity));
        totalCost += product->calculateTotalCost(quantity);
    } else {
        std::cout << "Not enough stock available for " << product->getName() << ". Current quantity: " << product->getQuantityInStock() << std::endl;
    }
}

double Order::calculateTotalCost() const {
    return totalCost;
}

void Order::changeOrderStatus(const std::string& status) {
    orderStatus = status;
}

std::vector<std::pair<std::shared_ptr<Product>, int>> Order::getProducts() const {
    return products;
}

int Order::getOrderID() const {
    return orderID;
}

std::string Order::getCustomer() const {
    return customer;
}

double Order::getTotalCost() const {
    return totalCost;
}

std::string Order::getOrderStatus() const {
    return orderStatus;
}
