// LoanManager.cpp - Implémentation du gestionnaire d'emprunts
#include "LoanManager.h"
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>

void LoanManager::borrowBook(const std::string& bookId, const std::string& userId, const std::string& date) {
    std::string when = date;
    if (when.empty() || when == "today") {
        // generate timestamp
        auto now = std::chrono::system_clock::now();
        std::time_t tt = std::chrono::system_clock::to_time_t(now);
        char buf[64];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&tt));
        when = buf;
    }
    loans.push_back({bookId, userId, when, ""});
}

void LoanManager::returnBook(const std::string& bookId) {
    auto it = std::find_if(loans.begin(), loans.end(),
        [&bookId](const Loan& l) { return l.bookId == bookId && l.returnDate.empty(); });
    if (it != loans.end()) {
        auto now = std::chrono::system_clock::now();
        std::time_t tt = std::chrono::system_clock::to_time_t(now);
        char buf[64];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&tt));
        it->returnDate = buf;
    }
}

std::vector<Loan> LoanManager::getActiveLoans() const
{
    std::vector<Loan> active;
    std::copy_if(loans.begin(), loans.end(), std::back_inserter(active),
                 [](const Loan &l)
                 { return l.returnDate.empty(); });
    return active;
}

std::vector<Loan> LoanManager::getLoansByUserId(const std::string& userId) const {
    std::vector<Loan> res;
    std::copy_if(loans.begin(), loans.end(), std::back_inserter(res),
        [&userId](const Loan& l) { return l.userId == userId && l.returnDate.empty(); });
    return res;
}

bool LoanManager::isBookAvailable(const std::string& bookId) const {
    auto it = std::find_if(loans.begin(), loans.end(),
        [&bookId](const Loan& l) { return l.bookId == bookId && l.returnDate.empty(); });
    return it == loans.end();
}

bool LoanManager::saveToFile(const std::string& path) const {
    std::ofstream ofs(path);
    if (!ofs) return false;
    for (auto& l : loans) {
        ofs << l.bookId << "|" << l.userId << "|" << l.borrowDate << "|" << l.returnDate << "\n";
    }
    return true;
}

bool LoanManager::loadFromFile(const std::string& path) {
    std::ifstream ifs(path);
    if (!ifs) return false;
    loans.clear();
    std::string line;
    while (std::getline(ifs, line)) {
        if (line.empty()) continue;
        std::istringstream ss(line);
        Loan l;
        if (!std::getline(ss, l.bookId, '|')) continue;
        if (!std::getline(ss, l.userId, '|')) continue;
        if (!std::getline(ss, l.borrowDate, '|')) continue;
        if (!std::getline(ss, l.returnDate, '|')) l.returnDate = "";
        loans.push_back(l);
    }
    return true;
}