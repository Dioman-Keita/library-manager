// Library.cpp - Implémentation de la classe Library
#include "Library.h"
#include <algorithm>

bool Library::addBook(const Book& book) {
    bool ok = bookManager.addBook(book);
    if (ok) saveData("data");
    return ok;
}

bool Library::removeBookById(const std::string& id) {
    return bookManager.removeBookById(id);
}

bool Library::registerUser(const User& user) {
    bool ok = userManager.addUser(user);
    if (ok) saveData("data");
    return ok;
}

User* Library::findUserByEmail(const std::string& email) {
    return userManager.findUserByEmail(email);
}

std::vector<Book> Library::listBooks() const {
    return bookManager.getAllBooks();
}

std::vector<User> Library::listUsers() const {
    return userManager.getAllUsers();
}

BookManager& Library::books() { return bookManager; }
UserManager& Library::users() { return userManager; }

bool Library::borrowBookById(const std::string& bookId, const std::string& userId, const std::string& date) {
    if (!bookManager.findBookById(bookId)) return false;
    if (!userManager.findUserById(userId)) return false;
    if (!loanManager.isBookAvailable(bookId)) return false;
    loanManager.borrowBook(bookId, userId, date);
    saveData("data");
    return true;
}

bool Library::returnBookById(const std::string& bookId) {
    if (!bookManager.findBookById(bookId)) return false;
    loanManager.returnBook(bookId);
    saveData("data");
    return true;
}

std::vector<Loan> Library::listLoansByUserId(const std::string& userId) const {
    return loanManager.getLoansByUserId(userId);
}

bool Library::isBookAvailable(const std::string& bookId) const {
    return loanManager.isBookAvailable(bookId);
}

std::vector<Book> Library::findBooksByTitle(const std::string& title) const {
    return bookManager.findByTitle(title);
}

std::vector<Book> Library::findBooksByAuthor(const std::string& author) const {
    return bookManager.findByAuthor(author);
}

std::vector<Book> Library::findBooksByIsbn(const std::string& isbn) const {
    return bookManager.findByIsbn(isbn);
}

bool Library::loadData(const std::string& dir) {
    bool ok1 = bookManager.loadFromFile(dir + "/books.txt");
    bool ok2 = userManager.loadFromFile(dir + "/users.txt");
    bool ok3 = loanManager.loadFromFile(dir + "/loans.txt");
    (void)ok1; (void)ok2; (void)ok3;
    return ok1 || ok2 || ok3;
}

bool Library::saveData(const std::string& dir) const {
    bool ok1 = bookManager.saveToFile(dir + "/books.txt");
    bool ok2 = userManager.saveToFile(dir + "/users.txt");
    bool ok3 = loanManager.saveToFile(dir + "/loans.txt");
    return ok1 && ok2 && ok3;
}