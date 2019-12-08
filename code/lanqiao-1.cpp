#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int inf = 0x3f3f3f3f;
const int maxn=1e4+7;
#define LOCAL
ll er_s(string s){
	ll ans=0,tp=1;
	for(int i=s.size()-1;i>=0;i--){
		ans+=tp*(s[i]-'0');
		tp=tp*2;
	}
	return ans;
}
string bin(int s){
	string ans="";
	while(s){
		char c= (s%2)+'0';
		ans=c+ans;
		s/=2;
	}
	return ans;
}
bool juge(int x){
	while(x){
		if(x%10==9){
			return 1;
		}
		x/=10;
	}
	return 0;
}
int main(int argc, char * argv[]) 
{
    
    #ifdef LOCAL
    freopen("C:/Users/Administrator/Documents/ACM/code/data.in", "r", stdin);
    //freopen("C:/Users/Administrator/Documents/ACM/code/data.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    int n,ans=0;
    string s="11110011101";
    string y="1111101001";
    int sum=er_s(y)+er_s(s);
    for(int i=1;i<=2019;i++){
    	if(juge(i)){
    		ans++;
    	}
    }
    cout<<ans<<endl;

    return 0;
}