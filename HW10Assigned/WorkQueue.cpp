#include <iostream>
#include <string>
#include <stdlib.h>
#include <mutex>
#include <memory>
#include "WorkQueue.h"

void WorkQueue::put(shared_ptr<Command> command) {
    static std::mutex lck;
    std::lock_guard<std::mutex> lock(lck);
    queue.push_back(command);
}

shared_ptr<Command> WorkQueue::get( ) {
    static mutex lck;
    std::lock_guard<std::mutex> lock(lck);
    if (queue.empty()) {
        return nullptr;
    }
    std::shared_ptr<Command> &temp = queue.back( );
    queue.pop_back( );
    return temp;
}