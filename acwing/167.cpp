#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int vis[100],stick[100],n,cnt,len,sum;
bool cmp(int a,int b){
    return a > b;
}
bool dfs(int k,int nowlen,int step){
    if(k * len == sum) return true ;
    if( nowlen == len  ) return dfs(k+1,0,0);
    int fail=0;
    for(int i=step;i<n;i++){
        if(vis[i]) continue;
        if(nowlen + stick[i] >len) continue;
        if(stick[i] == fail) continue;

        vis[i] = 1;
        if(dfs(k,nowlen + stick [i] , i+1 ) ){
            return true;
        }
        fail= stick[i];
        vis[i] = 0;
        if(nowlen == 0 || nowlen + stick[i] == len){
            return false;
        }
    }
    return false;
}
int main(){
    while(cin>>n && n){
        sum=0,cnt=0,len=0;
        for(int i=0,tp;i<n;i++){
            cin>>tp;
            if( tp >50) continue;
            stick[cnt++]=tp;
            len=max(len,tp);
            sum+=tp;
        }
        n=cnt;
        sort(stick,stick+n,cmp);
        for(len;len<=sum;len++){
            memset(vis,0,sizeof vis);
            if(sum % len==0 && dfs(0,0,0)){
                cout<<len<<endl;
                break;
            }
        }
    }

    return 0;
}