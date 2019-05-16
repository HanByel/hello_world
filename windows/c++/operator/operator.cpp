#include "operator.hpp"

Point::Point(int _x, int _y)
    :x(_x), y(_y){
}

Point::~Point(){

}

void Point::print() const{
    cout << x << "," << y << endl;
}

const Point Point::operator+(Point& arg) const{
    Point pt;
    pt.x = this->x + arg.x;
    pt.y = this->y + arg.y;

    return pt;
}

const Point& Point::operator++(){
    ++x;
    ++y;
    return *this;
}

const Point Point::operator++(int){
    Point tmp = *this;
    ++*this;
    return tmp;
}
