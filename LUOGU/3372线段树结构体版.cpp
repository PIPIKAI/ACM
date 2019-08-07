#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
inline int ls(int p){return p<<1;}///�����
inline  int rs(int p){return p<<1|1;}///�Ҷ���
const int maxn=100011;
int n,m,f[maxn];
struct node
{
    int l,r;
    ll p,add;
}t[maxn*4];
/// �����
void spread(int p)
{
    if(t[p].add)
    {
        t[ls(p)].p+=t[p].add*(t[ls(p)].r-t[ls(p)].l+1);
        t[rs(p)].p+=t[p].add*(t[rs(p)].r-t[rs(p)].l+1);
        ///�´�
        t[ls(p)].add+=t[p].add;///�����Ҷ��Ӵ��������
        t[rs(p)].add+=t[p].add;
        t[p].add=0;///�´�֮�󽫸ýڵ���������0
    }
}
/// �����޸�
void change(int p,int x,int y,ll z)
{
    if(x<=t[p].l&&y>=t[p].r)///�����ǵĻ����Ͷ�������޸�
    {
        t[p].p+=z*(t[p].r-t[p].l+1);
        t[p].add+=z;
        return ;
    }
    spread(p);///�������û�б����ǣ��Ǿ���Ҫ���������ң�
    ///���Ƕ�����ά�������������Ϊ����ǵĴ��ڶ�û���޸ģ���˽�������·�
    int mid=((t[p].l+t[p].r)>>1);
    if (x<=mid) change(ls(p),x,y,z);
    if (y>mid) change(rs(p),x,y,z);
    t[p].p=t[ls(p)].p+t[rs(p)].p;///
}
void built(int p,int l,int r)
{
    t[p].l=l,t[p].r=r;
    if(l==r)
    {
        t[p].p=f[l];return ;
    }
    int mid=(l+r)>>1;
    built(ls(p),l,mid);
    built(rs(p),mid+1,r);
    t[p].p=t[ls(p)].p+t[rs(p)].p;
}
ll ask(int p,int x,int y)
{
    if(x<=t[p].l&&y>=t[p].r) return t[p].p;
    spread(p);///�´�����ǣ�����ѯ���Ҷ���
    int mid=((t[p].l+t[p].r)>>1);
    ll ans=0;
    if (x<=mid) ans+=ask(ls(p),x,y);
    if (y>mid) ans+=ask(rs(p),x,y);
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>f[i];
    built(1,1,n);
    while(m--)
    {
        int flag,x,y,k;
        cin>>flag;
        if(flag==1)
        {
            cin>>x>>y>>k;
            change(1,x,y,k);
        }
        else
        {
            cin>>x>>y;
            cout<<ask(1,x,y)<<endl;
        }
    }
    return 0;
}
