// Library.h - Gestion principale de la bibliothèque
#ifndef LIBRARY_H
#define LIBRARY_H

#include "../models/Book.h"
#include "../models/User.h"
#include "BookManager.h"
#include "UserManager.h"
#include "LoanManager.h"

class Library {
private:
    BookManager bookManager;
    UserManager userManager;
    LoanManager loanManager;
public:
    // Book operations
    bool addBook(const Book& book);
    bool removeBookById(const std::string& id);

    // User operations
    bool registerUser(const User& user);
    User* findUserByEmail(const std::string& email);
    std::vector<Book> listBooks() const;
    std::vector<User> listUsers() const;
    BookManager& books();
    UserManager& users();
    // Loan operations
    bool borrowBookById(const std::string& bookId, const std::string& userId, const std::string& date);
    bool returnBookById(const std::string& bookId);
    std::vector<Loan> listLoansByUserId(const std::string& userId) const;
    bool isBookAvailable(const std::string& bookId) const;
    std::vector<Book> findBooksByTitle(const std::string& title) const;
    std::vector<Book> findBooksByAuthor(const std::string& author) const;
    std::vector<Book> findBooksByIsbn(const std::string& isbn) const;
    bool loadData(const std::string& dir);
    bool saveData(const std::string& dir) const;
};

#endif