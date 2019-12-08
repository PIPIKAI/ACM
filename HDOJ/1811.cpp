#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
int n,m;
int f[maxn],a[maxn],b[maxn],d[maxn];
char c[maxn];
queue<int> q;
std::vector<int > mp[maxn];
int tnod;
#define LOCAL
int find(int x){
	while(f[x]!=x){
		x=f[x];
	}
	return x;
}
void merge(int a,int b){
	int fa=find(a);
	int fb=find(b);
	if(fa<fb){
		f[fb]=fa;
		tnod--;
	}
	else if(fa>fb){
		f[fa]=fb;
		tnod--;
	}
}
void init(){
	tnod=n;
	for(int i=1;i<=n;i++){
		f[i]=i;
		mp[i].clear();
		d[i]=0;
	}
}
void topsort(){
	for(int i=1;i<=n;i++){
		if(!d[i]&&find(i)==i)
			q.push(i);
	}
	int flag=0;
	while(!q.empty()){
		int tp=q.front();
		if(q.size()>1) flag=1;
		// cout<<tp<<endl;
		q.pop();
		tnod--;
		for(int i=0;i<mp[tp].size();i++){
			int j=mp[tp][i];
			d[j]--;
			if(!d[j])
				q.push(j);
		}
	}
	// cout<<tnod<<endl;
	if(tnod>0){
		cout<<"CONFLICT"<<endl;
	}
	else if(flag){
		cout<<"UNCERTAIN"<<endl;
	}
	else{
		cout<<"OK"<<endl;
	}
}
int main(int argc, char * argv[]) 
{
    
    #ifdef LOCAL
    // freopen("C:/Users/Administrator/Documents/ACM/code/data.in", "r", stdin);
    //freopen("C:/Users/Administrator/Documents/ACM/code/data.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    while (cin>>n>>m)
    {
    	init();
    	for(int i=0;i<m;i++){
    		cin>>a[i]>>c[i]>>b[i];
    		a[i]++;b[i]++;
    		if(c[i]=='='){
    			merge(a[i],b[i]);
    		}
    	}
    	for(int i=0;i<m;i++){
    		int fa=find(a[i]);
    		int fb=find(b[i]);
    		if(c[i]=='>'){
    			d[fa]++; // 从小的算起，就这样，这题没区别
    			mp[fb].push_back(fa);
    		}
    		else if(c[i]=='<'){
    			d[fb]++;
    			mp[fa].push_back(fb);
    		}
    	}
    	topsort();
    }

    return 0;
}