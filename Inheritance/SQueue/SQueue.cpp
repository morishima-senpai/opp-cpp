#include "SQueue.h"
#include <random>
#include <cstdlib>
#include <ctime>


SQueue::SQueue(size_t length) : current_index(0){
    static bool seeded = false;

    /*  эй, бог кодирования, если ты существуешь, пожалуйста, 
        сделай так, чтобы этот конструктор работал... 
        пожалуйста!!
    */
    if (!seeded) {
        srand(static_cast<unsigned int>(time(nullptr)));
        seeded = true;
    }
    numbers.reserve(length);
    while(length--) numbers.push_back(rand() % 101);
}

int SQueue::Get() {
    if (current_index < numbers.size()) {
        return numbers[current_index++];
    }
    return -1;
}