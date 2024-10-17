#include "Elips.h" 
#include <cmath> 

Elips::Elips() : a(0), b(0) {
    std::cout << "Default constructor called \n";
}

Elips::Elips(const Elips& other) {
    this->a = other.a;
    this->b = other.b;
    std::cout << "Copy constructor called. Copying values a: "
        << other.a << " ³ b: " << other.b << std::endl;
}

Elips::Elips(double val) : a(val), b(val) {
    std::cout << "Constructor with one value called. Values a and b: "
        << val << std::endl;
}

Elips::Elips(double aval, double bval) : a(aval), b(bval) {
    std::cout << "Constructor with two values called. Value a: "
        << aval << ", b: " << bval << std::endl;
}

Elips::~Elips() {
    std::cout << "Destructor called\n";
}

Elips& Elips::operator=(const Elips& other) {
    if (this != &other) {
        a = other.a;
        b = other.b;
        std::cout << "Assignment operator called \n";
    }
    return *this;
}

void Elips::input() {
    std::cout << "Enter values for a and b: ";
    std::cin >> a >> b;
}

void Elips::output() const {
    std::cout << "Values a: " << a << ", b: " << b << std::endl;
}

double calculateFocusX(const Elips& el) {
    if (el.a > el.b) {
        return sqrt(el.a * el.a - el.b * el.b);
    }
    else {
        return 0;
    }
}

double Elips::calculateFocusY() const {
    if (b > a) {
        return sqrt(b * b - a * a);
    }
    else {
        return 0;
    }
}

double Elips::getA() const {
    return a;
}

double Elips::getB() const {
    return b;
}

void Elips::setA(double newA) {
    a = newA;
}

void Elips::setB(double newB) {
    b = newB;
}

double Elips::eccentricity() const {
    if (a > b) {
        return sqrt(1 - (b * b) / (a * a));
    }
    else {
        return sqrt(1 - (a * a) / (b * b));
    }
}

double Elips::focalParameter(double a, double b) {
    return (a * a) / b;
}

void Elips::directrixEquations() const {
    if (eccentricity() != 0) {
        double c = calculateFocusX(*this);
        std::cout << "Directrix equations:\n";
        std::cout << "x = " << (a * a / c) << " and x = " << -(a * a / c) << std::endl;
    }
    else {
        std::cout << "The ellipse is a circle, no directrices exist." << std::endl;
    }
}

void Elips::draw() const {
    const int width = 40;
    const int height = 20;
    const double aspect_ratio = static_cast<double>(height) / width;

    for (int y = -height / 2; y <= height / 2; ++y) {
        for (int x = -width / 2; x <= width / 2; ++x) {
            double ellipse_equation = (pow(x / (a * aspect_ratio), 2) + pow(y / b, 2));
            if (ellipse_equation <= 1.0) {
                std::cout << "*";
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}

bool Elips::operator==(const Elips& other) const {
    return (a == other.a && b == other.b);
}

std::ostream& operator<<(std::ostream& os, const Elips& elips) {
    os << "Ellipse: a = " << elips.a << ", b =  " << elips.b;
    std::cout << "\n";
    return os;
}

bool Elips::operator<=(const Elips& other) const {
    return (a <= other.a && b <= other.b);
}

bool operator>=(const Elips& a, const Elips& b) {
    return (a.a >= b.a && a.b >= b.b);
}

