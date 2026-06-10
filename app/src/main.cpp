// main.cpp - Point d'entrée du programme
#include <iostream>
#include <limits>
#include "services/Library.h"
#include "services/BookManager.h"
using namespace std;

int main()
{
    cout << "==============================================" << endl;
    cout << "  Bienvenue dans le système de gestion de bibliothèque" << endl;
    cout << "==============================================" << endl;
    cout << "Que souhaitez-vous faire ?" << endl
         << endl;

    string title;
    string autheur;
    int years;
    int choix = -1;
    Library library;

    BookManager Stock;

    while (choix != 0)
    {
        cout << "Menu principal" << endl;
        cout << "------------------------------" << endl;
        cout << "1 - Voir tous les livres" << endl;
        cout << "2 - Ajouter un livre" << endl;
        cout << "3 - Retirer un livre" << endl;
        cout << "4 - Rechercher un livre" << endl;
        cout << "0 - Quitter" << endl;
        cout << "------------------------------" << endl;
        cout << "Votre choix : ";
        
        if (!(cin >> choix))
        {
            cout << "Saisie invalide. Veuillez entrer un nombre." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        switch (choix)
        {
        case 0:
            cout << "Au revoir !" << endl;
            break;

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
            cout << "Ajout d'un livre" << endl;
            cout << "----------------" << endl;
            cout << "Titre : ";
            getline(cin, title);
            cout << "Auteur : ";
            getline(cin, autheur);
            cout << "Année : ";
            while (!(cin >> years))
            {
                cout << "Année invalide. Veuillez entrer un nombre : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Book livre(title, autheur, years);
            Stock.addBook(livre);
            library.addBook(livre);
            break;
        }
        case 3:
        {
            cout << "Retirer un livre" << endl;
            cout << "----------------" << endl;
            cout << "Titre : ";
            getline(cin, title);
            if (Stock.removeBook(title))
            {
                library.removeBook(title);
                cout << "Livre retiré avec succès." << endl;
            }
            else
            {
                cout << "Erreur : Livre non trouvé." << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Rechercher un livre" << endl;
            cout << "--------------------" << endl;
            cout << "Titre : ";
            getline(cin, title);
            Book *livre = Stock.findBook(title);
            if (livre != nullptr)
            {
                cout << "Livre trouvé :" << endl;
                cout << "Titre  : " << livre->getTitle() << endl;
                cout << "Auteur : " << livre->getAuthor() << endl;
                cout << "Année  : " << livre->getYear() << endl;
            }
            else
            {
                cout << "Livre non trouvé." << endl;
            }
            break;
        }

        default:
            cout << "Choix inexistant" << endl;
            break;
        }
    }

    return 0;
}
