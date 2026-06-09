// test_loan.cpp - Tests pour emprunt/retour
#include <iostream>
#include "../src/services/Library.h"
#include "../src/utils/IdGenerator.h"

int main() {
    Library lib;
    lib.loadData("data");

    // create user
    std::string uid = util::generateId();
    User u(uid, "Bob", "bob@example.com");
    lib.registerUser(u);

    // create book
    std::string bid = util::generateId();
    std::string isbn = std::string("ISBN-") + bid;
    Book b(bid, "C++ Primer", "Lippman", 2012, isbn);
    if (!lib.addBook(b)) std::cout << "Failed to add book (duplicate ISBN)\n";

    // borrow
    bool ok = lib.borrowBookById(bid, uid, "2026-06-08");
    std::cout << "Borrow: " << (ok?"OK":"FAIL") << std::endl;

    // check availability
    std::cout << "Available after borrow: " << (lib.isBookAvailable(bid)?"YES":"NO") << std::endl;

    // return
    lib.returnBookById(bid);
    std::cout << "Available after return: " << (lib.isBookAvailable(bid)?"YES":"NO") << std::endl;

    lib.saveData("data");
    return 0;
}
