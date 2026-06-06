// test_user.cpp - Tests unitaires pour la classe User
#include <iostream>
#include "../src/models/User.h"

int main() {
    User u(1, "Alice", "alice@example.com");
    std::cout << "Nom : " << u.getName() << std::endl;
    return 0;
}