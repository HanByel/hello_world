#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include <iostream>

using namespace std;

class Point{
public:
    int x;
    int y;

    Point(int _x = 0, int _y = 0);
    ~Point();
    void print() const;

    // + 연산
    const Point operator+(Point& arg) const;

    // 전위 ++
    const Point& operator++();

    // 후위 ++   후위 연산은 ++ 하기 전의 클래스를 반환해야 한다.
    const Point operator++(int);
};

#endif // OPERATOR_HPP
