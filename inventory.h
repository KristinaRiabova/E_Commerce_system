#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <memory>
#include "productcatalog.h"
#include "order.h"

class Inventory {
public:
    Inventory(ProductCatalog& productCatalog);
    void addProductToInventory(const std::shared_ptr<Product>& product);
    void manageStock(int productID, int quantity);
    void notifyLowStock(const std::vector<Order>& shoppingCart) const;

private:
    ProductCatalog& productCatalog;
    std::vector<std::shared_ptr<Product>> products;
    int lowStockThreshold;
};

#endif // INVENTORY_H
