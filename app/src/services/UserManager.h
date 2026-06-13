// UserManager.h - Gestion des utilisateurs 
#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include <list>
#include <string>
#include "../models/User.h"

class UserManager {
private:
    std::list<User> users;
public:
    bool addUser(const User& user);
    bool removeUserById(const std::string& id);
    User* findUserById(const std::string& id);
    User* findUserByEmail(const std::string& email);
    std::vector<User> getAllUsers() const;
    bool saveToFile(const std::string& path) const;
    bool loadFromFile(const std::string& path);
};


#endif