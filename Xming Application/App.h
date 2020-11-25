#ifndef App_h
#define App_h
#include <vector>

#include "GlutApp.h"
#include "Rect.h"


class App: public GlutApp {
    
    bool fullscreen;
    
    Rect* object;

    Rect* button1;
    Rect* button2;

    bool up;
public:

    bool moveSideToSide;
    bool makeCircle;
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw() const;
    
    void keyDown(unsigned char key, float x, float y);

    void leftMouseDown(float x, float y);

    void idle();
    
    ~App();
};

#endif
