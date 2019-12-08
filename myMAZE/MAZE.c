#include "stdafx.h"
#include "Maze.h"
#include "public.h"
#include "Queue.h"
int visited[hight][wight];
int mask[hight][wight];
int area[hight][wight];
int maze[hight][wight];
point in,out;
int di[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
int check(int x,int y){
    if(x>=0&&x<hight&&y<wight&&y>=0&&!visited[x][y]){
        return 1;
    }
    return 0;
}
void initMaze()
{

	srand((unsigned)time(NULL));
    for (int i = 0; i < hight; i++)
		for (int j = 0; j < wight; j++)
        maze[i][j]=WALL,visited[i][j]=0;
    int vis=2;
    visited[in.x][in.y]=1;
    visited[out.x][out.y]=1;
    maze[in.x][in.y]=ROAD;
    maze[out.x][out.y]=ROAD;
    squeue q;
    initqueue(q);
    qqush(q,in);
    while(!isempty(q)){
        point tp=qfront(q),pt;qpop(q);
        visited[tp.x][tp.y]=1;
        maze[tp.x][tp.y]=ROAD;
        int bt;
        int x=tp.x,y=tp.y;
        if(!check(tp.x+1,tp.y)&&!check(tp.x,tp.y+1)&&!check(tp.x-1,tp.y)&&!check(tp.x,tp.y-1)){
            for(int i=0;i<4;i++){
                x=tp.x+di[i][0],y=tp.y+di[i][1];
                if(x >=0 &&x<hight&&y>=0&&y<wight){
                    pt.x=x;pt.y=y;
                    qqush(q,pt);
                }
            }
            continue;
        }
        do{
             bt=rand()%4;
             x=tp.x+di[bt][0],y=tp.y+di[bt][0];
        }while(!check( x, y));
        pt.x=x;pt.y=y;
        qqush(q,pt);
        Sleep(2);
        showBlock();
    } 
	
}
void showBlock()
{
	for (int i = 0; i < hight; i++)
	{
		for (int j = 0; j < wight; j++)
		{
			if (mask[i][j] == ROAD)
				printf("  ");
			else if (maze[i][j] == WALL)
				printf("¨€");
			else if (maze[i][j] == WORKED)
				printf("¡õ");
			else if (maze[i][j] == LEFT)
				printf("¡ú");
			else if (maze[i][j] == DOWN)
				printf("¡ý");
			else if (maze[i][j] == RIGHT)
				printf("¡û");
			else if (maze[i][j] == UP)
				printf("¡ü");
			if (j != 0 && j % (wight - 1) == 0)
				printf("\n");
		}
	}
    system("CLS");
}
int main(){
    initMaze();
    return 0;
}