#include <Cell.h>

Cell::Cell(){
    value = false;
}

void Cell::makeAlive(){
    value = true;
}

void Cell::makeDead(){
    value = false;
}

bool Cell::getValue(){
    return value;
}


