#include <Square.h>

Square::Square(){
    //-1 = Bomb
    //0 = Blank
    //Other values are the # of bombs it surrounds
    value = 0;
    flag = false;
    open = false;
    first_blast = false;
}

void Square::openSquare(){
    open = true;
}

void Square::blasted(){
    first_blast = true;
}

bool Square::isBlasted(){
    if(open == true){
        return true;
    }else{
        return false;
    }
}

bool Square::isOpen(){
    if(open == true){
        return true;
    }else{
        return false;
    }
}

void Square::makeFlag(){
    flag = true;
}

void Square::unmakeFlag(){
    flag = false;
}

bool Square::isFlag(){
    if(flag == true){
        return true;
    }else{
        return false;
    }
}

void Square::makeBomb(){
    value = -1;
}

void Square::makeBlank(){
    value = 0;
    flag = false;
    open = false;
    first_blast = false;
}

void Square::setValue(int x){
    value = x;
}

int Square::getValue(){
    return value;
}

bool Square::isBomb(){
    if(value == -1){
        return true;
    }

    return false;
}