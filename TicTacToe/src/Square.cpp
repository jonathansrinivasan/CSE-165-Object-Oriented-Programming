#include <Square.h>

Square::Square(){
    //0 = blank
    //1 = X
    //2 = O
    value = 0;
}

void Square::makeBlank(){
    value = 0;
}

void Square::makeX(){
    value = 1;
}

void Square::makeO(){
    value = 2;
}

int Square::getValue(){
    return value;
}