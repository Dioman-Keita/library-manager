// Book.cpp - Implémentation de la classe Book
#include "Book.h"

Book::Book(const std::string& id, const std::string& title, const std::string& author, int year, const std::string& isbn)
    : id(id), title(title), author(author), year(year), isbn(isbn) {}

const std::string& Book::getId() const { return id; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }
std::string Book::getIsbn() const { return isbn; }