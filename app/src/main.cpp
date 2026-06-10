// main.cpp - Point d'entrée du programme
#include <iostream>
#include "services/Library.h"
#include "services/BookManager.h"
using namespace std;

int main()
{
    cout << "*******Bienvenue dans le système de gestion de bibliothèque********" << endl;
    cout << "*Que souheter vous faire*" << endl;
    string title;
    string autheur;
    int years;
    int choix;
    Library library;

    BookManager Stock;

    while (choix != 0)
    {
        cout << " 1- voir tous les livre " << endl;
        cout << " 2- ajouter un livre " << endl;
        cout << " 3- retirer un livre  " << endl;
        cout << " 4- rechercher un livre" << endl;
        cout << " 0- quitter " << endl;
        cin >> choix;
        switch (choix)
        {

        case 1:
        {

            cout << "--- Liste de tous les livres ---" << endl;

            std::vector<Book> livres = Stock.getAllBooks();

            if (livres.empty())
            {
                cout << "Aucun livre en stock." << endl;
            }
            else
            {

                for (const auto &livre : livres)
                {
                    cout << "- " << livre.getTitle() << " par " << livre.getAuthor()
                         << " (" << livre.getYear() << ")" << endl;
                }
            }
            break;
        }
        case 2:
        {

            cout << " Titre : ";
            cin >> title;
            cout << " Auteur : ";
            cin >> autheur;
            cout << " annee: ";
            cin >> years;
            Book livre(title, autheur, years);
            Stock.addBook(livre);
            library.addBook(livre);
            break;
        }
        case 3:
        {

            cout << "retirer un livre" << endl;
            cout << " Titre : ";
            cin >> title;
            Stock.removeBook(title);
            library.removeBook(title);
            break;
        }
        break;
        case 4:
        {

            cout << "rechercher un livre" << endl;
            cout << " Titre : ";
            cin >> title;
            Book *livre = Stock.findBook(title);
            if (livre != nullptr)
            {
                cout << "Titre : " << livre->getTitle() << endl;
                cout << "Auteur : " << livre->getAuthor() << endl;
                cout << "Annee : " << livre->getYear() << endl;
            }
            else
            {
                cout << "Livre non trouvé." << endl;
            }
            break;
        }

        default:
            cout << "Choix inexistant";
            break;
        }
    }

    return 0;
}
