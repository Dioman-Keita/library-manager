// User.h - Définition de la classe User
#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string id;
    std::string name;
    std::string email;

public:
    User(const std::string& id, const std::string& name, const std::string& email);
    const std::string& getId() const;
    std::string getName() const;
    std::string getEmail() const;
};

#endif