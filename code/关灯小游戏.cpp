/*#include<stdio.h>
#include<bits/stdc++.h>
int sum[200][9],aa=-1;
int kg[9][4]={
    1,3,-1,-1,
    0,4,2,-1,
    1,5,-1,-1,
    0,6,4,-1,
    1,3,5,7,
    2,4,8,-1,
    3,7,-1,-1,
    4,6,8,-1,
    5,7,-1,-1,
};
using namespace std;
int main()
{
    int f[9];
    int juge[9];

    for(int i=0;i<9;i++)
    {
        memset(f,0,sizeof(f));
        int t=0;
        for(int j=8;t<=i;t++,j--)
            f[j]=1;
            /*for(int i=0;i<9;i++)
            cout<<f[i];
            cout<<endl;
        do
        {
            memset(juge,0,sizeof(juge));
            for(int i=0;i<9;i++)
            {
                if(f[i])
                {
                    for(int j=0;j<4;j++)
                    {
                        if(kg[i][j]!=-1)
                        {
                            if(juge[kg[i][j]])
                                juge[kg[i][j]]=0;
                            else
                                juge[kg[i][j]]=1;
                        }
                    }
                }
            }
            int co=0;
            for(int i=0;i<9;i++)
            {
                if(juge[i])
                    co++;
            }
            if(co==4)
            {
                 for(int j=0;j<9;j++)
                cout<<f[j];
                cout<<endl;
                /*++aa;
                for(int i=0;i<9;i++)
                   sum[aa][i]=f[i];

            }
        }while(next_permutation(f,f+9));
    }
    for(int i=aa;i>=0;i--)
    {
        for(int j=0;j<9;j++)
            cout<<sum[i][j];
        cout<<endl;
    }
    return 0;
}*/
#include<stdio.h>
#include<string.h>

int sum=0;
int a[10][10]={{2,4},{1,3,5},{2,6},{1,5,7},{2,4,6,8},{3,5,9},{4,8},{5,7,9},{6,8}};
char c[2000][10];
int mark[12],b[12];

void f(int k,int aa[],int bb[]);
int main()
{
    int i,j;

    memset(b,0,sizeof(b));
    memset(mark,0,sizeof(mark));
    memset(c,0,sizeof(c));

    f(0,mark,b);
    for(i=0;i<sum;i++)
    {
        for(j=0;j<9;j++)
            printf("%c",c[i][j]);
        printf("\n");
//      printf("%s\n",c[i]);
//      puts(c[i]);
    }
//  printf("%d\n",sum);
    return 0;
}

void f(int k,int aa[],int bb[])
{
    int i,t=0,ab[12];

    for(i=1;i<10;i++)
    {
        ab[i]=aa[i];
        if(aa[i]==1)
            t++;
    }
    if(t==4){
        for(i=0;i<9;i++)
            c[sum][i]=bb[i]+'0';
        c[sum][i]='\0';
        sum++;
        for(i=0;i<sum-1;i++)
        {
            if(strcmp(c[i],c[sum-1])==0){
                sum--;
                break;
            }
        }
    }
    if(k==9){
        return;
    }

    f(k+1,ab,bb);
    for(i=0;a[k][i];i++)
    {
        if(ab[a[k][i]]==0)
            ab[a[k][i]]=1;
        else    ab[a[k][i]]=0;
    }

    bb[k]=1;
    f(k+1,ab,bb);
    bb[k]=0;
}
