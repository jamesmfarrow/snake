#ifndef PILL_H
#define PILL_H

#include <random>
#include <vector>
#include <array>
#include "coordinate.h"

class pill
{
private:
    coordinate position;

public:
    pill();

    int grow() {
        std::random_device dev;
        std::uniform_int_distribution<int> dist(0, 5);
        return dist(dev);
    }


};

#endif // PILL_H
