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
    move direction{move::north};
    turn change{turn::left};
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
    // first need to know which direction travelling
    // 2 choices left/right
    // north + left = west, north + right = east
    // east + left = north, east + right = south
    // south + left = east, south + right = west
    // west + left = south, west + right = north

    void change_direction() {
        if(direction == move::north && change == turn::left) {
            direction = move::west;
        }
        else if(direction == move::north && change == turn::right) {
            direction = move::east;
        }

        if(direction == move::east && change == turn::left) {
            direction = move::north;
        }
        else if(direction == move::east && change == turn::right) {
            direction = move::south;
        }

        if(direction == move::south && change == turn::left) {
            direction = move::east;
        }
        else if(direction == move::south && change == turn::right) {
            direction = move::west;
        }

        if(direction == move::west && change == turn::left) {
            direction = move::south;
        }
        else if(direction == move::west && change == turn::right) {
            direction = move::north;
        }
    }


    // self collision test
    bool self_collision() {
        for(unsigned long int i{1}; i < body.size() - 1; i++) {
            if(body[0] == body[i]) return true;
        }
        return false;
    }

};

#endif // SNAKE_H
