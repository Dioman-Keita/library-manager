#include "Borrow.h"
#include <stdexcept>
#include <string>
#include <chrono>
#include <optional>
#include <vector>

// Implémentation du Constructeur
Borrow::Borrow(std::string id, std::string user_id, std::string book_id, int duration_days)
    : id(id), user_id(user_id), book_id(book_id), returned_at(std::nullopt) {
    
    this->borrowed_at = std::chrono::system_clock::now();
    this->due_date = this->borrowed_at + std::chrono::hours(24 * duration_days);
}

// Règle métier : Retourner le livre
void Borrow::return_book() {
    if (this->returned_at.has_value()) {
        throw std::runtime_error("Regle metier : Le livre a deja ete retourne.");
    }
    this->returned_at = std::chrono::system_clock::now();
}

// Règle métier : Vérifier si l'emprunt a dépassé la date limite
bool Borrow::is_overdue() const {
    if (this->returned_at.has_value()) return false;
    return std::chrono::system_clock::now() > this->due_date;
}

// Getters
std::string Borrow::get_id() const { 
    return this->id; 
}

std::string Borrow::get_user_id() const { 
    return this->user_id; 
}

std::string Borrow::get_book_id() const { 
    return this->book_id; 
}

bool Borrow::is_returned() const { 
    return this->returned_at.has_value(); 
}