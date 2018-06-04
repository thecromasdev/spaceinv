#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define MAXX 20
#define MAXY 23

char World [MAXX][MAXY];

int main()
{
    int xpos=0;
    int ypos=0;

    World[xpos][ypos] = 'a';

    printf ("%c", World[xpos][ypos]);

    return 0;
}
