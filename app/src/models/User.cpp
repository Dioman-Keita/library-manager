// User.cpp - Implémentation de la classe User
#include "User.h"

User::User(const std::string& id, const std::string& name, const std::string& email, const std::string& memberNumber)
    : id(id), name(name), email(email), memberNumber(memberNumber) {}

const std::string& User::getId() const { return id; }
std::string User::getName() const { return name; }
std::string User::getEmail() const { return email; }
std::string User::getMemberNumber() const { return memberNumber; }