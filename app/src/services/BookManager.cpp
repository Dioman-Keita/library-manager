// BookManager.cpp - Implémentation du gestionnaire de livres
#include "BookManager.h"
#include <algorithm>

void BookManager::addBook(const Book& book) {
    books.push_back(book);
}

bool BookManager::removeBook(const std::string& title) {
    auto it = std::find_if(books.begin(), books.end(),
        [&title](const Book& b) { return b.getTitle() == title; });
    if (it != books.end()) {
        books.erase(it);
        return true;
    }
    return false;
}

Book* BookManager::findBook(const std::string& title) {
    for (auto& book : books) {
        if (book.getTitle() == title) return &book;
    }
    return nullptr;
}

std::vector<Book> BookManager::getAllBooks() const {
    return std::vector<Book>(books.begin(), books.end());
}