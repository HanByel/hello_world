#include <iostream>
using namespace std;

class Point{
    int x;
    int y;
public:
    Point(int _x = 0, int _y = 0)
        :x(_x), y(_y){
    }

    void print() const { cout << x << "," << y << endl; }

    // + 연산
    const Point operator+(Point& arg) const{

        Point pt;
        pt.x = this->x + arg.x;
        pt.y = this->y + arg.y;

        return pt;
    }

    // 전위 ++
    const Point& operator++(){
        ++x;
        ++y;
        return *this;
    }

    // 후위 ++   후위 연산은 ++ 하기 전의 클래스를 반환해야 한다.
    const Point operator++(int){
        Point tmp = *this;
        ++*this;
        return tmp;
    }
};


int main(){

    Point p1(2, 3), p2(5, 5);
    Point p3;

    p3 = p1 + p2;
    p3.print();
    p3 = p1.operator+(p2);
    p3.print();

    Point result;
    result = ++p1;
    p1.print();
    result.print();

    result = p2++;
    p2.print();
    result.print();

    return 0;
}

