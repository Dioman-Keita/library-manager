// LoanManager.cpp - Implémentation du gestionnaire d'emprunts
#include "LoanManager.h"
#include <algorithm>

void LoanManager::borrowBook(const Book& book, const User& user, const std::string& date) {
    loans.push_back({book, user, date, ""});
}

void LoanManager::returnBook(const Book& book) {
    auto it = std::find_if(loans.begin(), loans.end(),
        [&book](const Loan& l) { return l.book.getTitle() == book.getTitle(); });
    if (it != loans.end()) {
        it->returnDate = "today";
    }
}

std::vector<Loan> LoanManager::getActiveLoans() const {
    std::vector<Loan> active;
    std::copy_if(loans.begin(), loans.end(), std::back_inserter(active),
        [](const Loan& l) { return l.returnDate.empty(); });
    return active;
}