#include "UserManager.h"
#include <iostream>

using namespace std;

void UserManager::addUser(Bibliotheque& biblio) {
    string name, email;
    int id;

    cout << "\n--- Enregistrement d'un nouvel utilisateur ---" << endl;
    cout << "Nom : ";
    getline(cin >> ws, name);
    cout << "Email : ";
    cin >> email;
    cout << "Numéro de membre : ";
    cin >> id;

    // Création de l'objet User (assure-toi que Assitan a ce constructeur)
    User newUser(name, email, id);
    
    // On l'ajoute au vecteur central de la classe Bibliotheque de Dioman
    biblio.utilisateurs.push_back(newUser);

    cout << "Utilisateur enregistré avec succès !" << endl;
}

User* UserManager::findUser(Bibliotheque& biblio, int id) {
    for (size_t i = 0; i < biblio.utilisateurs.size(); ++i) {
        if (biblio.utilisateurs[i].getId() == id) { // Vérifie le nom du getter avec Assitan
            return &biblio.utilisateurs[i];
        }
    }
    return nullptr;
}

bool UserManager::removeUser(Bibliotheque& biblio, int id) {
    for (auto it = biblio.utilisateurs.begin(); it != biblio.utilisateurs.end(); ++it) {
        if (it->getId() == id) {
            biblio.utilisateurs.erase(it);
            cout << "Utilisateur supprimé avec succès." << endl;
            return true;
        }
    }
    cout << "Erreur : Utilisateur introuvable." << endl;
    return false;
}

void UserManager::displayAllUsers(const Bibliotheque& biblio) const {
    cout << "\n--- Liste des membres enregistrés ---" << endl;
    if (biblio.utilisateurs.empty()) {
        cout << "Aucun utilisateur dans la base de données." << endl;
        return;
    }
    for (const auto& user : biblio.utilisateurs) {
        user.display(); // Assitan doit créer cette méthode display() ou afficher()
    }
}