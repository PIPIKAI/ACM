#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<stdio.h>
#define MAXN 26
using namespace std;
typedef struct{
	char a;
	int w;
}DATE;
typedef struct{
	DATE data[MAXN];
	int len;
}SQlist;
typedef struct{
	char ch;
	int wei,i_p,i_r,i_l;
}HULIST;
void display(HULIST hf[],int n);
void Creat_HuffList(HULIST hf[],int n);
SQlist* initi_Sqilst()
{
	SQlist *sq;
	int i;
	sq=(SQlist*)malloc(sizeof(SQlist));
	for(i=0;i<MAXN;i++){
		sq->data[i].a=i+97;
		sq->data[i].w=0;
	}
	return sq;
}
void statistics(SQlist *sq)
{
	char ch;
	while(cin>>ch)	{
		if(ch>='a'&&ch<='z')
			sq->data[ch-97].w++;
		else if(ch<='Z'&&ch>='A')
			sq->data[ch-65].w++;
	}
}
void inti_HuffSqList(HULIST hf[],SQlist *sq)
{
	int len=0;
	for(int i=0;i<MAXN;i++)
	if(sq->data[i].w!=0)
	{
		hf[len].ch=sq->data[i].a;
		hf[len].wei=sq->data[i].w;
		hf[len].i_p=-1;
		hf[len].i_r=-1;
		hf[len].i_l=-1;
		len++;
	}
	Creat_HuffList(hf,len);
}
void Creat_HuffList(HULIST hf[],int n)
{
	int min1,min2,m1_i,m2_i,len=n;
	for(int i=0;i<n-1;i++){
		min1=min2=500;
		m1_i=m2_i=-1;
		for(int j=0;j<n+i;j++)
			if(hf[j].i_p==-1)
				if(hf[j].wei<min2)
					if(hf[j].wei<min1){
						min1=hf[j].wei;
						m1_i=j;
					}
					else{
						min2=hf[j].wei;
						m2_i=j;
					}
		//-------------------------------------------------------
		hf[n+i].wei=min1+min2;
		hf[n+i].ch='#';
		hf[n+i].i_r=m1_i;
		hf[n+i].i_l=m2_i;
		hf[n+i].i_p=-1;
		hf[m1_i].i_p=n+i;
		hf[m2_i].i_p=n+i;
	}
	display(hf,n*2-2);
}
void display(HULIST hf[],int n)
{
    cout<<"i    "<<"h      "<<"w        "<<"p       "<<"l          "<<"r"<<endl<<endl;
	for(int i=0;i<=n;i++)
		cout<< i<<"    "<<hf[i].ch<<"    "<<hf[i].wei<<"        "<<hf[i].i_p<<"        "<<hf[i].i_l<<"        "<<hf[i].i_r<<endl;
}
int main()
{
	freopen("hu.txt","r",stdin);
	SQlist *sq;
	HULIST hff[2*MAXN-1];
	sq=initi_Sqilst();
	statistics(sq);
	inti_HuffSqList(hff,sq);
	return 0;
}
