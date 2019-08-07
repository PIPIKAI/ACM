#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define MAX 100
typedef struct{
	int sn;
	int en;
	int w;
}EDGE;

typedef struct{
	int V;
	int E;
	EDGE M[MAX];
}MAP;

MAP *Initial()
{
	MAP *m;
	int i;
	m = (MAP *)malloc(sizeof(MAP));
	scanf("%d%d",&m->V,&m->E);
	for(i=0;i<m->E;i++)
	{
		scanf("%d%d%d",&m->M[i].sn,&m->M[i].en,&m->M[i].w);
	}
	return m;
}

int cmp(EDGE a,EDGE b)
{
	return a.w<b.w;
}

void display(MAP *m)
{
	int i;
	printf("\ns e w\n");
	for(i=0;i<m->E;i++)
	{
		printf("%d %d %d\n",m->M[i].sn,m->M[i].en,m->M[i].w);
	}
	return;
}

void displayResult(EDGE result[],int n)
{
	int i;
	printf("\ns e w\n");
	for(i=0;i<n;i++)
	{
		printf("%d %d %d\n",result[i].sn,result[i].en,result[i].w);
	}
	return;	
}

void Kruscal(MAP *m,EDGE result[])
{
	int i,j,count = 0,t,tsn,ten;
	int vis[MAX];
	for(i=0;i<MAX;i++)
	{
		vis[i] = i;
	}
	for(i=0;i<m->E;i++)
	{
		if(vis[m->M[i].sn] == vis[m->M[i].en])
		{
			continue;
		}		
		tsn = vis[m->M[i].sn];
		ten = vis[m->M[i].en];		
		result[count] = m->M[i];
		count++;		
		for(j=0;j<m->V;j++)
		{
			if(vis[j]==ten)
			{
				vis[j] = tsn;	
			}	
		}
		if(count==m->V-1)
		{
			break;
		}
	}	
	return;
}

int main()
{
	freopen("map1.txt","r",stdin);
	MAP *map;
	EDGE result[MAX];
	map = Initial();
	sort(&map->M[0],&map->M[map->E],cmp);
	display(map);
	Kruscal(map,result);
	displayResult(result,map->V-1);
	return 0;
}
