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


            productCatalog.updateProduct((*it)->getProductID(), *it);




            std::cout << "Stock updated for " << (*it)->getName() << ". Remaining quantity: " << (*it)->getQuantityInStock() << std::endl;
        } else {
            std::cout << "Not enough stock available for " << (*it)->getName() << ". Current quantity: " << (*it)->getQuantityInStock() << std::endl;
        }
    } else {
        std::cout << "Product not found in the catalog." << std::endl;
    }
}

void Inventory::notifyLowStock(const std::vector<Order>& shoppingCart) const {
    // Check products in the inventory
    for (const auto& product : products) {
        if (product->getQuantityInStock() < lowStockThreshold) {
            std::cout << "Low stock for " << product->getName() << ". Current quantity: " << product->getQuantityInStock() << std::endl;
        }
    }


    for (const auto& order : shoppingCart) {
        for (const auto& cartItem : order.getProducts()) {
            const Product& product = *(cartItem.first);
            int quantityInCart = cartItem.second;

            if (quantityInCart > 0 && quantityInCart < lowStockThreshold) {
                std::cout << "Low stock for " << product.getName() << ". Quantity in cart: " << quantityInCart << std::endl;
            }
        }
    }
}
