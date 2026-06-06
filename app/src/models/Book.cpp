// Book.cpp - Implémentation de la classe Book
#include "Book.h"

Book::Book(const std::string& title, const std::string& author, int year)
    : title(title), author(author), year(year) {}

std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }