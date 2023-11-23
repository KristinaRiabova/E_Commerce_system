// Order.h
#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "product.h"

class Order {
public:
    Order(int orderID, const std::string& customer);
    // Move constructor
    Order(Order&& other) noexcept;

    void addProduct(const std::shared_ptr<Product>& product, int quantity);
    double calculateTotalCost() const;
    void changeOrderStatus(const std::string& status);
    std::vector<std::pair<std::shared_ptr<Product>, int>> getProducts() const;
    int getOrderID() const;
    std::string getCustomer() const;
    double getTotalCost() const;
    std::string getOrderStatus() const;

private:
    int orderID;
    std::string customer;
    std::vector<std::pair<std::shared_ptr<Product>, int>> products;
    double totalCost;
    std::string orderStatus;
};

#endif

