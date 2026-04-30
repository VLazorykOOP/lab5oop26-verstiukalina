#include <iostream>
#include <cmath>
#include <cstring>
#include <cctype>
#include <windows.h>
#undef Ellipse
using namespace std;

class Point {
protected:
    double x, y;

public:
    Point() {
        x = 0;
        y = 0;
    }

    Point(double x1, double y1) {
        x = x1;
        y = y1;
    }

    ~Point() {
        cout << "Деструктор точки\n";
    }

    void drukuvaty() {
        cout << "Точка: x = " << x << ", y = " << y << endl;
    }

    double ploshcha() {
        return 0;
    }
};

class MyEllipse : public Point {
protected:
    double a, b;

public:
    MyEllipse() : Point() {
        a = 1;
        b = 1;
    }

    MyEllipse(double x1, double y1, double a1, double b1) : Point(x1, y1) {
        a = a1;
        b = b1;
    }

    ~MyEllipse() {
        cout << "Деструктор еліпса\n";
    }

    void drukuvaty() {
        cout << "Центр еліпса: x = " << x << ", y = " << y << endl;
        cout << "Півосі: a = " << a << ", b = " << b << endl;
        cout << "Площа = " << ploshcha() << endl;
    }

    double ploshcha() {
        return 3.14 * a * b;
    }
};

class Circle : public MyEllipse {
public:
    Circle() : MyEllipse() {}

    Circle(double x1, double y1, double r) : MyEllipse(x1, y1, r, r) {}

    ~Circle() {
        cout << "Деструктор кола\n";
    }

    void drukuvaty() {
        cout << "Центр кола: x = " << x << ", y = " << y << endl;
        cout << "Радіус: r = " << a << endl;
        cout << "Площа = " << ploshcha() << endl;
    }

    double ploshcha() {
        return 3.14 * a * a;
    }
};

