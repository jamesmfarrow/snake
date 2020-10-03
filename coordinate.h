#ifndef COORDINATE_H
#define COORDINATE_H

/*
class coordinate
{
private:
    int x_coord;
    int y_coord;
public:
    coordinate();
    coordinate(int x, int y) : x_coord(x), y_coord(y) {}

    void changeX(int off) { x_coord+=off; }
    void changeY(int off) { y_coord+=off; }

    void setX(int x) { x_coord = x; }
    void setY(int y) { y_coord = y; }
    void SetBoth(int x, int y) { setX(x), setY(y); }

    int getX() { return x_coord; }
    int getY() { return y_coord; }

    bool operator==(const coordinate& rhs) {
        return this->x_coord == rhs.x_coord && this->y_coord == rhs.y_coord;
    }

};
*/

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
