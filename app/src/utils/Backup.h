// Backup.h - Sauvegarde des données
#ifndef BACKUP_H
#define BACKUP_H

#include <string>

class Backup {
public:
    static void saveToFile(const std::string& filename, const std::string& data);
    static std::string loadFromFile(const std::string& filename);
};

#endif