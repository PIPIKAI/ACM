#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
int n,m;
int  f[26];
#define LOCAL
int main(int argc, char * argv[]) 
{
    
    #ifdef LOCAL
    // freopen("C:/Users/Administrator/Documents/ACM/code/data.in", "r", stdin);
    //freopen("C:/Users/Administrator/Documents/ACM/code/data.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    string s;
    cin>>s;
    ll ans=0;
    for(int i=0;i<m;i++){
    	char ch;
    	cin>>ch;
    	f[ch-'a']=1; 
    }
    ll len=0;
    for(int i=0;i<s.size();i++){
    	if(f[s[i]-'a']==0){
    		ans+= (1+len)*len/2;
    		len=0;
    	}
    	else{
    		len++;
    	}
    }
    ans+= (ll )(1+len)*len/2;
    cout<<ans<<endl;
    return 0;
}