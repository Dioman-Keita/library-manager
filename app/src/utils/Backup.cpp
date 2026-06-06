// Backup.cpp - Implémentation de la sauvegarde
#include "Backup.h"
#include <fstream>
#include <sstream>

void Backup::saveToFile(const std::string& filename, const std::string& data) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << data;
        file.close();
    }
}

std::string Backup::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::stringstream buffer;
    if (file.is_open()) {
        buffer << file.rdbuf();
    }
    return buffer.str();
}