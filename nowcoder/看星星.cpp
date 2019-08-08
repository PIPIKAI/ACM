#include<bits/stdc++.h>
using namespace std;
const int maxn=50;
int f[maxn][1001],k[maxn][1001],x,y,ans;
int main()
{
    cin>>x>>y;
    for(int i=0;i<x;i++){
        cin>>f[i][1];
    }
    for(int i=0;i<y;i++){
        cin>>k[i][1];
    }
    
    int maxj=max(k[y-1][1]/f[0][1],f[x-1][1]/k[0][1] );
    
    for(int i=0;i<x;i++){
        for(int j=2;j<=maxj;j++){
            f[i][j]=f[i][1]*j;
        }
    }
    
    for(int i=0;i<y;i++){
        for(int j=2;j<=maxj;j++){
            k[i][j]=k[i][1]*j;
        }
    }
    
    
    for(int j=1;j<=maxj;j++){
        for(int l=1;l<=maxj;l++){
            int tp=0;
            for(int i=0;i<x;i++){
                for(int r=0;r<y;r++){
                    if(f[i][j] ==k[r][l]){
                        tp++;
                    }
                }
            }
            ans=max(ans,tp);
            tp=0;
            
        }
    }
    cout<<x+y-ans<<endl;
    return 0;
}