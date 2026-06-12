#include <iostream>
#include <string>
#include <limits>
#include "services/Library.h"
#include "utils/IdGenerator.h"

int main() {
    Library lib;
    User* currentUser = nullptr;

    auto checkBookAvailability = [&lib]() {
        std::string bookId;
        std::cout << "ID du livre: ";
        std::getline(std::cin, bookId);
        auto* book = lib.books().findBookById(bookId);
        if (!book) {
            std::cout << "Livre introuvable.\n";
            return;
        }
        if (lib.isBookAvailable(bookId)) {
            std::cout << "Le livre est disponible pour emprunt.\n";
        } else {
            std::cout << "Le livre n'est pas disponible pour emprunt.\n";
        }
    };

    // Load persisted data if available
    lib.loadData("data");

    std::cout << "Bienvenue dans le système de gestion de bibliothèque" << std::endl;

    while (true) {
        std::cout << "\n--- Menu ---\n";
        bool isAdmin = (currentUser && currentUser->getEmail() == "admin@admin.com");
        if (!currentUser) {
            std::cout << "1) Se connecter\n";
            std::cout << "2) S'inscrire\n";
            std::cout << "0) Quitter\n";
            std::cout << "Choix: ";
            int choice;
            if (!(std::cin >> choice)) break;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (choice == 0) break;
            if (choice == 1) {
                std::string email;
                std::cout << "Email: ";
                std::getline(std::cin, email);
                User* u = lib.findUserByEmail(email);
                if (u) {
                    currentUser = u;
                    std::cout << "Connecté.\n";
                } else {
                    std::cout << "Utilisateur non trouvé. Inscrivez-vous d'abord.\n";
                }
            } else if (choice == 2) {
                std::string name, email, memberNumber;
                std::cout << "Nom: "; std::getline(std::cin, name);
                std::cout << "Email: "; std::getline(std::cin, email);
                std::cout << "Numéro de membre: "; std::getline(std::cin, memberNumber);
                if (memberNumber.empty()) {
                    std::cout << "Erreur: le numéro de membre est obligatoire. Inscription annulée.\n";
                    continue;
                }
                std::string uid = util::generateId();
                User u(uid, name, email, memberNumber);
                if (lib.registerUser(u)) {
                    std::cout << "Utilisateur créé avec ID: " << uid << "\n";
                } else {
                    std::cout << "Erreur: email ou numéro de membre déjà utilisé. Inscription annulée.\n";
                }
            }
            continue;
        }

        // Logged in menu
        std::cout << "Connecté: " << currentUser->getName() << " <" << currentUser->getEmail() << ">\n";
        if (isAdmin) {
            std::cout << "1) Ajouter un livre\n";
            std::cout << "2) Supprimer un livre par ID\n";
            std::cout << "3) Lister les livres\n";
            std::cout << "4) Lister les utilisateurs\n";
            std::cout << "5) Rechercher un livre\n";
            std::cout << "6) Lister les livres empruntés\n";
            std::cout << "7) Vérifier la disponibilité d'un livre\n";
            std::cout << "8) Déconnecter\n";
        } else {
            std::cout << "1) Emprunter un livre (par ID)\n";
            std::cout << "2) Retourner un livre (par ID)\n";
            std::cout << "3) Lister les livres\n";
            std::cout << "4) Mes emprunts\n";
            std::cout << "5) Rechercher un livre\n";
            std::cout << "6) Vérifier la disponibilité d'un livre\n";
            std::cout << "7) Déconnecter\n";
        }
        std::cout << "0) Quitter\n";
        std::cout << "Choix: ";
        int choice;
        if (!(std::cin >> choice)) break;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice == 0) break;

        if (isAdmin) {
            if (choice == 1) {
                std::string title, author, isbn;
                int year;
                std::cout << "Titre: "; std::getline(std::cin, title);
                std::cout << "Auteur: "; std::getline(std::cin, author);
                std::cout << "ISBN: "; std::getline(std::cin, isbn);
                std::cout << "Année: "; std::cin >> year; std::cin.ignore();
                std::string bid = util::generateId();
                Book b(bid, title, author, year, isbn);
                if (lib.addBook(b)) {
                    std::cout << "Livre ajouté avec ID: " << bid << "\n";
                } else {
                    std::cout << "Erreur: ISBN déjà existant, ajout annulé.\n";
                }
            } else if (choice == 2) {
                std::string id;
                std::cout << "ID du livre à supprimer: "; std::getline(std::cin, id);
                if (lib.removeBookById(id)) std::cout << "Livre supprimé.\n";
                else std::cout << "Livre introuvable.\n";
            } else if (choice == 3) {
                auto books = lib.listBooks();
                std::cout << "Livres:\n";
                for (auto& bk : books) {
                    std::cout << "- [" << bk.getId() << "] " << bk.getTitle() << " par " << bk.getAuthor() << " (" << bk.getYear() << ") ISBN:" << bk.getIsbn() << "\n";
                }
            } else if (choice == 4) {
                auto users = lib.listUsers();
                std::cout << "Utilisateurs:\n";
                for (auto& us : users) {
                    std::cout << "- [" << us.getId() << "] " << us.getName() << " <" << us.getEmail() << ">";
                    if (!us.getMemberNumber().empty()) {
                        std::cout << " Numéro de membre:" << us.getMemberNumber();
                    }
                    std::cout << "\n";
                }
            } else if (choice == 5) {
                std::cout << "Recherche par (t)itre, (a)uteur, (i)sbn? ";
                char c; std::cin >> c; std::cin.ignore();
                if (c == 't') {
                    std::string q; std::cout << "Titre: "; std::getline(std::cin, q);
                    auto res = lib.findBooksByTitle(q);
                    for (auto& bk : res) std::cout << "- ["<<bk.getId()<<"] "<<bk.getTitle()<<" ISBN:"<<bk.getIsbn()<<"\n";
                } else if (c == 'a') {
                    std::string q; std::cout << "Auteur: "; std::getline(std::cin, q);
                    auto res = lib.findBooksByAuthor(q);
                    for (auto& bk : res) std::cout << "- ["<<bk.getId()<<"] "<<bk.getTitle()<<" ISBN:"<<bk.getIsbn()<<"\n";
                } else if (c == 'i') {
                    std::string q; std::cout << "ISBN: "; std::getline(std::cin, q);
                    auto res = lib.findBooksByIsbn(q);
                    for (auto& bk : res) std::cout << "- ["<<bk.getId()<<"] "<<bk.getTitle()<<" ISBN:"<<bk.getIsbn()<<"\n";
                }
            } else if (choice == 6) {
                auto loans = lib.listActiveLoans();
                std::cout << "Livres empruntés:\n";
                if (loans.empty()) {
                    std::cout << "Aucun livre emprunté pour le moment\n";
                } else {
                    for (auto& ln : loans) {
                        auto book = lib.books().findBookById(ln.bookId);
                        auto user = lib.users().findUserById(ln.userId);
                        if (book && user) {
                            std::cout << "- [" << book->getId() << "] " << book->getTitle()
                                      << " par " << book->getAuthor()
                                      << " emprunté par " << user->getName()
                                      << " <" << user->getEmail() << ">"
                                      << " le " << ln.borrowDate << "\n";
                        }
                    }
                }
            } else if (choice == 7) {
                checkBookAvailability();
            } else if (choice == 8) {
                currentUser = nullptr; std::cout << "Déconnecté.\n";
            } else {
                std::cout << "Option inconnue.\n";
            }
        } else {
            if (choice == 1) {
                std::string bookId;
                std::cout << "ID du livre à emprunter: "; std::getline(std::cin, bookId);
                if (lib.borrowBookById(bookId, currentUser->getId(), "today")) std::cout << "Emprunt effectué.\n";
                else {
                    if (!lib.books().findBookById(bookId)) std::cout << "Livre introuvable.\n";
                    else if (!lib.isBookAvailable(bookId)) std::cout << "livre deja emprunté\n";
                    else std::cout << "Impossible d'emprunter.\n";
                }
            } else if (choice == 2) {
                std::string bookId;
                std::cout << "ID du livre à retourner: "; std::getline(std::cin, bookId);
                if (lib.returnBookById(bookId)) std::cout << "Retour enregistré.\n";
                else std::cout << "Échec du retour.\n";
            } else if (choice == 3) {
                auto books = lib.listBooks();
                std::cout << "Livres:\n";
                for (auto& bk : books) {
                    std::cout << "- [" << bk.getId() << "] " << bk.getTitle() << " par " << bk.getAuthor() << " (" << bk.getYear() << ") ISBN:" << bk.getIsbn();
                    std::cout << (lib.isBookAvailable(bk.getId())?" [disponible]":" [emprunté]") << "\n";
                }
            } else if (choice == 4) {
                auto loans = lib.listLoansByUserId(currentUser->getId());
                std::cout << "Mes emprunts:\n";
                if (loans.empty()) {
                    std::cout << "Aucun emprunt trouve pour le moment\n";
                } else {
                    for (auto& ln : loans) {
                        auto b = lib.books().findBookById(ln.bookId);
                        if (b) {
                            std::cout << "- ["<<ln.bookId<<"] "<<b->getTitle();
                            std::cout << " (emprunté le: " << ln.borrowDate << ")";
                            if (!ln.returnDate.empty()) std::cout << " (retourné: "<<ln.returnDate<<")";
                            std::cout << "\n";
                        }
                    }
                }
            } else if (choice == 5) {
                std::cout << "Recherche par (t)itre, (a)uteur, (i)sbn? ";
                char c; std::cin >> c; std::cin.ignore();
                if (c == 't') {
                    std::string q; std::cout << "Titre: "; std::getline(std::cin, q);
                    auto res = lib.findBooksByTitle(q);
                    for (auto& bk : res) std::cout << "- ["<<bk.getId()<<"] "<<bk.getTitle()<<" ISBN:"<<bk.getIsbn()<<"\n";
                } else if (c == 'a') {
                    std::string q; std::cout << "Auteur: "; std::getline(std::cin, q);
                    auto res = lib.findBooksByAuthor(q);
                    for (auto& bk : res) std::cout << "- ["<<bk.getId()<<"] "<<bk.getTitle()<<" ISBN:"<<bk.getIsbn()<<"\n";
                } else if (c == 'i') {
                    std::string q; std::cout << "ISBN: "; std::getline(std::cin, q);
                    auto res = lib.findBooksByIsbn(q);
                    for (auto& bk : res) std::cout << "- ["<<bk.getId()<<"] "<<bk.getTitle()<<" ISBN:"<<bk.getIsbn()<<"\n";
                }
            } else if (choice == 6) {
                checkBookAvailability();
            } else if (choice == 7) {
                currentUser = nullptr; std::cout << "Déconnecté.\n";
            } else {
                std::cout << "Option inconnue.\n";
            }
        }
    }

    // Save data before exit
    lib.saveData("data");
    std::cout << "Au revoir." << std::endl;
    return 0;
}
