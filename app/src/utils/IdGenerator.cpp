// IdGenerator.cpp - Simple UUID-like generator using random_device
#include "IdGenerator.h"
#include <random>
#include <sstream>
#include <iomanip>

namespace util {
    static std::string to_hex(uint64_t v) {
        std::ostringstream ss;
        ss << std::hex << std::setw(16) << std::setfill('0') << v;
        return ss.str();
    }

    std::string generateId() {
        std::random_device rd;
        std::mt19937_64 gen(rd());
        std::uniform_int_distribution<uint64_t> dist;

        // Produce 128 bits and format as hex groups similar to UUID
        uint64_t a = dist(gen);
        uint64_t b = dist(gen);

        std::string ha = to_hex(a);
        std::string hb = to_hex(b);

        // format: 8-4-4-4-12 like UUID but using hex of the two 64-bit values
        std::string id = ha.substr(0,8) + "-" + ha.substr(8,4) + "-" + ha.substr(12,4)
            + "-" + hb.substr(0,4) + "-" + hb.substr(4,12);
        return id;
    }
}
