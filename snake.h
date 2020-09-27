#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "coordinate.h"

class snake
{
private:
    coordinate head;
    std::vector<coordinate> tail;
    enum class direction{ left, right };
public:
    snake();

};

#endif // SNAKE_H
