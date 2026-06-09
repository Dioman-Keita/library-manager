// test_user_registration.cpp - Tests pour inscription utilisateurs
#include <iostream>
#include "../src/services/Library.h"
#include "../src/utils/IdGenerator.h"

int main() {
    Library lib;

    std::string uid1 = util::generateId();
    User u1(uid1, "Alice", "alice@example.com");
    bool ok1 = lib.registerUser(u1);
    std::cout << "Register first user: " << (ok1?"OK":"FAIL") << std::endl;

    std::string uid2 = util::generateId();
    User u2(uid2, "Alice2", "alice@example.com");
    bool ok2 = lib.registerUser(u2);
    std::cout << "Register duplicate email: " << (ok2?"OK":"FAIL (expected)") << std::endl;

    return 0;
}
