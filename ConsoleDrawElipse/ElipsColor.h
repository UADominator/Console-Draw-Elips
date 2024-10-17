#ifndef ElipsColor_h
#define ElipsColor_h

#include <iostream>
#include "Elips.h"
//DON`T FUCKING TOCH ME
class MyColor {
private: int red, green, blue;

public:
	MyColor(int red, int green, int blue) {
		setRed(red);
		setGreen(green);
		setBlue(blue);
	}


public:
	int getRed() { return red; }
	int getGreen() { return green; }
	int getBlue() { return blue; }

	void setRed(int red) { if (red < 0 || red > 255) this->red = 255; else this->red = red; }
	void setGreen(int green) { if (green < 0 || green > 255) this->green = 255; else this->green = green; }
	void setBlue(int blue) { if (blue < 0 || blue > 255) this->blue = 255; else this->blue = blue; }

	int createColor() {
		return (this->red << 16) | (this->green << 8) | this->blue;
	}
};
//HERE U CAN

class ElipsColor : public Elips {
private:
	MyColor color;

public:
	ElipsColor();
	ElipsColor(const ElipsColor&);
	ElipsColor(const Elips&);
	ElipsColor(MyColor, const Elips&);
	ElipsColor(int, int, int, const Elips&);
	ElipsColor(int, int, int, double, double);

	MyColor getColor() const;

	//@Override
	void input();
	void output() const;


};

#endif