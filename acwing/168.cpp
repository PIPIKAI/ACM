//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=9;
const int inf = 0x3f3f3f3f;
int n,m,bin_d[1<<maxn],ones[1<<maxn],h[maxn],l[maxn],k[maxn][maxn];
string s;
int lowbit(int x){
	return x& -x;
}
inline int get(int x,int y){ // 获得 x,y 位此时能选的方案，即（）并集
	return h[x] & l[y] & k[x/3][y/3];
}
void init(){ // 初始化数组为二进制，当某位为1的时候代表这个数在（某行？？）可选
	for(int i=0 ;i<maxn ;i++) h[i]=l[i]= (1<<maxn )-1;
	for(int i=0 ;i<3 ; i++)
		for(int j=0 ;j<3 ; j++)
			k[i][j]=(1<<maxn)-1;
}
void calout(){
	for(int i=0;i<s.size();i++){
    		cout<<s[i]<<" ";
    		if((i+1)%9==0) cout<<endl;
    }
}
bool dfs(int cnt){
	if(!cnt){
		return true;
	}
	// 找出方案数最少的 x,y
	int minv=10,x,y;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(s[i*9+j] == '.'){
				int k=ones[get(i,j)];
				if(k<minv){
					minv=k;
					x=i,y=j;
				}
			}
		}
	}
	for(int i=get(x,y);i ; i-=lowbit(i)){
		int tp=bin_d[lowbit(i)];
		s[x * 9 + y] = '1'+ tp;
		h[x]-= 1<<tp;
		l[y]-= 1<<tp;
		k[x/3][y/3]-= 1<<tp;
		/////// 优先
		if( dfs(cnt-1) ) return true;
		//////
		s[x * 9 + y] = '.';
		h[x]+= 1<<tp;
		l[y]+= 1<<tp;
		k[x/3][y/3]+= 1<<tp;
	}
	return false;
}
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
	for(int i=0;i<maxn;i++) bin_d[1<<i]=i;
	for(int i=0;i<1<<maxn ; i++){
		int tp=i;
		while(tp){
			ones[i]++;
			tp-=lowbit(tp);
		}
	}

    while(cin>>s,s[0]!='e'){
    	init();
    	int cnt=0;
    	for(int i=0;i<maxn;i++){
    		for(int j=0;j<maxn;j++){
    			if(s[i*9 + j]!='.'){
    				int tp=s[i*9 + j]-'1';
    				h[i]-= 1<<tp ;
    				l[j]-= 1<<tp ;
    				k[i/3][j/3]-= 1<<tp;
    			}
    			else{
    				cnt++;
    			}
    		}
    	}
    	dfs(cnt);
    	calout();
    	// cout<<s<<endl;
    }
    return 0;
}