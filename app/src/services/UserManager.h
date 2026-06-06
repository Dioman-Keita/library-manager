// UserManager.h - Gestion des utilisateurs
#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include "../models/User.h"

class UserManager {
private:
    std::vector<User> users;
public:
    void addUser(const User& user);
    bool removeUser(int id);
    User* findUser(int id);
    std::vector<User> getAllUsers() const;
};

#endif