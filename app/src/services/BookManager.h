// BookManager.h - Gestion des livres
#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include <list>
#include <vector>
#include <string>
#include "../models/Book.h"

class BookManager {
private:
    std::list<Book> books;
public:
    bool addBook(const Book& book);
    bool removeBookById(const std::string& id);
    Book* findBookById(const std::string& id);
    std::vector<Book> findByTitle(const std::string& title) const;
    std::vector<Book> findByAuthor(const std::string& author) const;
    std::vector<Book> findByIsbn(const std::string& isbn) const;
    std::vector<Book> getAllBooks() const;
    bool saveToFile(const std::string& path) const;
    bool loadFromFile(const std::string& path);
};

#endif