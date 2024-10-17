#include <iostream>
#include "Elips.h"
#include "ElipsColor.h"


int main() {
    ElipsColor color(255, 255, 0, 50, 25);
    color.output();

    Elips obj1;
    Elips obj2;
    obj1.input();
    obj2.input();
    obj1.output();
    obj2.output();

    Elips obj3 = obj2;
    obj3.output();

    obj1 = obj2;
    obj1.output();

    obj1.input();
    obj1.output();

    double singleValue;
    std::cout << "Enter a single value for obj4: ";
    std::cin >> singleValue;
    Elips obj4(singleValue);
    std::cout << "Object 4 (created from a single value): ";
    obj4.output();

    Elips obj5(3.0, 4.0);
    std::cout << "Object 5 (created from two values): ";
    obj5.output();

    if (obj1 == obj2) {
        std::cout << "obj1 is equal to obj2\n";
    }
    else {
        std::cout << "obj1 is not equal to obj2\n";
    }

    if (obj1 <= obj2) {
        std::cout << "obj1 includes obj2\n";
    }
    else {
        std::cout << "obj1 does not include obj2\n";
    }

    std::cout << "Information about obj1:\n" << obj1;

    double focus1 = calculateFocusX(obj1);
    double focus2 = obj1.calculateFocusY();
    std::cout << "Coordinates of the foci of obj1: F1(" << focus1 << "), F2(" << focus2 << ")\n";
    double ec = obj1.eccentricity();
    std::cout << "Eccentricity of obj1: " << ec << "\n";

    double focalParameter = Elips::focalParameter(obj1.getA(), obj1.getB());
    std::cout << "Focal parameter of obj1: " << focalParameter << "\n";
    obj1.directrixEquations();
    obj1.draw();
	
	return 0;
}
