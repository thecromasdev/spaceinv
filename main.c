#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define WALL 124
#define WX 10
#define WY 16
#define ENX 2
#define ENY 5

// int MaxX; //Variavel Global para o X do tabuleiro

//int MaxY; //Variavel Global para o X do tabuleiro

unsigned int World[WX][WY];
int EO[3]; //Variavel de orientação de movimento 0 equivale a esquerda e 1 equivale direita.
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
struct player_table player;

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
    SpawnEnemy();
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

                if ( (enemyx<= ENX) && (enemyy < ENY)  )  // Verifica se nao extrapola matriz inimigos

                {
                    Enemy[enemyx][enemyy].posx = auxe;
                    Enemy[enemyx][enemyy].posy = auxn;
                    printf("%d,%d \n",Enemy[enemyx][enemyy].posx,Enemy[enemyx][enemyy].posy);
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
    int eg0=0;
    if (EO[3] == 0)

    {
        if( (Enemy[0][0].posy - 1 ) != 0)
        {
            eg0=0;
            while (eg0<ENY)
            {
                Enemy[0][eg0].posy= Enemy[0][eg0].posy -1;
                printf ("Moveu para a Esquerda %d, %d \n", Enemy[0][eg0].posx,Enemy[0][eg0].posy);
                eg0++;

            }
        }
        else
        {
            EO[3]=1;
            eg0=0;
            while (eg0<ENY)
            {
                Enemy[0][eg0].posx= Enemy[0][eg0].posx +1 ;
                printf ("Moveu uma Linha %d, %d \n", Enemy[0][eg0].posx,Enemy[0][eg0].posy);
                eg0++;

            }
         }
    }
    else
    {
        if( (Enemy[0][ENY-1].posy + 1 ) != 16)
        {
            eg0=0;
            while (eg0<ENY)
            {
                Enemy[0][eg0].posy= Enemy[0][eg0].posy +1;
                printf ("Moveu para a Direita %d, %d \n", Enemy[0][eg0].posx,Enemy[0][eg0].posy);
                eg0++;

            }
        }
        else
        {
            EO[3]=0;
            eg0=0;
            while (eg0<ENY)
            {
                Enemy[0][eg0].posx= Enemy[0][eg0].posx +1 ;
                printf ("Moveu uma Linha %d, %d \n", Enemy[0][eg0].posx,Enemy[0][eg0].posy);
                eg0++;

            }
         }
    }
}
void EnemyMoveG1 (void)
{
    int eg1=0;
    if (EO[1] == 0)

    {
        if( (Enemy[1][0].posy - 1 ) != 0)
        {
            eg1=0;
            while (eg1<ENY)
            {
                Enemy[1][eg1].posy= Enemy[1][eg1].posy -1;
                printf ("Moveu para a Esquerda %d, %d \n", Enemy[1][eg1].posx,Enemy[1][eg1].posy);
                eg1++;

            }
        }
        else
        {
            EO[1]=1;
            eg1=0;
            while (eg1<ENY)
            {
                Enemy[1][eg1].posx= Enemy[1][eg1].posx +1 ;
                printf ("Moveu uma Linha %d, %d \n", Enemy[1][eg1].posx,Enemy[1][eg1].posy);
                eg1++;

            }
         }
    }
    else
    {
        if( (Enemy[1][ENY-1].posy + 1 ) != 16)
        {
            eg1=0;
            while (eg1<ENY)
            {
                Enemy[1][eg1].posy= Enemy[1][eg1].posy +1;
                printf ("Moveu para a Direita %d, %d \n", Enemy[1][eg1].posx,Enemy[1][eg1].posy);
                eg1++;

            }
        }
        else
        {
            EO[1]=0;
            eg1=0;
            while (eg1<ENY)
            {
                Enemy[1][eg1].posx= Enemy[1][eg1].posx +1 ;
                printf ("Moveu uma Linha %d, %d \n", Enemy[1][eg1].posx,Enemy[1][eg1].posy);
                eg1++;

            }
         }
    }
}
void EnemyMoveG2 (void)
{
    int eg2=0;
    if (EO[2] == 0)

    {
        if( (Enemy[2][0].posy - 1 ) != 0)
        {
            eg2=0;
            while (eg2<ENY)
            {
                Enemy[2][eg2].posy= Enemy[2][eg2].posy -1;
                printf ("Moveu para a Esquerda %d, %d \n", Enemy[2][eg2].posx,Enemy[2][eg2].posy);
                eg2++;

            }
        }
        else
        {
            EO[2]=1;
            eg2=0;
            while (eg2<ENY)
            {
                Enemy[2][eg2].posx= Enemy[2][eg2].posx +1 ;
                printf ("Moveu uma Linha %d, %d \n", Enemy[2][eg2].posx,Enemy[2][eg2].posy);
                eg2++;

            }
         }
    }
    else
    {
        if( (Enemy[2][ENY-1].posy + 1 ) != 16)
        {
            eg2=0;
            while (eg2<ENY)
            {
                Enemy[2][eg2].posy= Enemy[2][eg2].posy +1;
                printf ("Moveu para a Direita %d, %d \n", Enemy[2][eg2].posx,Enemy[2][eg2].posy);
                eg2++;

            }
        }
        else
        {
            EO[2]=0;
            eg2=0;
            while (eg2<ENY)
            {
                Enemy[2][eg2].posx= Enemy[2][eg2].posx +1 ;
                printf ("Moveu uma Linha %d, %d \n", Enemy[2][eg2].posx,Enemy[2][eg2].posy);
                eg2++;

            }
         }
    }
}

void EnemyControl (void)
{
    EnemyMoveG2();
    EnemyMoveG1();
    EnemyMoveG0();

}

void PlayerControl(void)
{
    char KeyPress;

    while(1)
    {
        if(kbhit())
            {
                KeyPress = getch();
            }
        else
            {
            KeyPress = ' ';
            }

        if (KeyPress == 'a')
            {
                if(player.posy-1!=0)
                {
                    player.posy--;
                    printf("Player andou para Esquerda, atual posição %d", player.posy);
                }
            }
       if (KeyPress == 'd')
            {
                if(player.posy+1!=WY)
                {
                    player.posy++;
                    printf("Player andou para Direita, atual posição %d", player.posy);
                }
            }
        if (KeyPress == 'w')
            {
                printf("Fire in the Hole");

            }
            printf("Rodou");
            Sleep (1000);
    }
}

int main()

{
    player.posx=WX;
    player.posy=WY/2;
    EO[0]=0;
    EO[1]=0;
    EO[2]=0;
    EO[3]=0;


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
    PlayerControl();
   

    return 0;
}
