// Library.cpp - Implémentation de la classe Library
#include "Library.h"
#include <iostream>

void Library::addBook(const Book &book)
{
    std::cout << "Ajout du livre : " << book.getTitle() << std::endl;
}

void Library::removeBook(const std::string &title)
{
    std::cout << "Suppression du livre : " << title << std::endl;
}

void Library::registerUser(const User &user)
{
    std::cout << "Inscription de l'utilisateur : " << user.getName() << std::endl;
}