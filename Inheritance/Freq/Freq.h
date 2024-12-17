#ifndef FREQ_H
#define FREQ_H

#include "../SBase/SBase.h"
#include <map>
#include <iostream>

class Freq {
protected:
    std::map<int, int> frequencies;
    int total_sum;

public:
    Freq() : total_sum(0) {}
    virtual ~Freq() = default;
    
    virtual void Calc(SBase* source);
    
    friend std::ostream& operator<<(std::ostream& os, const Freq& freq);
};

#endif // FREQ_H
