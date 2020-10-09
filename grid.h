#ifndef GRID_H
#define GRID_H

#include "GridSize.h"
#include "coordinate.h"
#include <vector>
#include <random>

//#include <cstdlib>
//#include <ctime>


//collisions?

class Grid
{
private:
    //size of the grid play area
    int grid_length;
    int grid_breadth;
    enum item_type{pill, obstacle};

    struct item {
        item_type type=pill;
        coordinate position;
    };

    std::vector<item> items_on_grid;




public:
    //constructor - place pils/obstacles randomly on grid
    //use %2 to decide whether pill/obstacle
    Grid(int number_of_items, int length=50, int breadth=50) {
        std::random_device dev;
        std::uniform_int_distribution<int> dist(0,length*breadth);
        for(int i{}; i < number_of_items; i++) {
            coordinate p((dist(dev)/length), (dist(dev)%breadth));
            item it;
            it.type=(dist(dev)%2) ? item_type::pill : item_type::obstacle;
            it.position=p;
            items_on_grid.push_back(it);
        }
    }

};

#endif // GRID_H
