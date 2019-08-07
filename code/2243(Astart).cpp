#include<limits>
#include<queue>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>

using namespace std;
struct node{
	int h,f,g;
	int step;
	int x,y;
	bool operator < (const node k)const{
		return f>k.f;
	}
};
priority_queue <node> q;
int X1,Y1,X2,Y2,ans=0;
int vis[10][10];
int d[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
int H(node q)
{
	return (abs(q.x-X2)+abs(q.y-Y2))*10;
}
int juge_in(node q)
{
	if(q.x>7||q.y>7||q.x<0||q.y<0)
	return 0;
	return 1;
}
void Astart()
{
	node t,g;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		vis[t.x][t.y]=1;
		if(t.x==X2&&t.y==Y2)
		{
			ans=t.step ;return ;
		}
		for(int i=0;i<8;i++)
		{
			g.x=t.x+d[i][0];
			g.y=t.y+d[i][1];
			if(juge_in(g)&&!vis[g.x][g.y])
			{
				g.h=H(g);
				g.g=t.g+23;
				g.f=g.h+g.g;
				g.step=1+t.step;
				q.push(g);
			}
		}
	}
 } 
int main()
{
	char s[5];
	while (gets(s)){
		X1=s[0]-'a';Y1=s[1]-'1';
		X2=s[3]-'a';Y2=s[4]-'1';
		 memset(vis,0,sizeof(vis));
		while(!q.empty()) q.pop();
		node t;
		t.step=t.g=0;
		t.x=X1,t.y=Y1;
		t.h=H(t);
		t.f=t.g+t.h;
		q.push(t);
		ans=0;
		Astart();
		printf("To get from %c%c to %c%c takes %d knight moves.\n",s[0],s[1],s[3],s[4],ans);
	}
	return 0;
}
