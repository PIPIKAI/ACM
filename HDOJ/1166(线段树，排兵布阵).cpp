#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l,r,num;
};
node f[200080];
int a[50000];
int build(int root,int l,int r)
{
    f[root].l=l;
    f[root].r=r;
    if(l==r)
        return f[root].num=a[l];
    int m=(l+r)/2;
    return f[root].num=build(root*2,l,m)+build(root*2+1,m+1,r);
}
int query(int root,int l,int r)
{
    int m=(f[root].l+f[root].r)/2;
    if(f[root].l==l&&f[root].r==r)
        return f[root].num;
    if(r<=m)
        return query(root*2,l,r);
    if(l>m)
        return query(root*2+1,l,r);
    return query(root*2,l,m)+query(root*2+1,m+1,r);
}
void update(int root,int x,int y)
{
    f[root].num+=y;
    if(f[root].r==f[root].l)
        return ;
    int m=(f[root].l+f[root].r)/2;
    if(x<=m)
        update(root*2,x,y);
    else
        update(root*2+1,x,y);
}
int main()
{
	int t,p=1;
	scanf("%d",&t);
	while(p<=t)
    {
        int n;
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        build(1,1,n);
        printf("Case %d:\n",p);
        p++;
        char j[5];
        while(scanf("%s",j),j[0]!='E')
        {
            if(j[0]=='Q')
            {
                int l,r;
                scanf("%d%d",&l,&r);
                printf("%d\n",query(1,l,r));
            }
            if(j[0]=='A')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                update(1,x,y);
            }
            if(j[0]=='S')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                update(1,x,-y);
            }
        }
    }
	return 0;
 }
