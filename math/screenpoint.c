#include "../include/mathheader.h"

/*
    X * Y = pixelcounts on screen
*/

t_screenpoint make_screen(int in_x, int in_y)
{
    t_screenpoint screen;

    screen.x = in_x;
    screen.y = in_y;
    screen.aspect_ratio = screen.x / screen.y;

    return (screen);
}

float   get_screen_aspect_ratio(t_screenpoint *screen)
{
    return (screen->aspect_ratio);
}

