# LibraryCPP

Système de gestion de bibliothèque en C++.

## Structure du projet

- `app/`
  - `src/` : Code source
    - `models/` : Classes Book et User
    - `services/` : Logique métier (Library, BookManager, UserManager, LoanManager)
    - `utils/` : Utilitaires (Backup)
  - `Makefile` : Script de compilation
  - `CMakeLists.txt` : Build portable multi-plateforme
  - `README.md` : Documentation du module application
- `data/` : Fichiers de données (livres, utilisateurs, emprunts)
- `tests/` : Tests unitaires
- `docs/` : Documentation

## Compilation

Depuis la racine du dépôt :

```bash
cd app && make
```

Ou en restant à la racine :

```bash
make -C app
```

Build portable avec CMake :

```bash
cd app
cmake -S . -B build
cmake --build build
```

Le dossier `data/` est copié à côté de l'exécutable généré pour que le programme trouve ses fichiers au lancement.

## Auteur

Généré automatiquement.
