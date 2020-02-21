//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
int n,m,dx[5]={0,0,1,-1,0},dy[5]={0,1,0,0,-1};
char f[20][20],cp[20][20];
void trun(int x,int y){
	for(int i=0;i<5;i++){
		cp[x+dx[i]][y+dy[i]]^=1;
	}
}
int main(int argc, char * argv[]) 
{
	int T;
    cin>>T;
    while(T--){
    	for(int i=0;i<5;i++){
    		cin>>f[i];
    	}
    	int ans=inf;
    	for(int i=0;i< 1<<5;i++){ // 枚举第一行是否需要按的所有情况
    		int sum=0,isok=1;
    		memcpy(cp,f,sizeof cp);
    		for(int j=0;j<5;j++){
    			if(i >>j & 1){
    				trun(0,j);
    				sum++;
    			}
    		}
    		for(int j=1;j<5;j++){
    			for(int k=0;k<5;k++){
    				if(cp[j-1][k]=='0'){
    					trun(j,k);
    					sum++;
    				}
    			}
    		}
    		for(int j=0;j<5;j++){
    			if(cp[4][j]=='0') isok=0;
    		}
    		if(isok) ans=min(sum,ans);
    	}
    	if(ans>6){
    		cout<<-1<<endl;
    	}
    	else{
    		cout<<ans<<endl;
    	}

    }
    return 0;
}