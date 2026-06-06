// User.h - Définition de la classe User
#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    int id;
    std::string name;
    std::string email;

public:
    User(int id, const std::string& name, const std::string& email);
    int getId() const;
    std::string getName() const;
    std::string getEmail() const;
};

#endif