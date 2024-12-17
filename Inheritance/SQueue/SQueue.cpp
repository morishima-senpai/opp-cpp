#include "SQueue.h"
#include <random>

SQueue::SQueue(size_t length) : current_index(0) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100);


    numbers.reserve(length);
    for (size_t i = 0; i < length; ++i) {
        numbers.push_back(dis(gen));
    }
}

int SQueue::Get() {
    if (current_index < numbers.size()) {
        return numbers[current_index++];
    }
    return -1;
}
