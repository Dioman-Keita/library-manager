#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string titre;
    std::string auteur;
    std::string isbn;
    bool disponible;

public:
    // Constructeurs
    Book();
    Book(std::string titre, std::string auteur, std::string isbn);

    // Getters
    std::string getTitre() const;
    std::string getAuteur() const;
    std::string getIsbn() const;
    bool estDisponible() const;

    // Setters
    void setTitre(const std::string& titre);
    void setAuteur(const std::string& auteur);
    void setIsbn(const std::string& isbn);
    void setDisponible(bool disponible);

    // Méthodes
    void afficher() const;
};

#endif