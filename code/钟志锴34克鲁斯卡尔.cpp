#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define MAX 100
typedef struct{
	int a,b,w;
}bian;
typedef struct{
	int V,E;
	bian m[MAX];
}MAP;
MAP *init()
{
	MAP *mm;
	mm=(MAP*)malloc(sizeof(MAP));
	cin>>mm->V>>mm->E;
	for(int i=0;i<mm->E;i++)
	cin>>mm->m[i].a>>mm->m[i].b>>mm->m[i].w;
	 return mm;
}
bool cmp(bian a,bian b)
{
	return a.w<b.w;
}
void display(MAP *map,bian ans[])
{
	for(int i=0;i<map->V-1;i++)
		printf("%4d%4d%4d\n",ans[i].a,ans[i].b ,ans[i].w);
}

void Kuls(MAP * map,bian ans[])
{
	int vis[MAX];
	int co=0;
	for(int i=0;i<MAX;i++)
		vis[i]=i;
	for(int i=0;i<map->E;i++)//
	{
		if(vis[map->m[i].a]==vis[map->m[i].b] )
			continue;
		int ta= vis[map->m[i].a] ;
		int tb= vis[map->m[i].b] ;
		ans[co++]=map->m[i];

		for(int j=0;j<map->V;j++)
			if(vis[j]==tb)
			vis[j]=ta;
		if(co==map->V-1)
			break;
	}
}
int main()
{
	freopen("kuls.txt","r",stdin);
	MAP *map;
	bian ans[MAX];
	map=init();
	sort(&map->m[0],&map->m[map->E],cmp);
	Kuls( map,ans);
	display(map,ans);
	return 0;
}
