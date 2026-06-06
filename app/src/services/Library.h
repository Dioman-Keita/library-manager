// Library.h - Gestion principale de la bibliothèque
#ifndef LIBRARY_H
#define LIBRARY_H

#include "../models/Book.h"
#include "../models/User.h"

class Library {
public:
    void addBook(const Book& book);
    void removeBook(const std::string& title);
    void registerUser(const User& user);
};

#endif