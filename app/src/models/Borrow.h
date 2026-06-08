#ifndef BORROW_H
#define BORROW_H

#pragma once
#include <string>
#include <chrono>
#include <optional>
#include <vector>

enum class BookStatus { Available, Borrowed };

class Borrow {
private:
    std::string id;
    std::string user_id;
    std::string book_id;
    std::chrono::system_clock::time_point borrowed_at;
    std::chrono::system_clock::time_point due_date;
    std::optional<std::chrono::system_clock::time_point> returned_at;

public:
    // Uniquement les prototypes ici
    Borrow(std::string id, std::string user_id, std::string book_id, int duration_days);
    
    void return_book();
    bool is_overdue() const;
    
    std::string get_id() const;
    std::string get_user_id() const;
    std::string get_book_id() const;
    bool is_returned() const;
};

#endif