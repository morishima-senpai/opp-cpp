#include "Freq.h"

void Freq::Calc(SBase* source) {
    frequencies.clear();
    total_sum = 0;
    
    while (true) {
        int num = source->Get();
        if (num < 0) break;
        
        frequencies[num]++;
        total_sum += num;
    }
}

std::ostream& operator<<(std::ostream& os, const Freq& freq) {
    os << "Number frequencies:\n";
    for (const auto& pair : freq.frequencies) {
        os << "Number " << pair.first << " appears " << pair.second << " times\n";
    }
    os << "Total sum: " << freq.total_sum << "\n";
    return os;
}
