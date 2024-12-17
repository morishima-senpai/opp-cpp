#include "Diap.h"

void Diap::Calc(SBase* source) {
    min_value = std::numeric_limits<int>::max();
    max_value = std::numeric_limits<int>::min();
    count = 0;
    
    while (true) {
        int num = source->Get();
        if (num < 0) break;
        
        min_value = std::min(min_value, num);
        max_value = std::max(max_value, num);
        count++;
    }
}

std::ostream& operator<<(std::ostream& os, const Diap& diap) {
    if (diap.count > 0) {
        os << "Range statistics:\n"
           << "Minimum value: " << diap.min_value << "\n"
           << "Maximum value: " << diap.max_value << "\n"
           << "Number count: " << diap.count << "\n";
    } else {
        os << "No numbers were processed\n";
    }
    return os;
}
