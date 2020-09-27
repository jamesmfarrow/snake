#ifndef COORDINATE_H
#define COORDINATE_H


class coordinate
{
private:
    int x_coord;
    int y_coord;
public:
    coordinate();
    coordinate(int x, int y) : x_coord(x), y_coord(y) {}

    void setX(int x) { x_coord = x; }
    void setY(int y) { y_coord = y; }
    void SetBoth(int x, int y) { setX(x), setY(y); }

    int getX() { return x_coord; }
    int getY() { return y_coord; }

    bool operator==(const coordinate& rhs) {
        return this->x_coord == rhs.x_coord && this->y_coord == rhs.y_coord;
    }

};

#endif // COORDINATE_H
