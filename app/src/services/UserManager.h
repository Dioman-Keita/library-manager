// UserManager.h - Gestion des utilisateurs 
#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include "../models/User.h"       // Vérifie que Assitan a bien nommé le fichier User.h
#include "Bibliotheque.h"         // Pour accéder à la liste centrale

class UserManager {
public:
    // Ajouter un utilisateur (en demandant les infos en Français)
    void addUser(Bibliotheque& biblio);

    // Supprimer un utilisateur par son ID
    bool removeUser(Bibliotheque& biblio, int id);

    // Rechercher un utilisateur par ID
    User* findUser(Bibliotheque& biblio, int id);

    // Afficher tous les utilisateurs
    void displayAllUsers(const Bibliotheque& biblio) const;
};


#endif