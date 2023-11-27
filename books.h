#ifndef BOOKS_H
#define BOOKS_H

#include "product.h"

class Books : public Product {
public:
    Books(int productID, const std::string& name, double price, int quantityInStock,
          const std::string& author, const std::string& genre, const std::string& ISBN);

    std::string getCategory() const override;
    std::string getAuthor() const;
    std::string getGenre() const;
    std::string getISBN() const;

    void displayDetails() const override;

private:
    std::string author;
    std::string genre;
    std::string ISBN;
};

#endif

