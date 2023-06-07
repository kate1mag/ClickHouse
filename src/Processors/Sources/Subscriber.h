#pragma once

#include <mutex>
#include <condition_variable>
#include <queue>
#include <Processors/Sources/Cursor.h>

namespace DB
{

namespace ErrorCodes
{
    extern const int BAD_ARGUMENTS;
}

struct Subscriber
{
    Subscriber(BlocksPtr blocks_): blocks(blocks_) {
        // cursor = Cursor(value, name);
    }
    std::mutex mutex;
    std::condition_variable condition;
    BlocksPtr blocks;
    Cursor cursor;

    void addCursor(std::uint64_t value, std::string name) {
        cursor = Cursor(value, name);
    }
};

}
