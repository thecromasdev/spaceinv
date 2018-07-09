#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
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
    int alive;
};
struct enemy_table
 {
    int posx;
    int posy;
    int fire;
    int alive;
    int shield;
    int spritestt;
    char sprite;
    char laser;
};
struct laser_table
{
    int posx;
    int posy;
    int on;
    int use;

};



struct enemy_table Enemy[ENX][ENY];
struct player_table player;
struct laser_table playerl;
struct laser_table enemyl;

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
                    Enemy[enemyx][enemyy].alive = 1;
                    Enemy[enemyx][enemyy].fire = 0;
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
    EnemyArmed();

}


void EnemyDeath (int N1,int N2)
{
    Enemy[N1][N2].alive=0;
    if ( (N1==3) || (Enemy[N1][N2].fire==1)&& (N1!=0))
    {
        Enemy[N1][N2].fire=0;
        Enemy[N1-1][N2].fire=1;
    }

}
void EnemyArmed (void)
{
    int ef2;

        for (ef2=0;ef2<=ENY-1;ef2++)
        {
            Enemy[ENX][ef2].fire=1;

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
    EnemyLaser();
}


void PlayerLaserOn (void)
{
    if (playerl.on==0)
    {
        playerl.on=1;
        playerl.posx=player.posx-1;
        playerl.posy=player.posy;
    }

}
void PlayerLaserTravel (void)
{
    if (playerl.on==1)
    {
        printf("Laser andando em %d,%d \n",playerl.posx,playerl.posy);
        playerl.posx--;
        PlayerLaserHit();
        if(playerl.posx==0)
        {
            playerl.on=0;
        }
    }

}
void PlayerLaserHit (void)
{
    int enmy;
    int enmx;

    if(playerl.on==1)
    {
        for (enmx=0;enmx<=ENX;enmx++)
        {
            for (enmy=0;enmy<=ENY-1;enmy++)
            {
                if ( (Enemy[enmx][enmy].posy==playerl.posy) && (Enemy[enmx][enmy].posx==playerl.posx) && (Enemy[enmx][enmy].alive==1) )
                {
                    EnemyDeath(enmx,enmy);
                    playerl.on=0;
                    player.score= player.score+10;
                    printf ("HIT!");

                }


            }

        }
    }

}
void PlayerLaser (void)
{
    PlayerLaserOn();
    PlayerLaserTravel();
}


void EnemyLaser (void)
{
    EnemyLaserOn();
    EnemyLaserTravel();
}
void EnemyLaserOn(void)
{
    int enfx;
    int enfy;
    srand(time(NULL));

    if (enemyl.on==0)
    {


        for (enfx=ENX;enfx>=0;enfx--)
        {
            enfy= rand() % 5;
            if ( (Enemy[enfx][enfy].alive==1) &&  (Enemy[enfx][enfy].fire==1) && (enemyl.use==0) )
                {
                    enemyl.on=1;
                    enemyl.use=1;
                    enemyl.posx=Enemy[enfx][enfy].posx+1;
                    enemyl.posy=Enemy[enfx][enfy].posy;
                    printf ("\n Disparo inimigo saindo de %d,%d \n",Enemy[enfx][enfy].posx,Enemy[enfx][enfy].posy);
                    break;
                }
        }
    }
}
void EnemyLaserTravel (void)
{
     if (enemyl.on==1)
    {
        printf("\n Disparo inimigo se aproximando em %d,%d \n",enemyl.posx,enemyl.posy);
        enemyl.posx++;
        EnemyLaserHit();

        if(enemyl.posx==WX)
        {
            enemyl.on=0;
            enemyl.use=0;
        }
    }

}
void EnemyLaserHit (void)
{
    if (enemyl.on==1)
    {
            if( (enemyl.posx==player.posx) && (enemyl.posy==player.posy) )
            {
                enemyl.on=0;
                enemyl.use=0;
                player.alive=0;
            }
    }
}


void PlayerLives(void)
{
        if (player.alive == 0)
        {
                GameOver();
        }
}

void GameOver(void)
{
    system("cls");
    printf("\n \n \n Você Perdeu!! \n \n \n ");
    printf("Seu Score foi de %d", player.score);
    system("pause");

    exit(0);

}


void GameGear (void)
{
    while(1)
    {

        PlayerControl();
        Sleep(1000);
        EnemyControl();
        Sleep(1000);
        PlayerLives();

    }
}

void GameStart(void)
{


    player.alive=1;
    player.posx=WX;
    player.posy=WY/2;
    EO[0]=0;
    EO[1]=0;
    EO[2]=0;
    EO[3]=0;
    enemyl.use=0;
    enemyl.on=0;


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
    GameGear();




}

void PlayerControl(void)
{
    char KeyPress;

    //while(1)
   // {
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
                    printf("\n Player andou para Esquerda, atual posicao %d,%d", player.posx,player.posy);
                }
            }
       if (KeyPress == 'd')
            {
                if(player.posy+1!=WY)
                {
                    player.posy++;
                   printf("\n Player andou para Direita, atual posicao %d,%d", player.posx,player.posy);
                }
            }
        if (KeyPress == 'w')
            {
                PlayerLaserOn();
                PlayerLaserTravel();


            }

            //printf("Rodou");
            //Sleep (1000);
    //}
}

int main()
{
    GameStart();

    return 0;
}
