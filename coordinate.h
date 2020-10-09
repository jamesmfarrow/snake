#ifndef COORDINATE_H
#define COORDINATE_H


class coordinate
{
 public:
    int x_coord;
    int y_coord;

    coordinate(int x=0, int y=0) : x_coord(x), y_coord(y) {}

    //copy constructor
    coordinate(const coordinate &other) {
        x_coord = other.x_coord;
        y_coord = other.y_coord;
    }

    //assignment overload operator
    coordinate& operator=(const coordinate &coord) {
        x_coord = coord.x_coord;
        y_coord = coord.y_coord;
        return *this;
    }

    bool operator==(const coordinate& rhs) {
        return this->x_coord == rhs.x_coord && this->y_coord == rhs.y_coord;
    }


};

#endif // COORDINATE_H
