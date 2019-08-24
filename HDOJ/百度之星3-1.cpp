#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
int mm[1000][1000];
using namespace std;
int main()
{
    int k,i,j,n,m;
    //读入n和m，n表示顶点个数，m表示边的条数
    scanf("%d %d",&n,&m);

    //初始化
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            if(i==j)
                mm[i][j]=0;
            else
                mm[i][j]=inf;
    int a,b,c;
    //读入边
    for(i=1; i<=m; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        mm[a][b]=c;
         mm[b][a]=c;
    }

    //Floyd-Warshall算法核心语句
    int ans=0;
    for(int p=0;p<=n;p++){
        for(k=1; k<=p; k++)
                for(i=1; i<=n; i++)
                    for(j=1; j<=n; j++)
                        if(mm[i][j]>mm[i][k]+mm[k][j] ){
                            mm[i][j]=mm[i][k]+mm[k][j];
                            cout<<p<<endl;
                            ans+=p;
                        }
                            
        
    }
    cout<<ans<<endl;
    return 0;
}
