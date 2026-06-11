// application.cpp
#include "BorrowManager.h"
#include <stdexcept>
#include <chrono>   // Pour std::chrono::system_clock
#include <random>   // Pour std::mt19937 et std::random_device
#include <string>   // Pour std::to_string

// ============================================================================
// Implémentation de BorrowBookUseCase
// ============================================================================

BorrowBookUseCase::BorrowBookUseCase(IBorrowRepository& repo) : repo(repo) {}

void BorrowBookUseCase::execute(const std::string& user_id, const std::string& book_id) {
    // 1. Vérification de la disponibilité via l'interface du Repository
    if (this->repo.check_availability(book_id) == BookStatus::Borrowed) {
        throw std::runtime_error("Action Impossible : Ce livre est deja emprunte.");
    }

    // 2. Règle Application : Génération d'un ID d'emprunt unique pour la session
   auto now = std::chrono::system_clock::now().time_since_epoch().count();
   std::mt19937 rng(std::random_device{}());
   std::string unique_borrow_id = std::to_string(now) + "_" + std::to_string(rng());
    
    // Création de l'entité (durée de 14 jours)
    Borrow new_borrow(unique_borrow_id, user_id, book_id, 14);

    // 3. Demande de persistance à l'infrastructure
    this->repo.save_borrow(new_borrow);
}

// ============================================================================
// Implémentation de ReturnBookUseCase
// ============================================================================

ReturnBookUseCase::ReturnBookUseCase(IBorrowRepository& repo) : repo(repo) {}

void ReturnBookUseCase::execute(const std::string& user_id, const std::string& book_id) {
    // 1. Récupération de l'emprunt actif via l'interface du Repository
    auto borrow_opt = this->repo.find_active_borrow(user_id, book_id);
    if (!borrow_opt.has_value()) {
        throw std::runtime_error("Action Impossible : Aucun emprunt en cours trouve pour ce couple utilisateur/livre.");
    }

    // 2. Récupération de l'entité et mutation de son état (Logique Domaine Pure)
    Borrow& borrow = borrow_opt.value();
    borrow.return_book();

    // 3. Envoi de la mise à jour à l'infrastructure
    this->repo.update_borrow(borrow);
}