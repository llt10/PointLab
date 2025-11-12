#include <iostream>
#include <cmath>

using namespace std;

class Point {
private: 
    double x;
    double y;

public:
    Point(double xCoord = 0.0, double yCoord = 0.0) {
        x = xCoord;
        y = yCoord;
    }

    double operator-(const Point& other) const { //wouldn't let me 

    }
};