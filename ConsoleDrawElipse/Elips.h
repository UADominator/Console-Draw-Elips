#ifndef Elips_h
#define Elips_h

#include <iostream>

class Elips {
private:
    double a, b;

public:
    Elips();
    Elips(const Elips& other);
    Elips(double val);
    Elips(double aval, double bval);
    ~Elips();
    Elips& operator=(const Elips& other);
    void input();
    void output() const;
    friend double calculateFocusX(const Elips& el); //переробив в друг класу
    double calculateFocusY() const;
    double getA() const;
    double getB() const;
    void setA(double newA);
    void setB(double newB);
    double eccentricity() const; //була Static переробив 
    static double focalParameter(double a, double b);
    void directrixEquations() const;
    void draw() const;
    bool operator==(const Elips& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Elips& elips);
    bool operator<=(const Elips& other) const;
    friend bool operator>=(const Elips& a, const Elips& b);//переробив друг класу

};

#endif
