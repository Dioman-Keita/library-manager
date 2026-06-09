// Book.h - Définition de la classe Book
#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string id;
    std::string title;
    std::string author;
    int year;
    std::string isbn;

public:
    Book(const std::string& id, const std::string& title, const std::string& author, int year, const std::string& isbn);
    const std::string& getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    std::string getIsbn() const;
};

#endif