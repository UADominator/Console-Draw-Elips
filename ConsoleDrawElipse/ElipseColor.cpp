#include "ElipsColor.h"
#include "Elips.h"
#include "graphics.h" // добавити у проект ці 2 файли
#pragma comment(lib,"graphics.lib") // добавити у проект ці 2 файли

ElipsColor::ElipsColor() : Elips(), color(128, 128, 128) {
}

ElipsColor::ElipsColor(const ElipsColor& other) : Elips(other), color(other.color) {
}

ElipsColor::ElipsColor(const Elips& other) : Elips(other), color(255, 255, 255){
}

ElipsColor::ElipsColor(MyColor color, const Elips& other) : Elips(other), color(color) {
}

ElipsColor::ElipsColor(int r, int g, int b, const Elips& other) : Elips(other), color(r, g, b) {
}

ElipsColor::ElipsColor(int r, int g, int b, double aval, double bval) : Elips(aval, bval), color(r, g, b) {
}

void ElipsColor::input() {
    Elips::input();
    std::cout << "Enter Color RGB:\n";
    int r, g, b;
    std::cin >> r >> g >> b;
    color = MyColor(r, g, b);
}

MyColor ElipsColor::getColor() const {
    return color;
}

void ElipsColor::output() const {
    Elips::output();

    std::cout << "RGB Color: \n\t\Red:" << this->getColor().getRed() << "\n\t\Green: " << this->getColor().getGreen() << "\n\t\Blue: " << this->getColor().getBlue() << std::endl;

    int gd = DETECT, gm;

    initgraph(&gd, &gm, nullptr);

    setcolor(this->getColor().createColor());
    ellipse(300, 200, 0, 360, this->getA(), this->getB()); // Еліпс зі центром у (300, 200), радіусами 100 і 50
    getch();
    closegraph();
}



