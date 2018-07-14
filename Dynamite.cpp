#include "Dynamite.h"
#include "allegro.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Dynamite::Dynamite ( void )
{
    dynamite = load_bmp ( "Dynamite.bmp", colors );
    srand ( time ( 0 ) );
    xDynamite = 300;
}

Dynamite::~Dynamite ( void )
{
    destroy_bitmap ( dynamite );
}

void Dynamite::makeDynamite ( BITMAP *buffer )
{
    draw_sprite ( buffer, dynamite, xDynamite, yDynamite );
}

bool Dynamite::moveDynamite ( int speed )
{
    yDynamite += speed;
    if ( yDynamite >= 640 )
    {
        yDynamite = -100;
        setXDynamite();
        return false;
    }
    return true;
}

void Dynamite::setXDynamite ( void )
{
    xDynamite = 45 + rand() % 430; // Genera un numero casuale compreso fra 45 e 493
}

int Dynamite::getX ( void )
{
    return xDynamite;
}

int Dynamite::getY ( void )
{
    return yDynamite;
}
