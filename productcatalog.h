#ifndef PRODUCTCATALOG_H
#define PRODUCTCATALOG_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include "product.h"
#include "order.h"

class ProductCatalog {
public:
    ProductCatalog();
    int getNewProductID();
    void addProduct(const std::shared_ptr<Product>& product);
    void updateProduct(int productID, const std::shared_ptr<Product>& updatedProduct);
    void removeProduct(int productID);
    const std::vector<std::shared_ptr<Product>>& getProducts() const;
    std::vector<std::shared_ptr<Product>>& getProducts();
    void listAllProducts() const;
    void displayProductsWithFilter() const;
    bool filterByName(const std::shared_ptr<Product>& product, const std::string& filter) const;

private:
    std::vector<std::shared_ptr<Product>> products;
    int nextProductID;
};

#endif // PRODUCTCATALOG_H
