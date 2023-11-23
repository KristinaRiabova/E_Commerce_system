#include "inventory.h"

Inventory::Inventory(ProductCatalog& productCatalog) : productCatalog(productCatalog) {}

void Inventory::addProductToInventory(const std::shared_ptr<Product>& product) {
    products.push_back(product);
}

void Inventory::manageStock(int productID, int quantity) {
    auto& productCatalogProducts = productCatalog.getProducts();

    auto it = std::find_if(productCatalogProducts.begin(), productCatalogProducts.end(),
                           [productID](const std::shared_ptr<Product>& p) { return p->getProductID() == productID; });

    if (it != productCatalogProducts.end()) {
        if ((*it)->getQuantityInStock() >= quantity) {

            (*it)->setQuantityInStock((*it)->getQuantityInStock() - quantity);

            if ((*it)->getQuantityInStock() == 0) {

                productCatalog.removeProduct((*it)->getProductID());
            } else {

                productCatalog.updateProduct((*it)->getProductID(), *it);
            }


            std::cout << "Stock updated for " << (*it)->getName() << ". Remaining quantity: " << (*it)->getQuantityInStock() << std::endl;
        } else {
            std::cout << "Not enough stock available for " << (*it)->getName() << ". Current quantity: " << (*it)->getQuantityInStock() << std::endl;
        }
    } else {
        std::cout << "Product not found in the catalog." << std::endl;
    }
}


void Inventory::notifyLowStock(const std::vector<Order>& shoppingCart) const {

    for (const auto& product : productCatalog.getProducts()) {
        if (product->getQuantityInStock() < lowStockThreshold) {
            std::cout << "Low stock for " << product->getName() << ". Current quantity: " << product->getQuantityInStock() << std::endl;
        }
    }
}

