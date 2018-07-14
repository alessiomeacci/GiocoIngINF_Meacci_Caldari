// Inclusione della libreria allegro
#include "allegro/include/allegro.h"

#include <cstdlib>
#include <ctime>
using std::rand;
using std::srand;

// Inclusione delle classi create
#include "Car.h"
#include "Dynamite.h"

// Dichiarazione delle variabili
BITMAP *buf, *menuIniziale, *background, *scrolling, *explosion;
PALETTE colors;
MIDI *music;
SAMPLE *speedUp;
FONT *pointsFont;
int yScroll = 0;
int speed = 3;
double points = 1;
bool showDynamite = false;


// Prototipi di funzione
void doubleBuffering ( void );
void makeMenu ( void );
void makeBackground ( void );

// Funzioni
void doubleBuffering ( void )
{
    vsync();
    blit ( buf, screen, 0, 0, 0, 0, 600, 640 );
    clear ( buf );
}

void makeMenu ( void )
{
    blit ( menuIniziale, buf, 0, 0, 0, 0, 600, 640 );
}

void makeBackground ( void )
{
    yScroll -= speed;
    blit ( scrolling, buf, 0, yScroll, 0, 0, 600, 640 );
    if ( yScroll <= 0 )
        yScroll = 640;
}

// Inizio del gioco
int main ( void )
{
    srand ( time ( 0 ) );
    allegro_init();
    install_keyboard();
    set_color_depth ( 32 );
    set_palette ( colors );
    set_gfx_mode ( GFX_AUTODETECT, 600, 640, 0, 0 );
    install_sound ( DIGI_AUTODETECT, MIDI_AUTODETECT, 0 );
    music = load_midi ( "Music.mid" );
    speedUp = load_wav ( "SpeedUp.wav" );
    set_volume ( 100, 100 );
    buf = create_bitmap ( 600, 640 );
    clear ( buf );
    scrolling = create_bitmap ( 600, 1280 );
    clear ( scrolling );
    menuIniziale = load_bmp ( "Menu.bmp", colors );
    background = load_bmp ( "Background.bmp", colors );
    explosion = load_bmp ( "Explosion.bmp", colors );
    pointsFont = load_font ( "PointsFont.pcx", NULL, NULL );
    play_midi ( music, TRUE );

    for ( int i = 0; i <= 1280; i += 640 )
        blit ( background, scrolling, 0, 0, 0, i, 600, 640 );


    while ( !key[KEY_ENTER] )
    {
        doubleBuffering();
        makeMenu();
    }

    // Creazione degli oggetti
    Car car;
    Dynamite dynamite;

    while ( !key[KEY_ESC] )
    {
        doubleBuffering();
        makeBackground();
        points += 0.1;

        if ( ( ( dynamite.getY() + 89 ) >= 430 ) && ( dynamite.getY() <= 539 ) )
        {
            if ( ( ( dynamite.getX() + 63 ) >= car.getX() ) && ( dynamite.getX() <= ( car.getX() + 57 ) ) )
            {
                draw_sprite ( buf, explosion, car.getX(), 430 );
                textprintf ( buf, pointsFont, 275, 200, makecol ( 0, 0, 255 ), "%i", static_cast<int>( points ) );
                doubleBuffering();
                break;
            }
        }

        if ( ( static_cast<int> ( points ) % 50 ) == 0 )
        {
            points += 5;
            speed += 2.5;
            play_sample ( speedUp, 255, 128, 1000, FALSE );
        }

        textprintf ( buf, pointsFont, 0, 595, makecol ( 0, 0, 255 ), "%i", static_cast<int>( points ) );

        dynamite.makeDynamite ( buf );

        if ( showDynamite == false )
        {
            showDynamite = true;
        }

        if ( showDynamite == true )
            showDynamite = dynamite.moveDynamite ( speed );

        car.makeCar ( buf );
        car.moveCar ( speed );

    }

    allegro_message ( "Ottimo lavoro!!" );

    destroy_bitmap ( menuIniziale );
    destroy_bitmap ( buf );
    destroy_bitmap ( scrolling );
    destroy_bitmap ( explosion );
    destroy_bitmap ( background );
    destroy_midi ( music );

    return EXIT_SUCCESS;
}
// Fine del gioco
END_OF_MAIN();
