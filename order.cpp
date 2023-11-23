#include "order.h"

Order::Order(int orderID, const std::string& customer)
        : orderID(orderID), customer(customer), totalCost(0.0), orderStatus("Pending") {}

// Move constructor implementation
Order::Order(Order&& other) noexcept
        : orderID(other.orderID),
          customer(std::move(other.customer)),
          products(std::move(other.products)),
          totalCost(other.totalCost),
          orderStatus(std::move(other.orderStatus)) {

    other.orderID = 0;
    other.totalCost = 0.0;
}

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
