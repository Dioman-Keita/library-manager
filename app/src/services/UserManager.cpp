// UserManager.cpp - Implémentation du gestionnaire d'utilisateurs
#include "UserManager.h"
#include <algorithm>

void UserManager::addUser(const User& user) {
    users.push_back(user);
}

bool UserManager::removeUser(int id) {
    auto it = std::find_if(users.begin(), users.end(),
        [id](const User& u) { return u.getId() == id; });
    if (it != users.end()) {
        users.erase(it);
        return true;
    }
    return false;
}

User* UserManager::findUser(int id) {
    for (auto& user : users) {
        if (user.getId() == id) return &user;
    }
    return nullptr;
}

std::vector<User> UserManager::getAllUsers() const {
    return std::vector<User>(users.begin(), users.end());
}