#include<bits/stdc++.h>
using namespace std;
const int maxn=999;
int f[maxn],k[maxn],x,y,ans;
bool vis[]
void dfs(int xi,int yi,int step)
{

}
int main()
{
    cin>>x>>y;
    for(int i=0;i<x;i++){
        cin>>f[i];
    }
    for(int i=0;i<y;i++){
        cin>>k[i];
    }
    dfs(0,0,0);
    cout<<x+y-ans<<endl;
    return 0;
}