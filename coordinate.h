#ifndef COORDINATE_H
#define COORDINATE_H


class coordinate
{
private:
    int x_coord;
    int y_coord;
public:
    coordinate();

    bool operator==(const coordinate& rhs) {
        return this->x_coord == rhs.x_coord && this->y_coord == rhs.y_coord;
    }

};

#endif // COORDINATE_H
