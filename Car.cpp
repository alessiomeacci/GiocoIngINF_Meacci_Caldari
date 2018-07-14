#include "Car.h"
#include "allegro/include/allegro.h"

Car::Car ( void )
{
    car = load_bmp ( "Car.bmp", colors );
    xCar = 300;
}

Car::~Car ( void )
{
    destroy_bitmap ( car );
}

void Car::makeCar ( BITMAP *buffer )
{
    draw_sprite ( buffer, car, xCar, 430 );
}

void Car::moveCar ( int speed )
{
    if ( ( key[KEY_LEFT] ) && ( xCar >= 45 ) )
        xCar -= speed * 0.6;
    if ( ( key[KEY_RIGHT] ) && ( xCar <= 493 ) )
        xCar += speed * 0.6;
}

int Car::getX ( void )
{
    return xCar;
}
