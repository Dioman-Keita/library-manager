// test_book.cpp - Tests unitaires pour la classe Book
#include <iostream>
#include "../src/models/Book.h"
#include "../src/utils/IdGenerator.h"

int main() {
    std::string id = util::generateId();
    Book b(id, "Test", "Auteur", 2023, "ISBN-TEST-001");
    std::cout << "ID : " << b.getId() << " Titre : " << b.getTitle() << " ISBN:" << b.getIsbn() << std::endl;
    return 0;
}