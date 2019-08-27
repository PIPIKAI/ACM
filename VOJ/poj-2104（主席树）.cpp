#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define mid   (l+r)/2
const int maxn = 1e5+7;
int n,m,k,x,y,cnt,f[maxn],root[maxn];
struct node{
    int l,r,sum;
}T[maxn*40];
vector<int> li;
void update(int l,int r,int &x,int y,int pos){
    T[++cnt]=T[y];T[cnt].sum++,x=cnt;
    if(l==r) return ;
    if(mid>= pos){
        update(l,mid,T[x].l,T[y].l,pos);
    }
    else{
        update(mid+1,r,T[x].r,T[y].r,pos);
    }
}
int query(int l,int r,int x,int y,int k){
    if(l==r) return l;
    int sum=T[T[y].l].sum-T[T[x].l].sum;
    if(sum>=k){
        return query(l,mid,T[x].l,T[y].l,k);
    }
    else{
        return query(mid+1,r,T[x].r,T[y].r,k-sum);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            cin>>f[i];li.push_back(f[i]);
        }
        sort(li.begin(),li.end());
        li.erase(unique(li.begin(),li.end()),li.end());
        for(int i=1;i<=n;i++){
            int x=lower_bound(li.begin(),li.end(),f[i])-li.begin()+1;
            update(1,n,root[i],root[i-1],x);
        }
        while(m--){
            int l,r,k;
            cin>>l>>r>>k;
            cout<<li[query(1,n,root[l-1],root[r],k)-1]<<endl;
        }
    }
    return 0;
}