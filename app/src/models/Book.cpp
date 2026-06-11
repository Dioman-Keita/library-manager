#include "Book.h"
#include <iostream>

using namespace std;

// Constructeur par défaut
Book::Book() {
    titre = "";
    auteur = "";
    isbn = "";
    disponible = true;
}

// Constructeur avec paramètres
Book::Book(string titre, string auteur, string isbn) {
    this->titre = titre;
    this->auteur = auteur;
    this->isbn = isbn;
    disponible = true;
}

// Getters
string Book::getTitre() const {
    return titre;
}

string Book::getAuteur() const {
    return auteur;
}

string Book::getIsbn() const {
    return isbn;
}

bool Book::estDisponible() const {
    return disponible;
}

// Setters
void Book::setTitre(const string& titre) {
    this->titre = titre;
}

void Book::setAuteur(const string& auteur) {
    this->auteur = auteur;
}

void Book::setIsbn(const string& isbn) {
    this->isbn = isbn;
}

void Book::setDisponible(bool disponible) {
    this->disponible = disponible;
}

// Affichage
void Book::afficher() const {
    cout << "Titre : " << titre << endl;
    cout << "Auteur : " << auteur << endl;
    cout << "ISBN : " << isbn << endl;
    cout << "Disponibilite : "
         << (disponible ? "Disponible" : "Emprunte")
         << endl;
}