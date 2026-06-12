// UserManager.cpp - Implémentation du gestionnaire d'utilisateurs
#include "UserManager.h"
#include <algorithm>
#include <fstream>
#include <sstream>

bool UserManager::addUser(const User& user) {
    // prevent duplicate email or member number
    if (findUserByEmail(user.getEmail())) return false;
    for (const auto& existing : users) {
        if (!user.getMemberNumber().empty() && existing.getMemberNumber() == user.getMemberNumber()) {
            return false;
        }
    }
    users.push_back(user);
    return true;
}

bool UserManager::removeUserById(const std::string& id) {
    auto it = std::find_if(users.begin(), users.end(),
        [&id](const User& u) { return u.getId() == id; });
    if (it != users.end()) {
        users.erase(it);
        return true;
    }
    return false;
}

User* UserManager::findUserById(const std::string& id) {
    for (auto& user : users) {
        if (user.getId() == id) return &user;
    }
    return nullptr;
}

User* UserManager::findUserByEmail(const std::string& email) {
    for (auto& user : users) {
        if (user.getEmail() == email) return &user;
    }
    return nullptr;
}

bool UserManager::saveToFile(const std::string& path) const {
    std::ofstream ofs(path);
    if (!ofs) return false;
    for (auto& u : users) {
        ofs << u.getId() << "|" << u.getName() << "|" << u.getEmail() << "|" << u.getMemberNumber() << "\n";
    }
    return true;
}

bool UserManager::loadFromFile(const std::string& path) {
    std::ifstream ifs(path);
    if (!ifs) return false;
    users.clear();
    std::string line;
    while (std::getline(ifs, line)) {
        if (line.empty()) continue;
        std::istringstream ss(line);
        std::string id, name, email, memberNumber;
        if (!std::getline(ss, id, '|')) continue;
        if (!std::getline(ss, name, '|')) continue;
        if (!std::getline(ss, email, '|')) continue;
        if (!std::getline(ss, memberNumber, '|')) memberNumber = "";
        users.emplace_back(id, name, email, memberNumber);
    }
    return true;
}

std::vector<User> UserManager::getAllUsers() const {
    return std::vector<User>(users.begin(), users.end());
}