#ifndef CLOTHING_H
#define CLOTHING_H

#include "product.h"

class Clothing : public Product {
public:
    Clothing(int productID, const std::string& name, double price, int quantityInStock,
             const std::string& size, const std::string& color, const std::string& material);

    std::string getCategory() const override;

    std::string getSize() const;
    std::string getColor() const;
    std::string getMaterial() const;

private:
    std::string size;
    std::string color;
    std::string material;
};

#endif // CLOTHING_H
