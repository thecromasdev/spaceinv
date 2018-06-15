#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define WALL 124
#define WX 10
#define WY 15
#define ME 14
// int MaxX; //Variavel Global para o X do tabuleiro
//int MaxY; //Variavel Global para o X do tabuleiro
unsigned int World[WX][WY];

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

struct enemy_table
 {
    int id;
    int posx;
    int posy;
    int attack;
    int shield;
    int spritestt;
    char sprite;
    char laser;
};


struct enemy_table Enemy[ME];


/* int SizeWorldX(int tier) //Define o Tamanho x da matriz do "tabuleiro"
{
    int WorldX;
    switch (tier)
    {
        case 1 :
            WorldX=10;
            return WorldX;
        case 2 :
            WorldX=20;
            return WorldX;
        case 3 :
            WorldX=30;
            return WorldX;

        default :
            WorldX=10;
            return WorldX;


    }
return WorldX;

}

int SizeWorldY(int tier)  //Define o Tamanho y da matriz do "tabuleiro"
{
    int WorldY;
    switch (tier)
    {
        case 1 :
            WorldY=15;
            return WorldY;
        case 2 :
            WorldY=25;
            return WorldY;
        case 3 :
            WorldY=35;
            return WorldY;

        default :
            WorldY=15;
            return WorldY;
    }

return WorldY;
}
*/

void SpawnWorld(void)
{
int j;

for (j=0;j < WX ; j++)
{
    World[j][0]= WALL;
    World[j][WY] = WALL;
}

}


void DisplayWorld(void)
{
    int x;
    int y;

    for (x=0;x<=WX+1;x++)
    {
        for(y=0;y<=WY;y++)
        {
            printf("%c",World[x][y]);

        }
        printf("\n");
    }


}



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
   /* printf ("Olhando no console voce consegue identificar em que nivel o virus esta. Nos informe em que nivel o virus se encontra \n \n \n ");
    printf ("\n 1 - Bypass no Antivirus \n");
    printf ("\n 2 - Computador esta Lento \n");
    printf ("\n 3 - Arquivos Encriptografados \n \n");
    Sleep (1000);
    scanf ("%d", &player.dificulty); */
    printf (" \n \n Entendido!! Iremos te deixar frente a frente com o virus. Ao seu sinal, liberaremos o console e tudo estara em suas maos");
    printf(" \n \n  Boa sorte...");
    Sleep (1000);
    system("cls");

    //MaxX = SizeWorldX(player.dificulty); Dificuldade
   //MaxY = SizeWorldY(player.dificulty); Dificuldade

    SpawnWorld();
    DisplayWorld();


    return 0;
}
