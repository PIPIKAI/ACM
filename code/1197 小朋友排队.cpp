#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
#define Max(x,y) y>x?x=y:x=x
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;
}
#define read(x)  x=read()
struct node{
    int val,id;
};
int n;
node f[100050];
int k[100050];
ll ans=0;
void mm(int l,int m,int r){
    int x=l,y=m,i=m+1,j=r,cnt=0;
    int tp[100050>>1];
    while(x<=y &&i<=j){
        if(f[x].val <= f[i].val){
            x++;
        }
        else{
            i++;
            k[i]+= m-x+1;
        }
    }
}
void msort(int l,int r){
    if(l>=r)
        return ;
    int mid=(l+r)>>1;
    msort(l,mid);
    msort(mid+1,r);
    mm(l,mid,r);
}
int main()
{
    read(n);
    for(int i=0;i<n;i++){
        read(f[i].val);
        f[i].id=i;
    }
    msort(0,n-1);
    cout<<endl;
    cout<<(ans+3)*ans/2<<endl;
    return 0;
}
