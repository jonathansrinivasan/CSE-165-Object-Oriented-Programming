#include "Rect.h"
#include "GlutApp.h"
#include <iostream>
#include <math.h>

//change r and theta in order to make it go in a circle

Rect::Rect(){
	x = 0;
	y = 0;
	w = 0.5;
	h = 0.5;
	r = 1;
	g = 0;
	b = 0;
}

Rect::Rect(float x, float y, float w, float h, float r, float g, float b){
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->r = r;
	this->g = g;
	this->b = b;
	theta = 0;

	slide = false;
}

void Rect::draw() const {
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);

	glVertex2f(x, y);
	glVertex2f(x+w, y);
	glVertex2f(x+w, y-h);
	glVertex2f(x, y-h);

	glEnd();
}


void Rect::setY(float y){
	this-> y = y;
}

float Rect::getY() const {
	return y;
}

void Rect::setX(float x){
	this->x=x;
}

float Rect::getX() const{
	return x;
}

void Rect::sideToSide() {
	
	if (getX() >= 0.6)
        slide = false;
    

    if (getX() <= -0.9)
        slide = true;
    

    if (slide == true)
        setX(getX() + 0.01);
    else
        setX(getX() - 0.01);
    
}

void Rect::makeCircle(){
	setX(0.5 * cos(theta));
	setY(0.5 * sin(theta));

	theta += 2 * M_PI/60;
}

  void Rect::handle(float x, float y){
 	if (x >= this->x && x <= this->x + w && y <= this->y && y >= this->y -h)
         func();
 	
 }



