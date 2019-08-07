/*
题目:p1501 二叉树最大宽度和高度
*/
#include <iostream>
using namespace std;
typedef struct bit
{
    int i;
    int left,right;
}ttt;
ttt f[20];
void inti()
{
    int n,i;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>f[i].left>>f[i].right;
}
int with(int i,int dp)
{
    if(i==0) return 0;
    if(dp==1) return 1;
    int l=with(f[i].left,dp-1);
    int r=with(f[i].right,dp-1);
    return l+r;
}
int dpth(int i)
{
    if(i==0) return 0;
        int ll=dpth(f[i].left);
        int rl=dpth(f[i].right);
        return ll>rl?ll+1:rl+1;
}
int main()
{
    inti();
   int maxd=dpth(1),maxw=1;
   int i,j;
   for(i=2;i<maxd;i++)
       maxw=maxw>with(1,i)?maxw:with(1,i);

   cout<<maxw<<" "<<maxd<<endl;
    return 0;
}

