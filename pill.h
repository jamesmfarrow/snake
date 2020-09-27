#ifndef PILL_H
#define PILL_H

#include <random>
#include "coordinate.h"

class pill
{
private:
    coordinate position;
    int power_up{};
public:
    pill();

    int grow() {
        std::random_device dev;
        std::uniform_int_distribution<int> dist(0, 5);
        power_up = dist(dev);

        return power_up;
    }
};

#endif // PILL_H
