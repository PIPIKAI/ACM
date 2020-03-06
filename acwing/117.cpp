//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=14;
const int inf = 0x3f3f3f3f;
int n,m,f[maxn];
std::vector<int> v[maxn];
int get_id(char x){
	if(x=='A') return 1;
	else if(x=='J') return 11;
	else if(x=='Q') return 12;
	else if(x=='K') return 13;
	else if(x=='0') return 10;
	else return x-'0';
}
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    for(int i=1;i<=13;i++){
    	for(int j=0;j<4;j++){
    		string s;
    		cin>>s;
    		v[i].push_back(get_id(s[0]));
    	}
    }
    for(int i=0;i<4;i++){
    	int k=v[13][i];
    	while(k!=13){
    		f[k]++;
    		int tp=v[k].back();
    		v[k].pop_back();
    		k=tp;
    	}
    }
    int ans=0;
    for(int i=1;i<=13;i++) ans+= f[i] >= 4;
    cout<<ans<<endl;
    return 0;
}