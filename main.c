#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define MAXX 11
#define MAXY 13

char World [MAXX][MAXY];

struct player_table
{
    char name[40];
    int dificulty;
    int score;
    char laser;
    char sprite;
    int posx;
    int posy;

};

struct enemy
 {
    int posx;
    int posy;
    int attack;
    int shield;
    char sprite;
    char laser;
};


int main()
{

    struct player_table player;

    /* Tela Inicial */
    printf ("\n \n DIGITE SEU NOME: \n \n \n \n");
    scanf  ("%s", &player.name);
    Sleep (500);
    printf ("\n \n \n Login realizado com Sucesso");
    Sleep (1000);
    system("cls");
    printf ("\n \n                  Bem Vindo %s !       \n \n \n \n", player.name);
    Sleep (500);
    printf ("\n \n O sistema esta sob ataque do virus Sp4c31nv4d3r, precisamos de sua ajuda \n \n \n \n");
    printf ("Olhando no console voce consegue identificar em que nivel o virus esta. Nos informe em que nivel o virus se encontra \n \n \n ");
    printf ("\n 1 - Bypass no Antivirus \n");
    printf ("\n 2 - Computador esta Lento \n");
    printf ("\n 3 - Arquivos Encriptografados \n \n");
    Sleep (1000);
    scanf ("%d", &player.dificulty);
    printf (" \n \n Entendido!! Iremos te deixar frente a frente com o virus. Ao seu sinal, liberaremos o console e tudo estara em suas maos");
    printf(" \n \n  Boa sorte...");
    Sleep (1000);





    return 0;
}
