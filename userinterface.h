#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include <vector>
#include "productcatalog.h"
#include "inventory.h"

class UserInterface {
public:
    UserInterface(ProductCatalog& catalog, Inventory& inventory);
    void run();

private:
    ProductCatalog& catalog;
    Inventory& inventory;
    std::vector<Order> shoppingCart;
    std::vector<Order> orderHistory;
    std::vector<int> cartProductIndices;

    void addProductToCart();
    void proceedToCheckout();
    void viewOrderHistory() const;
};

#endif