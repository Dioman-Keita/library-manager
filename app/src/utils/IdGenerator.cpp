// IdGenerator.cpp - Générateur d'ID numérique séquentiel
#include "IdGenerator.h"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <string>

namespace util {
    namespace {
        unsigned long long nextId = 0;
        bool seeded = false;

        bool isNumericId(const std::string& value) {
            return !value.empty() && std::all_of(value.begin(), value.end(), [](unsigned char ch) {
                return std::isdigit(ch) != 0;
            });
        }

        void seedFromFile(const std::string& path) {
            std::ifstream ifs(path);
            if (!ifs) return;

            std::string line;
            while (std::getline(ifs, line)) {
                auto separator = line.find('|');
                if (separator == std::string::npos) continue;

                std::string id = line.substr(0, separator);
                if (isNumericId(id)) {
                    unsigned long long value = std::stoull(id);
                    if (value > nextId) nextId = value;
                }
            }
        }

        void seedCounter() {
            if (seeded) return;
            seeded = true;
            seedFromFile("data/books.txt");
            seedFromFile("data/users.txt");
            seedFromFile("data/loans.txt");
        }
    }

    std::string generateId() {
        seedCounter();
        ++nextId;
        return std::to_string(nextId);
    }
}
