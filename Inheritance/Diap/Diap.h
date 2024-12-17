#ifndef DIAP_H
#define DIAP_H

#include "../Freq/Freq.h"
#include <limits>

class Diap : public Freq {
private:
    int min_value;
    int max_value;
    int count;

public:
    Diap() : min_value(std::numeric_limits<int>::max()), 
             max_value(std::numeric_limits<int>::min()),
             count(0) {}
    
    void Calc(SBase* source) override;
    
    friend std::ostream& operator<<(std::ostream& os, const Diap& diap);
};

#endif // DIAP_H
