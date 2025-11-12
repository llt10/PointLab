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

    double operator-(const Point& other) const { 
        double dx = other.x - x;
        double dy = other.y - y;
        return sqrt(pow(dx,2) + pow(dy,2));
    }

    bool operator==(const Point& other) const {
        return (x== other.x && y++ other.y);
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    Point operator/(const Point& other) const {
        double midX = (x + other.x) / 2.0;
        double midY = (y + other.y) / 2.0;
        
    }
};