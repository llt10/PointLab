#include <iostream>
#include <cmath>

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
        return std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
    }

    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    Point operator/(const Point& other) const {
        double midX = (x + other.x) / 2.0;
        double midY = (y + other.y) / 2.0;
        return Point(midX, midY);
    }

    static void printPoint(std::ostream& output, const Point& p) {
        output << "(" << p.x << ", " << p.y << ")";
    }

    static void inputPoint(std::istream& input, Point& p) {
        std::cout << "Enter x coordinate: ";
        input >> p.x;
        std::cout << "Enter y coordinate: ";
        input >> p.y;
    }

    Point& operator++() {
        x++;
        return *this;
    }

    Point operator++(int) {
        Point temp = *this;
        y++;
        return temp;
    }

    Point& operator--() {
        x--;
        return *this;
    }

    Point operator--(int) {
        Point temp = *this;
        y--;
        return temp;
    }

    double& operator[](int index) {
        if (index == 0)
            return x;
        else if (index == 1)
            return y;
        else {
            std::cout << "Invalid index! Returning x by default." << std::endl;
            return x;
        }
    }
};

int main() {
    Point p1(3.2, 9.8);
    Point p2(5.5, -1.2);

    std::cout << "Distance: " << (p1 - p2) << std::endl;
    std::cout << "Equal? " << (p1 == p2) << std::endl;
    std::cout << "Not Equal? " << (p1 != p2) << std::endl;
    std::cout << "Midpoint: ";
    Point::printPoint(std::cout, p1 / p2);
    std::cout << std::endl;
    ++p1;
    p1++;
    std::cout << "After increments: ";
    Point::printPoint(std::cout, p1);
    std::cout << std::endl;
    --p1;
    p1--;
    std::cout << "After decrements: ";
    Point::printPoint(std::cout, p1);
    std::cout << std::endl;

    std::cout << "X coordinate using []: " << p1[0] << std::endl;
    std::cout << "Y coordinate using []: " << p1[1] << std::endl;

    Point p3;
    Point::inputPoint(std::cin, p3);
    std::cout << "You entered: ";
    Point::printPoint(std::cout, p3);
    std::cout << std::endl;

    return 0;
}
