// BookManager.cpp - Implémentation du gestionnaire de livres
#include "BookManager.h"
#include <algorithm>
#include <fstream>
#include <sstream>

bool BookManager::addBook(const Book& book) {
    // prevent duplicate ISBN (only if ISBN is not empty)
    if (!book.getIsbn().empty()) {
        auto found = findByIsbn(book.getIsbn());
        if (!found.empty()) return false;
    }
    books.push_back(book);
    return true;
}

bool BookManager::removeBookById(const std::string& id) {
    auto it = std::find_if(books.begin(), books.end(),
        [&id](const Book& b) { return b.getId() == id; });
    if (it != books.end()) {
        books.erase(it);
        return true;
    }
    return false;
}

Book* BookManager::findBookById(const std::string& id) {
    for (auto& book : books) {
        if (book.getId() == id) return &book;
    }
    return nullptr;
}

std::vector<Book> BookManager::getAllBooks() const {
    return std::vector<Book>(books.begin(), books.end());
}

std::vector<Book> BookManager::findByTitle(const std::string& title) const {
    std::vector<Book> results;
    for (auto& b : books) {
        if (b.getTitle().find(title) != std::string::npos) results.push_back(b);
    }
    return results;
}

std::vector<Book> BookManager::findByAuthor(const std::string& author) const {
    std::vector<Book> results;
    for (auto& b : books) {
        if (b.getAuthor().find(author) != std::string::npos) results.push_back(b);
    }
    return results;
}

std::vector<Book> BookManager::findByIsbn(const std::string& isbn) const {
    std::vector<Book> results;
    for (auto& b : books) {
        if (b.getIsbn() == isbn) results.push_back(b);
    }
    return results;
}

bool BookManager::saveToFile(const std::string& path) const {
    std::ofstream ofs(path);
    if (!ofs) return false;
    for (auto& b : books) {
        // id|title|author|year|isbn
        ofs << b.getId() << "|" << b.getTitle() << "|" << b.getAuthor() << "|" << b.getYear() << "|" << b.getIsbn() << "\n";
    }
    return true;
}

bool BookManager::loadFromFile(const std::string& path) {
    std::ifstream ifs(path);
    if (!ifs) return false;
    books.clear();
    std::string line;
    while (std::getline(ifs, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back(); // handle Windows line endings
        }
        if (line.empty()) continue;
        std::istringstream ss(line);
        std::string id, title, author, yearstr, isbn;
        if (!std::getline(ss, id, '|')) continue;
        if (!std::getline(ss, title, '|')) continue;
        if (!std::getline(ss, author, '|')) continue;
        if (!std::getline(ss, yearstr, '|')) continue;
        if (!std::getline(ss, isbn, '|')) isbn = "";
        int year = 0;
        try {
            year = std::stoi(yearstr);
        } catch (const std::exception&) {
            continue;
        }
        books.emplace_back(id, title, author, year, isbn);
    }
    return true;
}