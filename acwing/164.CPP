//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=3e4+7;
const int inf = 0x3f3f3f3f;
int n,m;
struct node{
	int next,to;
}e[maxn];
bitset<maxn> f[maxn];
int seq[maxn],head[maxn],cnt,d[maxn];
void add(int from, int to) {
    e[++cnt].next = head[from];
    e[cnt].to = to;
    head[from] = cnt;
}
void topsort(){
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(d[i] ==0 ){
			q.push(i);
		}
	}
	int k=0;
	while(q.size()){
		int tp=q.front();
		q.pop();
		seq[k++]=tp;
		for(int i=head[tp];i;i=e[i].next){
			int y=e[i].to;
			if(0== --d[y]){
				q.push(y);
			}
		}
	}
}
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int x,y,i=0;i<m;i++){
    	cin>>x>>y;
    	add(x,y);
    	d[y]++;
    }
    topsort();
    for(int i=n-1;i>=0;i--){
    	int x=seq[i];
    	f[x][x]=1;
    	for(int j=head[x];j;j=e[j].next){
    		f[x]|=f[e[j].to];
    	}
    }
    for(int i=1;i<=n;i++){
    	cout<<f[i].count()<<endl;
    }
    return 0;
}