#include "books.h"
#include <iostream>

Books::Books(int productID, const std::string& name, double price, int quantityInStock,
             const std::string& author, const std::string& genre, const std::string& ISBN)
        : Product(productID, name, price, quantityInStock), author(author), genre(genre), ISBN(ISBN) {}

std::string Books::getCategory() const {
    return "Books";
}

std::string Books::getAuthor() const {
    return author;
}

std::string Books::getGenre() const {
    return genre;
}

std::string Books::getISBN() const {
    return ISBN;
}

void Books::displayDetails() const {
    std::cout << "Author: " << getAuthor() << "\n";
    std::cout << "Genre: " << getGenre() << "\n";
    std::cout << "ISBN: " << getISBN() << "\n";
    Product::displayDetails();  // Assuming the base class has a displayDetails function
}
