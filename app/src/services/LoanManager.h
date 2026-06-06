// LoanManager.h - Gestion des emprunts
#ifndef LOANMANAGER_H
#define LOANMANAGER_H

#include <vector>
#include <string>
#include "../models/Book.h"
#include "../models/User.h"

struct Loan {
    Book book;
    User user;
    std::string borrowDate;
    std::string returnDate;
};

class LoanManager {
private:
    std::vector<Loan> loans;
public:
    void borrowBook(const Book& book, const User& user, const std::string& date);
    void returnBook(const Book& book);
    std::vector<Loan> getActiveLoans() const;
};

#endif