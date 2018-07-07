#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define WALL 124
#define WX 10
#define WY 16
#define ENX 2
#define ENY 4
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
    int posx;
    int posy;
    int attack;
    int shield;
    int spritestt;
    char sprite;
    char laser;
};


struct enemy_table Enemy[ENX][ENY];


void nothing(void)
{



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

}

void SpawnWorld(void)
{
int auxj;

for (auxj=0;auxj < WX ; auxj++)
{
    World[auxj][0]= WALL;
    World[auxj][WY] = WALL;
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

void DebugEnemy(void)
{
    int xe;
    int ye;

    for (xe=0;xe<=ENX;xe++)
    {
        for(ye=0;ye<=ENY;ye++)
        {
            printf("%d,%d \n",Enemy[xe][ye].posx,Enemy[xe][ye].posy);

        }
        printf("\n");
    }


}


void SpawnEnemy(void)
{
    int auxe;
    int auxn;
    int enemyx =0;
    int enemyy =0;

    for (auxe=0;auxe<WX;auxe++)
    {
        for (auxn=0;auxn<WY;auxn++)
        {

        if( (auxn>3) && (auxn<14) && (auxe <WX-5) ) // Verifica se esta em espaco para criar inimigos
        {
            if ( (enemyx<= ENX) && (enemyy <= ENY) )  // Verifica se nao extrapola matriz inimigos
            {
                Enemy[enemyx][enemyy].posx = auxe;
                Enemy[enemyx][enemyy].posy = auxn;
                //printf("%d,%d \n",Enemy[enemyx][enemyy].posx,Enemy[enemyx][enemyy].posy);
                enemyy++;
            }


        }
        auxn++;
        }
       auxe++;
       enemyx++;
       enemyy=0;
    }


}

void EnemyMoveG0 (void)
{
    char e0; // variavel de sentido do movimento.
    int eg0=0;

    e0='l';

    if (e0 == 'l')
    {
        if( (Enemy[0][0].posy - 1 ) != 0)
        {
            eg0=0;
            while (eg0<=ENY)
            {
                Enemy[0][eg0].posy= Enemy[0][eg0].posy -1;
                eg0++;
                printf ("Moveu para a Esquerda %d, %d \n", Enemy[0][eg0].posx,Enemy[0][eg0].posy);
            }
        }

         else
         {
             e0='r';
             eg0=0;
              while (eg0<=ENY)
            {
                Enemy[0][eg0].posx= Enemy[0][eg0].posx +1 ;;
                eg0++;
                printf ("Moveu uma Linha %d, %d \n", Enemy[0][eg0].posx,Enemy[0][eg0].posy);
            }
         }
    }

    else
    {
        if( (Enemy[0][0].posy + 1 ) != 16)
        {
            eg0=0;
            while (eg0<=ENY)
            {
                Enemy[0][eg0].posy= Enemy[0][eg0].posy +1;
                eg0++;
                printf ("Moveu para a Direita %d, %d \n", Enemy[0][eg0].posx,Enemy[0][eg0].posy);
            }
        }

        else
         {
             e0='l';
             eg0=0;
              while (eg0<=ENY)
            {
                Enemy[0][eg0].posx= Enemy[0][eg0].posx +1 ;;
                eg0++;
                printf ("Moveu uma Linha %d, %d \n", Enemy[0][eg0].posx,Enemy[0][eg0].posy);
            }
         }
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
    SpawnEnemy();
    EnemyMoveG0();
   // DisplayWorld();
   // DebugEnemy();


    return 0;
}
