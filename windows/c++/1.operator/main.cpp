#include "operator.hpp"

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

