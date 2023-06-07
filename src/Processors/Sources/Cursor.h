#pragma once

#include <cstdint>

namespace DB {

namespace ErrorCodes
{
    extern const int BAD_ARGUMENTS;
}

struct CursorStruct {
    std::uint64_t value;
    std::string name;
    std::size_t ttl;
};

class Cursor
{
public:
    Cursor(std::uint64_t value_, std::string name_){
        cursor.value = value_;
        cursor.name = name_;
        cursor.ttl = 86400;
    }

    Cursor() {
        cursor.value = 0;
        cursor.name = "";
        cursor.ttl = 86400;
    }

    std::uint64_t GetValue() const {
        return cursor.value;
    }

    std::string GetName() const {
        return cursor.name;
    }

    std::uint64_t GetNext(std::uint64_t offset) const {
        return cursor.value + offset;
    }

    void SaveNewCursor(std::uint64_t new_cursor) {
        cursor.value = new_cursor;
    }

private:
    CursorStruct cursor;
};
}
