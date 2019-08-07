#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#define INF 0x3f3f3f3f
#define N 100010
/* NO */
using namespace std;
int m;
int a[N];
struct zz
{
	double x,y;
}p[N];
bool cmpxy(zz a,zz b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}
bool cmpy(int a,int b)
{
	return p[a].y<p[b].y;
}
double dis(zz a,zz b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double min_dis(int l,int r)
{
	double d=INF;
	if(l==r)
		return d;
	else if(l+1==r)
		return dis(p[l],p[r]);
	int mid=(l+r)/2;
	d=min(min_dis(l,mid),min_dis(mid+1,r));
	int k=0;
	for(int i=l;i<=r;i++)
	{
		if(fabs(p[i].x-p[mid].x)<=d)
			a[k++]=i;
	}
	sort(a,a+k,cmpy);
	for(int i=0;i<k;i++)
	{
		for(int j=i+1;j<k&&p[a[j]].y-p[a[i]].y<=d;j++)
		{
			double dd=dis(p[a[i]],p[a[j]]);
			d=min(d,dd);
		}
	}
	return d;
}
int main()
{
	while(scanf("%d",&m),m)
	{
		for(int i=0;i<m;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		sort(p,p+m,cmpxy);
		double ans=min_dis(0,m-1)/2.0;
		printf("%.2lf\n",ans);
	}
	return 0;
}
