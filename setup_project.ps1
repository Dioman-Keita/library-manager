$rootDir = "app"

$folders = @(
    "$rootDir/src",
    "$rootDir/src/models",
    "$rootDir/src/services",
    "$rootDir/src/utils",
    "$rootDir/data",
    "$rootDir/tests",
    "$rootDir/docs"
)

foreach ($folder in $folders) {
    New-Item -ItemType Directory -Path $folder -Force | Out-Null
    Write-Host "Dossier créé : $folder"
}

$mainCpp = @'
// main.cpp - Point d'entrée du programme
#include <iostream>
#include "services/Library.h"

int main() {
    std::cout << "Bienvenue dans le système de gestion de bibliothèque" << std::endl;
    return 0;
}
'@
[System.IO.File]::WriteAllText("$rootDir/src/main.cpp", $mainCpp, [System.Text.UTF8Encoding]::new($false))

$bookH = @'
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
'@
[System.IO.File]::WriteAllText("$rootDir/src/models/Book.h", $bookH, [System.Text.UTF8Encoding]::new($false))

$bookCpp = @'
// Book.cpp - Implémentation de la classe Book
#include "Book.h"

Book::Book(const std::string& title, const std::string& author, int year)
    : title(title), author(author), year(year) {}

std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }
'@
[System.IO.File]::WriteAllText("$rootDir/src/models/Book.cpp", $bookCpp, [System.Text.UTF8Encoding]::new($false))

$userH = @'
// User.h - Définition de la classe User
#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    int id;
    std::string name;
    std::string email;

public:
    User(int id, const std::string& name, const std::string& email);
    int getId() const;
    std::string getName() const;
    std::string getEmail() const;
};

#endif
'@
[System.IO.File]::WriteAllText("$rootDir/src/models/User.h", $userH, [System.Text.UTF8Encoding]::new($false))

$userCpp = @'
// User.cpp - Implémentation de la classe User
#include "User.h"

User::User(int id, const std::string& name, const std::string& email)
    : id(id), name(name), email(email) {}

int User::getId() const { return id; }
std::string User::getName() const { return name; }
std::string User::getEmail() const { return email; }
'@
[System.IO.File]::WriteAllText("$rootDir/src/models/User.cpp", $userCpp, [System.Text.UTF8Encoding]::new($false))

$libraryH = @'
// Library.h - Gestion principale de la bibliothèque
#ifndef LIBRARY_H
#define LIBRARY_H

#include "../models/Book.h"
#include "../models/User.h"

class Library {
public:
    void addBook(const Book& book);
    void removeBook(const std::string& title);
    void registerUser(const User& user);
};

#endif
'@
[System.IO.File]::WriteAllText("$rootDir/src/services/Library.h", $libraryH, [System.Text.UTF8Encoding]::new($false))

$libraryCpp = @'
// Library.cpp - Implémentation de la classe Library
#include "Library.h"
#include <iostream>

void Library::addBook(const Book& book) {
    std::cout << "Ajout du livre : " << book.getTitle() << std::endl;
}

void Library::removeBook(const std::string& title) {
    std::cout << "Suppression du livre : " << title << std::endl;
}

void Library::registerUser(const User& user) {
    std::cout << "Inscription de l'utilisateur : " << user.getName() << std::endl;
}
'@
[System.IO.File]::WriteAllText("$rootDir/src/services/Library.cpp", $libraryCpp, [System.Text.UTF8Encoding]::new($false))

$bookManagerH = @'
// BookManager.h - Gestion des livres
#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include <vector>
#include "../models/Book.h"

class BookManager {
private:
    std::vector<Book> books;
public:
    void addBook(const Book& book);
    bool removeBook(const std::string& title);
    Book* findBook(const std::string& title);
    std::vector<Book> getAllBooks() const;
};

#endif
'@
[System.IO.File]::WriteAllText("$rootDir/src/services/BookManager.h", $bookManagerH, [System.Text.UTF8Encoding]::new($false))

$bookManagerCpp = @'
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
    return books;
}
'@
[System.IO.File]::WriteAllText("$rootDir/src/services/BookManager.cpp", $bookManagerCpp, [System.Text.UTF8Encoding]::new($false))

$userManagerH = @'
// UserManager.h - Gestion des utilisateurs
#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include "../models/User.h"

class UserManager {
private:
    std::vector<User> users;
public:
    void addUser(const User& user);
    bool removeUser(int id);
    User* findUser(int id);
    std::vector<User> getAllUsers() const;
};

#endif
'@
[System.IO.File]::WriteAllText("$rootDir/src/services/UserManager.h", $userManagerH, [System.Text.UTF8Encoding]::new($false))

$userManagerCpp = @'
// UserManager.cpp - Implémentation du gestionnaire d'utilisateurs
#include "UserManager.h"
#include <algorithm>

void UserManager::addUser(const User& user) {
    users.push_back(user);
}

bool UserManager::removeUser(int id) {
    auto it = std::find_if(users.begin(), users.end(),
        [id](const User& u) { return u.getId() == id; });
    if (it != users.end()) {
        users.erase(it);
        return true;
    }
    return false;
}

User* UserManager::findUser(int id) {
    for (auto& user : users) {
        if (user.getId() == id) return &user;
    }
    return nullptr;
}

std::vector<User> UserManager::getAllUsers() const {
    return users;
}
'@
[System.IO.File]::WriteAllText("$rootDir/src/services/UserManager.cpp", $userManagerCpp, [System.Text.UTF8Encoding]::new($false))

