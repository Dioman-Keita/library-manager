// test_book.cpp - Tests unitaires pour la classe Book
#include <iostream>
#include "../src/models/Book.h"

int main() {
    Book b("Test", "Auteur", 2023);
    std::cout << "Titre : " << b.getTitle() << std::endl;
    return 0;
}