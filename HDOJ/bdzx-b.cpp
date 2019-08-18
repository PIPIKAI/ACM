#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<cstring>
using namespace std;
#define Max(x,y) y>x?x=y:x=x
#define mem(a,b)  memset( a,b,sizeof a)
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 1e3+7;
int n,m;
struct node{
    int l,r;
}f[maxn];
int juge(int x,int y,int a,int b){
    if(  y < a){
        return 1;// you bian
    }
    else{
        if(y <= b ){
            if(x<a){
                return 2;//you xiang jiao
            }
            else{
                return 3;//bei bao le
            }
        }
        else{
            if(x<=a){
                return 4;// bao le  ta
            }
            else{
                if(x>b){
                    return 5; //zuobian
                }
                else{
                    return 6; //zuo xiang jiao
                }
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int x,y,a,b;
    while(cin>>x>>y>>a>>b){
        cout<<juge(x,y,a,b);
    }
    int T;cin>>T;
    while (T--)
    {
        ll ans=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>f[i].l>>f[i].r;
        }
        for(int i=0;i<n-1;i++){
            int tp=juge(f[i].l,f[i].r,f[i+1].l,f[i+1],r);
            if(tp==1){

            }
            else if(tp==2){
                
            }
        }
        
    }
    
    return 0;
}