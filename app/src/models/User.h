// User.h - Définition de la classe User
#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Book.h"

class User {
private:
    int id;
    std::string name;
    std::string email;
    std::vector<Book> borrowedBooks;

public:
    User(int id, const std::string& name, const std::string& email);
    
    // Getters
    int getId() const;
    std::string getName() const;
    std::string getEmail() const;
    std::vector<Book> getBorrowedBooks() const;
                       
    // Setters
    void setName(const std::string& name);
    void setEmail(const std::string& email);
    
    // Gestion de la liste des livres empruntés
    void borrowBook(const Book& book);
    void returnBook(const Book& book);
    bool hasBorrowedBook(const Book& book) const;
    int getBorrowedBooksCount() const;
};

#endif