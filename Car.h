#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include "allegro/include/allegro.h"

class Car
{
public:
    Car ( void );
    ~Car ( void );
    void makeCar ( BITMAP * );
    void moveCar ( int );
    int getX ( void );
private:
    PALETTE colors;
    BITMAP *car;
    int xCar;
};


#endif // CAR_H_INCLUDED
