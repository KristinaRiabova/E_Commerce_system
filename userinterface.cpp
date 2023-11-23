#include "userinterface.h"

UserInterface::UserInterface(ProductCatalog& catalog, Inventory& inventory)
        : catalog(catalog), inventory(inventory) {}

void UserInterface::run() {
    while (true) {
        std::cout << "Welcome to the E-Commerce System\n";
        std::cout << "1. Browse Products\n";
        std::cout << "2. Add Product to Cart\n";
        std::cout << "3. Proceed to Checkout\n";
        std::cout << "4. View Order History\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                catalog.listAllProducts();
                break;
            case 2:
                addProductToCart();
                break;
            case 3:
                proceedToCheckout();
                break;
            case 4:
                viewOrderHistory();
                break;
            case 5:
                std::cout << "Goodbye!" << std::endl;
                return;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;

        }

        inventory.notifyLowStock(shoppingCart);
    }
}

void UserInterface::addProductToCart() {
    int productId, quantity;

    std::cout << "Enter the product ID you want to add to the cart: ";
    std::cin >> productId;

    auto it = std::find_if(catalog.getProducts().begin(), catalog.getProducts().end(),
                           [productId](const std::shared_ptr<Product>& p) { return p->getProductID() == productId; });

    if (it != catalog.getProducts().end()) {
        std::cout << "Enter the quantity: ";
        std::cin >> quantity;

        if (quantity > 0 && quantity <= (*it)->getQuantityInStock()) {
            Order order(orderHistory.size() + 1, "Customer Name");
            order.addProduct(*it, quantity);

            cartProductIndices.push_back(std::distance(catalog.getProducts().begin(), it));

            shoppingCart.push_back(order);
            std::cout << "Product added to the cart." << std::endl;
        } else {
            std::cout << "Invalid quantity or product is out of stock." << std::endl;
        }
    } else {
        std::cout << "Product not found in the catalog." << std::endl;
    }
}

void UserInterface::proceedToCheckout() {
    if (shoppingCart.empty()) {
        std::cout << "Your shopping cart is empty." << std::endl;
        return;
    }



    std::cout << "Shopping Cart Contents:\n";
    double totalCost = 0.0;

    for (const Order& order : shoppingCart) {
        for (const auto& cartItem : order.getProducts()) {
            const Product& product = *(cartItem.first);
            int quantity = cartItem.second;

            std::cout << "Product: " << product.getName() << "\n";
            std::cout << "Price per unit: $" << product.getPrice() << "\n";
            std::cout << "Quantity: " << quantity << "\n";
            double itemCost = product.calculateTotalCost(quantity);
            totalCost += itemCost;
            std::cout << "Subtotal: $" << itemCost << "\n\n";



        }
    }

    std::cout << "Total Cost: $" << totalCost << "\n";

    std::string customerName;
    std::cout << "Enter your name: ";
    std::cin.ignore();
    std::getline(std::cin, customerName);


    Order checkoutOrder(orderHistory.size() + 1, customerName);
    for (const Order& order : shoppingCart) {
        for (const auto& cartItem : order.getProducts()) {
            const std::shared_ptr<Product>& product = cartItem.first;
            int quantity = cartItem.second;
            checkoutOrder.addProduct(product, quantity);

            inventory.manageStock(product->getProductID(), quantity);

        }


    }
    checkoutOrder.changeOrderStatus("Paid");


    orderHistory.push_back(checkoutOrder);


    shoppingCart.clear();


    std::cout << "Order placed successfully. Thank you, " << customerName << "!" << std::endl;
}

void UserInterface::viewOrderHistory() const {
    if (orderHistory.empty()) {
        std::cout << "No order history available.\n";
    } else {
        std::cout << "Order History:\n";
        for (const Order& order : orderHistory) {
            std::cout << "Order ID: " << order.getOrderID() << "\n";
            std::cout << "Customer: " << order.getCustomer() << "\n";
            std::cout << "Status: " << order.getOrderStatus() << "\n";
            std::cout << "Total Cost: $" << order.getTotalCost() << "\n";
            std::cout << "Products:\n";
            for (const auto& cartItem : order.getProducts()) {
                const std::shared_ptr<Product>& product = cartItem.first;
                int quantity = cartItem.second;
                std::cout << "- " << product->getName() << " (Quantity: " << quantity << ")\n";
            }
            std::cout << "\n";
        }
    }
}

