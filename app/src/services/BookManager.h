// BookManager.h - Gestion des livres
#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include <vector>
#include "../models/Book.h"

class BookManager {
private:
    std::vector<Book> books;
public:
    void addBook(const Book& book);
    bool removeBook(const std::string& title);
    Book* findBook(const std::string& title);
    std::vector<Book> getAllBooks() const;
};

#endif