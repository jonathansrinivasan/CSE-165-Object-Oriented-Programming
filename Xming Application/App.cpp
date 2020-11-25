#include <iostream>
#include <cmath>
#include "App.h"

static App* singleton;
static App* singleton2;

void doSomething(){
    singleton->moveSideToSide = !singleton->moveSideToSide;
}

void doSomething2(){
    singleton->makeCircle = !singleton->makeCircle;
}

App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    
    fullscreen = false;

    object = new Rect(-0.8, 0.8, 0.3, 0.1, 1, 0, 1);

    button1 = new Rect(-0.5, -0.8, 0.2, 0.1);
    button2 = new Rect(0.3, -0.8, 0.2, 0.1);

    button1->func = doSomething;
    button2->func = doSomething2;

    singleton = this;
    singleton2 = this;

    moveSideToSide = false;
    makeCircle = false;
    
}

void App::draw() const {
    object->draw();
    button1->draw();
    button2->draw();
}

void App::leftMouseDown(float x, float y){
    button1->handle(x,y); 
    button2->handle(x, y);
}

void App::idle(){
    if(moveSideToSide == true){
        object->sideToSide();
        redraw();
    }

    if(makeCircle == true) {
        object->makeCircle();
        redraw();
    }
}


void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
    else if (key == 'f'){
        toggleFullScreen();
    }
    redraw();
}

App::~App(){    
    delete object;
    delete button1;
    delete button2;
}
