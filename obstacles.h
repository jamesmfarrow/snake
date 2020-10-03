#ifndef OBSTACLES_H
#define OBSTACLES_H

#include <random>
#include <vector>
#include "coordinate.h"
#include "GridSize.h"
#include "pill.h"

//pill class and all pills must be initisied before this class

//maye a better way of doing placements, have grid with array of coordinates all with 0x, 0y


class obstacle
{
private:
    coordinate position;
    int obstacles{25};
    std::vector<coordinate> obstacle_pos;
    std::vector<coordinate> pillpostions;
    pill positioned_pills;
    GridSize grid;
public:
    obstacle();

    //method to get the vector of obstacle positions
    std::vector<coordinate> get_Vec() {
        return obstacle_pos;
    }

    //method to fill vector pill positions, to make sure obstacles do not duplicate pills or each other
    void get_pill_pos(std::vector<coordinate> vec) {
        pillpostions = vec;
    }

    //method t place obstacles on gris avoiding all dulicate positions
    void place_pills() {
        while(obstacles > 0) {
            get_pill_pos(positioned_pills.get_Vec());
            bool duplicate{false};
            std::random_device dev;
            std::uniform_int_distribution<int> dist(1,grid.length*grid.breadth);
            coordinate p((dist(dev)/grid.length), (dist(dev)%grid.breadth));
            for(unsigned long int i{}; i < obstacle_pos.size() - 1; i++) {
                if(p == obstacle_pos[i] || p == pillpostions[i]) { duplicate = true; break; }
            }
            if(!duplicate) { obstacle_pos.push_back(p); obstacles--; }
        }
    }



};

#endif // OBSTACLES_H
