#ifndef RECT_H
#define RECT_H

class Rect{
	float x;
	float y;
	float w;
	float h;
	float r;
	float g;
	float b;

	float theta;
	bool slide;

public:
	Rect();
	Rect(float, float, float, float, float r=1, float g=0, float b=0);

	void draw() const;

	void setY(float y);
	float getY() const;

	void setX(float x);
	float getX() const;

	void (*func)();

	//bool clicked;

	void sideToSide();
	void makeCircle();

    void handle(float x, float y);
};

#endif
