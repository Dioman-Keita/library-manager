// test_user.cpp - Tests unitaires pour la classe User
#include <iostream>
#include "../src/models/User.h"
#include "../src/utils/IdGenerator.h"

int main() {
    std::string id = util::generateId();
    User u(id, "Alice", "alice@example.com");
    std::cout << "ID : " << u.getId() << " Nom : " << u.getName() << std::endl;
    return 0;
}