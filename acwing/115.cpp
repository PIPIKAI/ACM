//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=2e3+7;
const int inf = 0x3f3f3f3f;
int n,root;
struct node
{
	int father,sum,size;
	double var;
}tree[maxn];
int find(){
	double tp=0;
	int res=-1;
	for(int i=1;i<=n;i++){
		if(i!= root && tp< tree[i].var){
			tp=tree[i].var;
			res=i;
		}
	}
	return res;
}
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    cin>>n>>root;
    int res=0;
    for(int i=1;i<=n;i++){
    	cin>>tree[i].sum;
    	tree[i].var=tree[i].sum;
    	tree[i].size=1;
    	res+=tree[i].sum;
    }
    for(int i=0,x,y;i<n-1;i++){
       	cin>>x>>y;
       	tree[y].father=x;
    }
    for(int i=0;i<n-1;i++){
    	int son=find();
    	int father=tree[son].father;
		res+= tree[son].sum * tree[father].size;
    	tree[son].var=-1;
    	for(int j=1;j<=n;j++){// 缩点
    		if(tree[j].father==son){
    			tree[j].father=father;
    		}
    	}
    	tree[father].size+=tree[son].size;
    	tree[father].sum+=tree[son].sum;
    	tree[father].var=(double )tree[father].sum/tree[father].size;
    }
    cout<<res<<endl;
    return 0;
}