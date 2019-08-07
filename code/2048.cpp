#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>

void Game_display();
void addRand();
void initGame();
void startGame();
void moveUp();
void moveRight();
void moveLeft();
void moveDown();
void GameOver();

int  getNULL();
int score=0;
int best=0;
int board[4][4]={0};
int if_need_add_rand;//need->1,else ->0.
int if_GameOver;//end is 1 else 0

int main()
{
    startGame();
    return 0;
}
void addRand()
{
    srand((unsigned )time (NULL));
    int i,j;
    while(1)
    {
        i=rand()%4;
        j=rand()%4;
        if(board[i][j]==0)
        {
            board[i][j]=(rand()%3?2:4);
            return ;
        }
        else
        {
            continue;
        }
    }
}
void Game_display()
{
    printf("\n                  GAME:2048\n");
    printf("--------------------------------------------\n\n");
    printf("      SCORE:%5d    BEST:%5d\n",score,best);
    printf("┏━━━━┳━━━━┳━━━━┳━━━━┓\n");
    for(int i=0;i<4;i++)
    {
         printf("┃");
         for(int j=0;j<4;j++)
        {
            if(board[i][j]!=0)
                printf("%4d    ┃",board[i][j]);
                else
                    printf("        ┃");
        }
        if(i<3)
        printf("\n┣━━━━╋━━━━╋━━━━╋━━━━┫\n");
        else
            printf("\n┗━━━━┻━━━━┻━━━━┻━━━━┛\n");
    }

    printf("\n--------------------------------------------\n\n");
    printf("        用方向键控制\n\n\n"); 
    return ;
}
//初始化游戏
void initGame()
{
	system("mode con cols=45 lines=28");
	system("title 2048");
    system("cls");
    system("color 6"); 
    score=0;
    if_need_add_rand=1;
    if_GameOver=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            board[i][j]=0;
        }
    }
    int i,j;
    i=(rand())%4;
    j=rand()%4;
    board[i][j]=2;// begin one of is 2

    Game_display();
    return;
}

void startGame()
{

    initGame();
    while(1)
    {
        if(getch()!='\0')
        {
            switch(getch())
        {
            case 75:
                moveLeft();
                break;
            case 77:
                moveRight();
                break;
            case 72:
                moveUp();
                break;
            case 80:
                moveDown();
                break;
            default:
                break;
        }
        }

        score>best?best=score:1;// flash best
           system("cls");
            Game_display();

        // panduan if end
        // no ge zi
        if(getNULL()==0)
        {
                system("cls");
                printf("\n\n\n\n\n\nSCORE:%5d  \n",score);
               printf(" \n\n      GAME    OVER!!\n\n\n        RESART? \n              Press|Y| -> RESTAR\n              Press|N| -> EXIT\n ");
               switch(getch())
               {
                case 'n':
                case 'N':
                    exit(1);
                    break;
                case 'y':
                case 'Y':
                    return startGame();
                    break;
               }
        }

    }
}
int  getNULL()
{
    int n=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
    {
        if(board[i][j]==0)
        {
            n++;
        }
    }
    return n;
}
void GameOver()// jiaji next
{
    for(int i=0;i<4;i++)
        for(int j=0;j<3;j++)
    {
        if(board[i][j]==board[i][j+1]||board[j][i]==board[j+1][i])
        {
            if_GameOver=0;
            return ;
        }
    }
    if_GameOver=1;
}
void moveLeft()
{
    for(int i=0;i<4;i++)
    {
        for(int j=1,k=0;j<4;j++)
        {
            if(board[i][j]>0)
            {
                //Case :k and j ==
                if(board[i][k]==board[i][j])
                {
                    score+=board[i][k++]<<=1; //*2
                    board[i][j]=0;
                    if_need_add_rand=1;
                }
                // k=0
                else if(board[i][k]==0)
                {
                    board[i][k]=board[i][j];
                    board[i][j]=0;
                    if_need_add_rand=1;
                }

                else//  f[i] != f[k]
                {
                    board[i][++k]=board[i][j];
                    if(j != k )//is pang bian?
                    {
                        board[i][j]=0;
                        if_need_add_rand=1;
                    }
                    // else is max
                }
            }
        }
    }
    addRand();
}

void moveRight()
{
    for(int i=0;i<4;i++)
    {
        for(int j=2,k=3;j>=0;j--)
        {
            if(board[i][j]>0)
            {
                if(board[i][j]==board[i][k])
                {
                    score+=board[i][k--]<<=1;
                    board[i][j]=0;
                    if_need_add_rand=1;
                }
                else if(board[i][k]==0)
                {
                    board[i][k]=board[i][j];
                    board[i][j]=0;
                    if_need_add_rand=1;

                }
                else
                {
                    board[i][--k]=board[i][j];
                    if(j!=k)
                    {
                        board[i][j]=0;
                        if_need_add_rand=1;
                    }
                }
            }
        }
    }
    addRand();
}
void moveDown()
{
     for(int i=0;i <4;i++)
    {
       for(int j=2,k=3;j >=0;j--)
        {
            if(board[j][i]>0)
            {
                //Case :k and j ==
                if(board[k][i]==board[j][i])
                {
                    score+=board[k--][i]<<=1; //*2
                    board[j][i]=0;
                    if_need_add_rand=1;
                }
                // k=0
                else if(board[k][i]==0)
                {
                    board[k][i]=board[j][i];
                    board[j][i]=0;
                    if_need_add_rand=1;
                }

                else//  f[i] != f[k]
                {
                    board[--k][i]=board[j][i];
                    if(j != k )//is pang bian?
                    {
                        board[j][i]=0;
                        if_need_add_rand=1;
                    }
                    // else is max
                }
            }
        }
    }
    addRand();
}

void moveUp()
{
     for(int i=0;i <4;i++)
    {
       for(int j=1,k=0;j <4;j++)
        {
            if(board[j][i]>0)
            {
                //Case :k and j ==
                if(board[k][i]==board[j][i])
                {
                    score+=board[k++][i]<<=1; //*2
                    board[j][i]=0;
                    if_need_add_rand=1;
                }
                // k=0
                else if(board[k][i]==0)
                {
                    board[k][i]=board[j][i];
                    board[j][i]=0;
                    if_need_add_rand=1;
                }

                else//  f[i] != f[k]
                {
                    board[++k][i]=board[j][i];
                    if(j != k )//is pang bian?
                    {
                        board[j][i]=0;
                        if_need_add_rand=1;
                    }
                    // else is max
                }
            }
        }
    }
    addRand();
}
