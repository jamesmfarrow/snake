#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "coordinate.h"

enum class turn{ left, right };
enum class move{ north, south, east, west };

class snake
{
private:
    //coordinate head;
    std::vector<coordinate> body;
    move direction;
    //int length;

public:
    snake(coordinate pos);

    coordinate get_head() const {
        return body[0];
    }

    move get_direction() const {
        return direction;
    }

    void grow(int growth) {
        //int size = body.size();
        coordinate last = body.back();
        for(int i{}; i < growth; i++) {
            body.push_back(last);
        }
    }

    void movement() {

        for(int i=body.size() - 1; i > 0; i--){
            body[i] = body[i - 1];
        }

        switch(direction){
        case move::north:
            body[0].y_coord++;
            break;
        case move::south:
            body[0].y_coord--;
            break;
        case move::east:
            body[0].x_coord++;
            break;
        case move::west:
            body[0].x_coord--;
        break;

        }
    }

    // change direction


    // self collision test
    bool self_collision() {
        for(unsigned long int i{1}; i < body.size() - 1; i++) {
            if(body[0] == body[i]) return true;
        }
        return false;
    }

};

#endif // SNAKE_H
