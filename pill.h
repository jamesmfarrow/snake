#ifndef PILL_H
#define PILL_H

#include <random>
#include <vector>
#include "coordinate.h"
#include "GridSize.h"

class pill
{
private:
    coordinate position;
    int pills{25};
    std::vector<coordinate> pill_pos;
    GridSize grid;
public:
    pill();

    int grow() {
        std::random_device dev;
        std::uniform_int_distribution<int> dist(1, 5);
        return dist(dev);
    }

    void place_pills() {
        while(pills > 0) {
            bool duplicate{false};
            std::random_device dev;
            std::uniform_int_distribution<int> dist(1,grid.length*grid.breadth);
            coordinate p((dist(dev)/grid.length), (dist(dev)%grid.breadth));
            for(unsigned long int i{}; i < pill_pos.size() - 1; i++) {
                if(p == pill_pos[i]) { duplicate = true; break; }
            }
            if(!duplicate) { pill_pos.push_back(p); pills--; }
        }
    }

    std::vector<coordinate> get_Vec() {
        return pill_pos;
    }

};

#endif // PILL_H
