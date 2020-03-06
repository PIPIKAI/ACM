//#pragma comment(linker, "/STACK:1024000000,1024000000")
/*
思路，用二进制来枚举所有按开关的情况
+ 为1，要求吧开关全部变成0
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
int n,m,change[5][5];
int now=0;
int get_id(int x,int y){
	return x * 4 + y;
}
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    for(int i=0;i<4;i++){
    	string s;
    	cin>>s;
    	for(int j=0;j<4;j++){
    		if(s[j] == '+'){
    			now += 1 << get_id(i,j);
    		}
    		for(int k=0;k<4;k++){
    			change[i][j]+= 1<<get_id(i,k);
    			change[i][j]+= 1<<get_id(k,j);
    		}
    		change[i][j] -= 1<<get_id(i,j);
    	}
    }
    
    std::vector<pii> res;
    for(int k=0;k < 1<<16; k++){
    	int vv=now;
    	std::vector<pii> path;
    	for(int i=0;i<16;i++){
    		if(k >> i & 1){
    			int x=i/4 ,y= i%4;
    			vv ^= change[x][y];
    			path.push_back({x,y});
    		}
    	}
    	if(vv == 0 &&( res.empty() || path.size() < res.size())){
    		res=path;
    	}
    }
    cout<<res.size()<<endl;
    for(auto i : res) cout<<i.first+1<<" "<<i.second+1<<endl;
    return 0;
}