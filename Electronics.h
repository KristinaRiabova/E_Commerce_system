#ifndef ELECTRONICS_H
#define ELECTRONICS_H

#include "product.h"

class Electronics : public Product {
public:
    Electronics(int productID, const std::string& name, double price, int quantityInStock,
                const std::string& brand, const std::string& model, const std::string& powerConsumption);

    std::string getCategory() const override;

    std::string getBrand() const;
    std::string getModel() const;
    std::string getPowerConsumption() const;

private:
    std::string brand;
    std::string model;
    std::string powerConsumption;
};

#endif // ELECTRONICS_H
