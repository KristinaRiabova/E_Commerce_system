// product.h
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    Product(int productID, const std::string& name, double price, int quantityInStock);
    virtual ~Product() = default;

    double calculateTotalCost(int quantity) const;
    virtual void displayInfo() const;
    virtual std::string getCategory() const = 0;
    virtual void displayDetails() const = 0;

    int getProductID() const;
    std::string getName() const;
    double getPrice() const;
    int getQuantityInStock() const;

    void setName(const std::string& newName);
    void setPrice(double newPrice);
    void setQuantityInStock(int newQuantity);

private:
    int productID;
    std::string name;
    double price;
    int quantityInStock;
};

#endif // PRODUCT_H
