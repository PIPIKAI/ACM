#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define mid   (l+r)/2
const int maxn = 1e5+7;
int n,m,cnt,f[maxn],root[maxn];
struct node{
    int l,r,sum;
}T[maxn*40];
vector<int> li;
void built(int &cur,int l,int r){
    cur=++cnt;
    T[cur].sum=0;
    if(l==r) return ;
    built(T[cur].l,l,mid);
    built(T[cur].r,mid+1,r);
}
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
    if(l==r) return T[y].sum-T[x].sum;
    int ans=0;
    if(mid>=k){
        ans+=query(l,mid,T[x].l,T[y].l,k);
    }
    else{
        ans+= T[T[y].l].sum-T[T[x].l].sum ;
        ans+= query(mid+1,r,T[x].r,T[y].r,k);
    }
    return ans;
}
void debug(int rt,int l,int r){
    if(l==r) {
        cout<<l<<" "<<T[rt].sum<<endl;return ;
    }
    debug(T[rt].l,l,mid);
    debug(T[rt].r,mid+1,r);
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T_T=0,ca=0;
    cin>>T_T;
    while(T_T--){
        li.clear();
        cnt=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>f[i];li.push_back(f[i]);
        }
        sort(li.begin(),li.end());
        li.erase(unique(li.begin(),li.end()),li.end());
        built(root[0],1,n);
        for(int i=1;i<=n;i++){
            int x=lower_bound(li.begin(),li.end(),f[i])-li.begin()+1;
            update(1,n,root[i],root[i-1],x);
        }
        // for(int i=0;i<=n;i++){
        //     debug(root[i],1,n);
        // }
        //求l 到 r 里面 大于等于 h 的数的个数
        cout<<"Case "<<++ca<<":"<<endl;
        while(m--){
            int l,r,h;
            cin>>l>>r>>h;
            int k=upper_bound(li.begin(),li.end(),h)-li.begin();
            if(k)
                cout<<query(1,n,root[l],root[r+1],k)<<endl;
            else
                cout<<0<<endl;
            
        }
    }
    return 0;
}
