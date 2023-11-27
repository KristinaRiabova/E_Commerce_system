#include "productcatalog.h"
#include "Electronics.h"
#include "clothing.h"
#include "books.h"
ProductCatalog::ProductCatalog() : nextProductID(1) {}

int ProductCatalog::getNewProductID() {
    return nextProductID++;
}

void ProductCatalog::addProduct(const std::shared_ptr<Product>& product) {
    products.push_back(product);
}

void ProductCatalog::updateProduct(int productID, const std::shared_ptr<Product>& updatedProduct) {
    for (auto& product : products) {
        if (product->getProductID() == productID) {
            product = updatedProduct;
            return;
        }
    }
    std::cerr << "Product with ID " << productID << " not found in the catalog." << std::endl;
}

void ProductCatalog::removeProduct(int productID) {
    products.erase(
            std::remove_if(products.begin(), products.end(),
                           [productID](const std::shared_ptr<Product>& p) { return p->getProductID() == productID; }),
            products.end());
}

const std::vector<std::shared_ptr<Product>>& ProductCatalog::getProducts() const {
    return products;
}

std::vector<std::shared_ptr<Product>>& ProductCatalog::getProducts() {
    return products;
}

void ProductCatalog::listAllProducts() const {
    std::cout << "Choose a category to browse:\n";
    std::cout << "1. Electronics\n";
    std::cout << "2. Books\n";
    std::cout << "3. Clothing\n";
    std::cout << "4. All Products\n";
    std::cout << "5. Enter a product name to filter\n";
    std::cout << "Enter your choice: ";

    int categoryChoice;
    std::cin >> categoryChoice;

    for (const auto& product : products) {
        bool displayProduct = false;

        switch (categoryChoice) {
            case 1: // Electronics
                if (product->getCategory() == "Electronics") {
                    displayProduct = true;
                }
                break;
            case 2: // Books
                if (product->getCategory() == "Books") {
                    displayProduct = true;
                }
                break;
            case 3: // Clothing
                if (product->getCategory() == "Clothing") {
                    displayProduct = true;
                }
                break;
            case 4: // All Products
                displayProduct = true;
                break;
            case 5: // Enter a product name to filter
                displayProductsWithFilter();
                break;

            default:
                std::cout << "Invalid choice. Displaying all products.\n";
                displayProduct = true;
                break;
        }

        if (displayProduct) {
            product->displayDetails();

            // Try dynamic_cast to access specific properties or methods of derived classes
            if (auto bookProduct = dynamic_cast<const Books*>(product.get())) {
                // Dynamic cast to Books, then access book-specific information
                std::string author = bookProduct->getAuthor();
                std::cout << "Author: " << author << "\n";
            } else if (auto electronicsProduct = dynamic_cast<const Electronics*>(product.get())) {
                // Dynamic cast to Electronics, then access electronics-specific information
                std::string brand = electronicsProduct->getBrand();
                std::string model = electronicsProduct->getModel();
                std::string powerConsumption = electronicsProduct->getPowerConsumption();
                std::cout << "Brand: " << brand << "\n";
                std::cout << "Model: " << model << "\n";
            } else if (auto clothingProduct = dynamic_cast<const Clothing*>(product.get())) {
                // Dynamic cast to Clothing, then access clothing-specific information
                std::string size = clothingProduct->getSize();
                std::cout << "Size: " << size << "\n";
            }

            // Add a separator for better readability
            std::cout << "-----------------------------------\n";
        }
    }
}


void ProductCatalog::displayProductsWithFilter() const {
    std::cout << "Enter a product name to filter: ";
    std::string filter;
    std::cin.ignore();
    std::getline(std::cin, filter);

    std::cout << "Filtered Product List:\n";

    for (const auto& product : products) {

        if (filter.empty() || filterByName(product, filter)) {
            product->displayInfo();
        }
    }
}

bool ProductCatalog::filterByName(const std::shared_ptr<Product>& product, const std::string& filter) const {
    std::string productNameLower = product->getName();
    std::transform(productNameLower.begin(), productNameLower.end(), productNameLower.begin(), ::tolower);

    std::string filterLower = filter;
    std::transform(filterLower.begin(), filterLower.end(), filterLower.begin(), ::tolower);


    return productNameLower.find(filterLower) != std::string::npos;
}

