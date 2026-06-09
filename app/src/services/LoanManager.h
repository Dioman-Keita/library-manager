// LoanManager.h - Gestion des emprunts
#ifndef LOANMANAGER_H
#define LOANMANAGER_H

#include <vector>
#include <string>
#include "../models/Book.h"
#include "../models/User.h"

struct Loan {
    std::string bookId;
    std::string userId;
    std::string borrowDate;
    std::string returnDate;
};

class LoanManager {
private:
    std::vector<Loan> loans;
public:
    void borrowBook(const std::string& bookId, const std::string& userId, const std::string& date);
    void returnBook(const std::string& bookId);
    std::vector<Loan> getActiveLoans() const;
    std::vector<Loan> getLoansByUserId(const std::string& userId) const;
    bool isBookAvailable(const std::string& bookId) const;
    bool saveToFile(const std::string& path) const;
    bool loadFromFile(const std::string& path);
};

#endif