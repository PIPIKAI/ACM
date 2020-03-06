//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e3+7;
const int inf = 0x3f3f3f3f;
int n,m;
int ans[maxn][maxn];
int k[12];
void work(int n,int x,int y){
	if(n==1){
		ans[x][y]=1;
		return ;
	}
	int len=k[n-2];
	work(n-1,x,y);
	work(n-1,x+2*len,y);
	work(n-1,x,y+2*len);
	work(n-1,x+len,y+len);
	work(n-1,x+2*len,y+2*len);

}
int main(int argc, char * argv[]) 
{
	k[0]=1;
	for(int i=1;i<12;i++){
		k[i]=k[i-1]*3;
	}
	std::ios::sync_with_stdio(false);
    while(cin>>n,n>0){
    	work(n,1,1);
    	for(int i=1;i<=k[n-1];i++){
    		for(int j=1;j<=k[n-1];j++){
    			if(ans[i][j]){
    				cout<<'X';
    			}
    			else{
    				cout<<' ';
    			}
    		}
    		cout<<endl;
    	}
    	cout<<'-'<<endl;
    }
    return 0;
}