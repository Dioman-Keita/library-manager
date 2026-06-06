// Book.h - Définition de la classe Book
#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int year;

public:
    Book(const std::string& title, const std::string& author, int year);
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
};

#endif