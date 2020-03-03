//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
int n,m,a,b;
struct node{
	int l, r;
};
node f[maxn];
bool cmp(node a,node b){
	return a.l*a.r < b.r*b.l;
}
vector<int> max_vec(vector<int> a,vector<int > b){
    if(a.size()> b.size() ){
        return a;
    }
    if(b.size() > a.size()){
        return b;
    }
    if( vector<int> (a.rbegin(),a.rend()) > vector<int> (b.rbegin(),b.rend()) ){
        return a;
    }
    else{
        return b;
    }
}
void output(vector<int> tp){
    for(int i=tp.size()-1;i>=0;i--){
        cout<<tp[i];
    }
    cout<<endl;
}
vector<int> mul(vector<int > a,int b){
    int j=0;
    std::vector<int> res;
    for(auto i: a){
        j=i*b+j;
        res.push_back(j%10);
        j=j/10;
    }
    while(j){
        res.push_back(j%10);
        j/=10;
    }
    return res;
}
vector<int> div(vector<int > a,int b){
    std::vector<int > res;
    bool is_first=true;
    for(int i=a.size()-1,t=0;i>=0;i--){
        t=t*10+a[i];
        int x=t/b;
        if(!is_first || x){
            is_first=false;
            res.push_back(x);
        }
        t%=b;
    }
    reverse(res.begin(),res.end());
    return res;
}
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<=n;i++){
    	cin>>f[i].l>>f[i].r;
    }
    sort(f+1,f+n+1,cmp);
    std::vector<int> ans(1,0),sl(1,1);
    for(int i=0;i<=n;i++){
    	ans=max_vec(ans,div(sl,f[i].r));
        sl=mul(sl,f[i].l);
    }
    output(ans);
    return 0;
}