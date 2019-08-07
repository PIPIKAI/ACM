#include<bits/stdc++.h>
using namespace std;
struct fff{
    int  time,w;
};
typedef struct fff ff;
bool cmp(ff a,ff b)
{
    if(a.time==b.time)
        return a.w>b.w;
    return a.time < b.time;
}
bool operator<(ff a,ff b){
	if(a.w==b.w) return a.time>b.time;
	return a.w>b.w;
}
int main()
{
    long long sum=0;
    int N;
    cin>>N;
    ff f[50001];
    for(int i=1;i<=N;i++) cin>>f[i].time>>f[i].w;
    sort(f+1,f+N+1,cmp);
    priority_queue <ff> ss;
    int t=0,c=1;
    for(int i=1;i<=N;i++)
    {
        if(f[i].time>=c) {ss.push(f[i]),sum+=f[i].w;/* cout<<": "<<f[i].w<<endl;*/c++;}
        else
        {
            if(f[i].w>ss.top().w)
            {
                ss.push(f[i]),sum-=ss.top().w;sum+=f[i].w;/*cout<<"e: "<<f[j].w<<endl;*/ss.pop();
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
