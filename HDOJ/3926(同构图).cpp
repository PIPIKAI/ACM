#include<bits/stdc++.h>
using namespace std;
class  Node{
public:
    int c,x;

};
Node f1[10005],f2[10005];
int p[10005];
void ini()
{

    for(int i=0;i<=10005;i++)
    {
        f1[i].c=0;
        f1[i].x=1;
        f2[i].c=0;
        f2[i].x=1;
    }
}
bool cmp(Node a,Node b)
{
    if(a.c==b.c)
        return a.x>b.x;
        return a.c>b.c;
}
int find(int x)
{
    while(x!=p[x])
        x=p[x];
    return x;
}
int mer(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)
        return 0;
    if(a>b)
        p[a]=b;
    if(a<b)
        p[b]=a;
    return 1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int cnt=1, flag=1 ,n1,n2,m1,m2;
        ini();
        cin>>n1>>m1;
        for(int i=1;i<=10005;i++)
            p[i]=i;
        for(int i=0;i<m1;i++)
        {
            int x,y;
            cin>>x>>y;
            x=find(x);
            y=find(y);
            if(x!=y)
            {
                p[y]=x;
                f1[x].x+=f1[y].x;
                f1[y].x=0;
            }
            else
                f1[y].c=1;
        }
        cin>>n2>>m2;
        for(int i=1;i<=10005;i++)
            p[i]=i;
        for(int i=0;i<m2;i++)
        {
            int x,y;
            cin>>x>>y;
             x=find(x);
            y=find(y);
            if(x!=y)
            {
                p[y]=x;
                f2[x].x+=f2[y].x;
                f2[y].x=0;
            }
            else
                f2[y].c=1;
        }
        if(n1!=n2||m1!=m2)
        {
            flag=0;
        }
        else{
            sort(f1+1,f1+1+n1,cmp);
            sort(f2+1,f2+n2+1,cmp);
            for(int i=1;i<=n1;i++)
            {
                if(f1[i].c!=f2[i].c||f1[i].x!=f2[i].x)
                {
                    flag=0;
                    break;
                }
            }
        }
         cout << "Case #" << cnt ++ << ": ";
        if(flag) {
        	cout << "YES" << endl;
        }
        else {
        	cout << "NO" << endl;
        }
    }
    return 0;
}
