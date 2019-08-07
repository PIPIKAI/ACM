#include<iostream>
#include<algorithm>
using namespace std;
int n;
int p[70]={0};
int f[20];
int book[20];
void biao()
{
    int i,j;
    p[1]=1;
    for(i=2;i<70;i++)
        if(!p[i])
            for(j=i;j*i<=70;j++)
                p[j*i]=1;
}
void dfs(int step)
{
    int i;
    if(step>n&&!p[f[step-1]+1])
    {
        for(i=1;i<=n;i++)
            cout<<f[i]<<" ";
        cout<<endl;
        return ;
    }
    for(i=2;i<=n;i++)
    if(book[i]==0)
    {
        if(!p[i+f[step-1]])
        {
            f[step]=i;
            book[i]=1;
            dfs(step+1);
            book[i]=0;
        }
    }
}
int main()
{
    biao();
    book[1]=f[1]=1;
    cin>>n;
    dfs(2);
    return 0;
}
