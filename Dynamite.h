#ifndef DYNAMITE_H_INCLUDED
#define DYNAMITE_H_INCLUDED
#include "allegro/include/allegro.h"

class Dynamite
{
public:
    Dynamite ( void );
    ~Dynamite ( void );
    void makeDynamite ( BITMAP * );
    bool moveDynamite ( int );
    void setXDynamite ( void );
    int getX ( void );
    int getY ( void );
private:
    PALETTE colors;
    BITMAP *dynamite;
    int xDynamite, yDynamite;
};


#endif // DYNAMITE_H_INCLUDED
