#include "SKbrd.h"
#include <iostream>

int SKbrd::Get() {
    int num;
    std::cout << "Enter a number (-1 to end): ";
    if (std::cin >> num) {
        return num;
    }
    return -1;
}