// User.cpp - Implémentation de la classe User
#include "User.h"
#include <algorithm>

User::User(int id, const std::string& name, const std::string& email)
    : id(id), name(name), email(email) {}

// Getters
int User::getId() const { return id; }
std::string User::getName() const { return name; }
std::string User::getEmail() const { return email; }
std::vector<Book> User::getBorrowedBooks() const { return borrowedBooks; }

// Setters
void User::setName(const std::string& name) { this->name = name; }
void User::setEmail(const std::string& email) { this->email = email; }

// Gestion de la liste des livres empruntés
void User::borrowBook(const Book& book) {
    borrowedBooks.push_back(book);
}

void User::returnBook(const Book& book) {
    borrowedBooks.erase(
        std::remove_if(borrowedBooks.begin(), borrowedBooks.end(),
            [&book](const Book& b) {
                return b.getTitle() == book.getTitle() && 
                       b.getAuthor() == book.getAuthor() && 
                       b.getYear() == book.getYear();
            }),
        borrowedBooks.end()
    );
}

bool User::hasBorrowedBook(const Book& book) const {
    for (const auto& b : borrowedBooks) {
        if (b.getTitle() == book.getTitle() && 
            b.getAuthor() == book.getAuthor() && 
            b.getYear() == book.getYear()) {
            return true;
        }
    }
    return false;
}

int User::getBorrowedBooksCount() const {
    return borrowedBooks.size();
}