#ifndef SQUARE
#define SQUARE

class Square {
public:
    int value;
    bool open;
    bool flag;
    bool first_blast;
    Square();

    void blasted();
    bool isBlasted();

    void openSquare();
    bool isOpen();

    void makeFlag();
    void unmakeFlag();
    bool isFlag();

    void makeBomb();
    void makeBlank();
    bool isBomb();

    void setValue(int);
    int getValue();
    
};

#endif