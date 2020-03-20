//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
map<ll,char> lcmp;
map<char,ll> clmp;
#define lll __int128_t
void init(){
	int cnt=0;
	for(int i=0;i<10;i++) lcmp[cnt]='0'+i , clmp[char(i+'0')]= cnt++ ;
		for(int i=0;i<26;i++) lcmp[cnt]='A'+i , clmp[char(i+'A')]= cnt++ ;
			for(int i=0;i<26;i++) lcmp[cnt]='a'+i , clmp[char(i+'a')]= cnt++ ;
}
lll toten(string s, ll n){
	lll mul=1,sum=0;
	for(int i=s.size()-1;i>=0;i--){
		sum+= clmp[s[i]]*mul;
		mul*=n;
	}
	return sum;
}
string tento(lll s,ll n){
	string res="";
	while(s){
		int tp= s%n;
		res=lcmp[tp]+res;
		s/=n;
	}
	return res;
}
string solve(int A,int B,string s){
	lll tp= toten(s,A);
	return tento(tp,B);
}
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    init();
    int T,A,B;
    string s;
    cin>>T;
    while(T--){
    	cin>>A>>B>>s;
    	cout<<A<<" "<<s<<endl;
    	cout<<B<<" "<<solve(A,B,s)<<endl<<endl;
    }
    return 0;
}