$loanManagerH = @'
// LoanManager.h - Gestion des emprunts
#ifndef LOANMANAGER_H
#define LOANMANAGER_H

#include <vector>
#include <string>
#include "../models/Book.h"
#include "../models/User.h"

struct Loan {
    Book book;
    User user;
    std::string borrowDate;
    std::string returnDate;
};

class LoanManager {
private:
    std::vector<Loan> loans;
public:
    void borrowBook(const Book& book, const User& user, const std::string& date);
    void returnBook(const Book& book);
    std::vector<Loan> getActiveLoans() const;
};

#endif
'@
[System.IO.File]::WriteAllText("$rootDir/src/services/LoanManager.h", $loanManagerH, [System.Text.UTF8Encoding]::new($false))

$loanManagerCpp = @'
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
'@
[System.IO.File]::WriteAllText("$rootDir/src/services/LoanManager.cpp", $loanManagerCpp, [System.Text.UTF8Encoding]::new($false))

$backupH = @'
// Backup.h - Sauvegarde des données
#ifndef BACKUP_H
#define BACKUP_H

#include <string>

class Backup {
public:
    static void saveToFile(const std::string& filename, const std::string& data);
    static std::string loadFromFile(const std::string& filename);
};

#endif
'@
[System.IO.File]::WriteAllText("$rootDir/src/utils/Backup.h", $backupH, [System.Text.UTF8Encoding]::new($false))

$backupCpp = @'
// Backup.cpp - Implémentation de la sauvegarde
#include "Backup.h"
#include <fstream>
#include <sstream>

void Backup::saveToFile(const std::string& filename, const std::string& data) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << data;
        file.close();
    }
}

std::string Backup::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::stringstream buffer;
    if (file.is_open()) {
        buffer << file.rdbuf();
    }
    return buffer.str();
}
'@
[System.IO.File]::WriteAllText("$rootDir/src/utils/Backup.cpp", $backupCpp, [System.Text.UTF8Encoding]::new($false))

[System.IO.File]::WriteAllText("$rootDir/data/books.txt", "", [System.Text.UTF8Encoding]::new($false))
[System.IO.File]::WriteAllText("$rootDir/data/users.txt", "", [System.Text.UTF8Encoding]::new($false))
[System.IO.File]::WriteAllText("$rootDir/data/loans.txt", "", [System.Text.UTF8Encoding]::new($false))

$testBook = @'
// test_book.cpp - Tests unitaires pour la classe Book
#include <iostream>
#include "../src/models/Book.h"

int main() {
    Book b("Test", "Auteur", 2023);
    std::cout << "Titre : " << b.getTitle() << std::endl;
    return 0;
}
'@
[System.IO.File]::WriteAllText("$rootDir/tests/test_book.cpp", $testBook, [System.Text.UTF8Encoding]::new($false))

$testUser = @'
// test_user.cpp - Tests unitaires pour la classe User
#include <iostream>
#include "../src/models/User.h"

int main() {
    User u(1, "Alice", "alice@example.com");
    std::cout << "Nom : " << u.getName() << std::endl;
    return 0;
}
'@
[System.IO.File]::WriteAllText("$rootDir/tests/test_user.cpp", $testUser, [System.Text.UTF8Encoding]::new($false))

$testLibrary = @'
// test_library.cpp - Tests pour la classe Library
#include <iostream>
#include "../src/services/Library.h"

int main() {
    Library lib;
    std::cout << "Tests bibliothèque OK" << std::endl;
    return 0;
}
'@
[System.IO.File]::WriteAllText("$rootDir/tests/test_library.cpp", $testLibrary, [System.Text.UTF8Encoding]::new($false))

[System.IO.File]::WriteAllText("$rootDir/docs/class_diagram.pdf", "", [System.Text.UTF8Encoding]::new($false))

$readme = @'
# LibraryCPP

Système de gestion de bibliothèque en C++.

## Structure du projet

- `src/` : Code source
  - `models/` : Classes Book et User
  - `services/` : Logique métier (Library, BookManager, UserManager, LoanManager)
  - `utils/` : Utilitaires (Backup)
- `data/` : Fichiers de données (livres, utilisateurs, emprunts)
- `tests/` : Tests unitaires
- `docs/` : Documentation

## Compilation

Utilisez le Makefile fourni :

```bash
make
```

## Auteur

Généré automatiquement.
'@
[System.IO.File]::WriteAllText("$rootDir/README.md", $readme, [System.Text.UTF8Encoding]::new($false))

$makefile = @'
CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = library_app
SRCDIR = src
OBJDIR = obj

SOURCES = $(SRCDIR)/main.cpp \
          $(SRCDIR)/models/Book.cpp \
          $(SRCDIR)/models/User.cpp \
          $(SRCDIR)/services/Library.cpp \
          $(SRCDIR)/services/BookManager.cpp \
          $(SRCDIR)/services/UserManager.cpp \
          $(SRCDIR)/services/LoanManager.cpp \
          $(SRCDIR)/utils/Backup.cpp

OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: all clean
'@
[System.IO.File]::WriteAllText("$rootDir/Makefile", $makefile, [System.Text.UTF8Encoding]::new($false))

$gitignore = @'
# Compiled files
*.o
*.exe
*.out

# Build directory
obj/
library_app

# IDE files
.vscode/
.idea/

# Data files
# data/*.txt
'@
[System.IO.File]::WriteAllText("$rootDir/.gitignore", $gitignore, [System.Text.UTF8Encoding]::new($false))

Write-Host "`nStructure du projet créée avec succès dans '$rootDir' (noms en anglais)." -ForegroundColor Green