// application.h
#pragma once
#include "Borrow.h"  // Pour avoir accès à  Borrow
#include "BorrowRepository" // Pour avoir accès à IBorrowRepository 

// Cas d'usage : Emprunter un livre
class BorrowBookUseCase {
private:
    IBorrowRepository& repo;

public:
    explicit BorrowBookUseCase(IBorrowRepository& repo);
    void execute(const std::string& user_id, const std::string& book_id);
};

// Cas d'usage : Retourner un livre
class ReturnBookUseCase {
private:
    IBorrowRepository& repo;

public:
    explicit ReturnBookUseCase(IBorrowRepository& repo);
    void execute(const std::string& user_id, const std::string& book_id);
};