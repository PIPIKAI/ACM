#include<bits/stdc++.h>
using namespace std;
#define inf 1e7
int n,m,vis1[105],vis2[105],cna,cnb,flag,aa[105],naa,bb[105],nbb;
struct node{
	int a,b,w,vv;
	char c;
}f[105];
bool juge(int vis[])
{
    int s=0;
    for(int i=1;i<=n;i++)
        if (vis[i]==i)
            s++;
  if(s==1)
    return 1;
  else
    return 0;
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
void init(int vis[])
{
    for(int i=0;i<=n;i++)
        vis[i]=i;
}
int find(int x,int vis[])
{
    int r=x,i=x,j;
    while(vis[r]!=r)
       r=vis[r];
    while(r!=i)
    {
        j=vis[i];
        vis[i]=r;
        i=j;
    }
    return r;
}
int merg(int a,int b,int vis[])
{
    a=find(a,vis);
    b=find(b,vis);
    if(a==b)
        return 0;
    if(a>b)
         vis[a]=b;
    if(a<b)
        vis[b]=a;
    return 1;
}
int kusal()
{
    int ans1=0,ans2=0;
    naa=nbb=0;
    queue< int >  f1,f2;
    init(vis1);
    init(vis2);
    for(int i=0;i<m;i++)
   {
       if(f[i].c=='R')
        if(merg(f[i].a,f[i].b,vis1))
            {
                f1.push(i);ans1+=f[i].w;
                aa[naa++]=ans1;
            }
        if(f[i].c=='B')
        if(merg(f[i].a,f[i].b,vis2))
        {
            f2.push(i);ans2+=f[i].w;
            bb[nbb++]=ans2;
        }
       if(f[i].c=='G')
       {
           if(merg(f[i].a,f[i].b,vis1))
            {
                f1.push(i);ans1+=f[i].w;
                aa[naa++]=ans1;
            }
            if(merg(f[i].a,f[i].b,vis2))
            {
                f2.push(i);ans2+=f[i].w;
                bb[nbb++]=ans2;
            }
       }
   }
   if(!juge(vis1))
    ans1=inf;
   if(!juge(vis2))
    ans2=inf;
    if(ans1==inf&&ans2==inf)
       flag=0;
   if(ans1<ans2)
   {
       while(!f1.empty())
       {
           f[f1.front()].vv=1;
           f1.pop();
       }
   }
   if(ans1>ans2)
   {
        while(!f2.empty())
       {
           f[f2.front()].vv=1;
           f2.pop();
       }
   }
   if(ans1==ans2&&ans1!=inf)
   {
   		flag=3;
   		
	} 
   return min(ans1,ans2);
}
int findmin()
{
    for(int i=0;i<m;i++)
    {
        if(0==f[i].vv)
            {
                f[i].vv=1;
                return f[i].w;
            }
    }
}
int fuu(int i)
{
	if(aa[i]<bb[i])
	return aa[i];
	else
	return bb[i];
}
int main()
{
    int t,cnt;
    ios::sync_with_stdio(false);cin.tie(0);
	cin>>t;
	cnt=1;
	while(t--)
	{
	    flag=1;
		memset(f,0,sizeof(f));
		cin>>n>>m;
		for(int i=0;i<m;i++)
        {
            node t;
            cin>>t.a>>t.b>>t.w>>t.c;
            f[i]=t;f[i].vv=0;
        }
		sort(f,f+m,cmp);
		int sum=kusal();
		cout<<"Case #"<<cnt<<":"<<endl;cnt++;
		if(n==1&&m==0)
            cout<<"0"<<endl;
        
		for(int i=1;i<=m;i++)
		{
			if(i<n-1)
			cout<<"-1"<<endl;
			else
            {
                if(flag==0)
                    cout<<"-1"<<endl;
                else 
                {
                    if(i==n-1)
                        cout<<sum<<endl;
                    else
                    {
                    	if(flag==3)
                    	cout<<sum+fuu(i-n)<<endl;
						else
						{
						sum+=findmin();
                    	cout<<sum<<endl;
						 } 
						
                    }

                }
            }
		}
	}
	return 0;
}
