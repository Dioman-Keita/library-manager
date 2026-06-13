// User.h - Définition de la classe User
#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Book.h"

class User {
private:
    std::string id;
    std::string name;
    std::string email;
    std::string memberNumber;

public:
    User(const std::string& id, const std::string& name, const std::string& email, const std::string& memberNumber);
    const std::string& getId() const;
    std::string getName() const;
    std::string getEmail() const;
    std::string getMemberNumber() const;
};

#endif