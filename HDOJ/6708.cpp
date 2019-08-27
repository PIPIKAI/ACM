#include<bits/stdc++.h>
using namespace std;
int a[2000][2000],n;
void work(int x,int y,int n,int o){
    if(n==1){
        a[x][y]=o;
        return ;
    }
    n>>=1;
    work(x,y,n,o);
    work(x,y+n,n,o);
    work(x+n,y,n,-o);
    work(x+n,y+n,n,o);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin >> n;
        memset(a,0,sizeof a);
        n= 1<<n;
        work(0,0,n,1);
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++) printf("%c",a[i][j]==1 ? 'C' : 'P');
            printf("\n");
        }
    }
    
    return 0;
}