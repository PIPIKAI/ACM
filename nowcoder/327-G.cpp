#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
string s,b;
int flag=0,difference_length=0,difference_word=0;
void dfs(int step, string s);
void change1(string s,int step,char cc,int in)
{

}
void change2(string s,int step)
{
    string ts;
    for(int i=0;i<=s.size();i++)
    {
        for(int j='a';j<='z';j++)
        {
            ts=s;
            ts.insert(i,1,char(j));
            dfs(step+1, ts );
        }
    }
}
void dfs(int step,string now)
{
    if(flag)
        return ;
    if(step>=2)
    {
        //cout<<now<<endl;
        if(now==b)    flag=1;
        return ;
    }
    string ts;
    for(int i=0;i<now.size();i++)
    {
        if(now[i]!=b[i])
        {
            if(now.size()>b.size())
            {
                ts=now;
                ts.erase(ts.begin()+i,ts.begin()+i+1);
                dfs(step+1, ts );
            }
            else if(now.size()<b.size())
            {
                ts=now;
                ts.insert(i,1,char(b[i]));
                dfs(step+1, ts );
            }
            else
            {
                ts=now;
                ts[i]=b[i];
                dfs(step+1,ts);

                ts=now;
                ts.erase(ts.begin()+i,ts.begin()+i+1);
                dfs(step+1, ts );

                ts=now;
                ts.insert(i,1,char(b[i]));
                dfs(step+1, ts );

            }
        }
        else
        {
                ts=now;
                if(i>0)
                ts[i]=b[i-1];
                else
                ts[i]=b[i+1];
                dfs(step+1,ts);

                ts=now;
                ts.erase(ts.begin()+i,ts.begin()+i+1);
                dfs(step+1, ts );

                ts=now;
                ts.insert(i,1,char(b[i]));
                dfs(step+1, ts );
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>s>>b;
    if(s==b)
        flag=1;
    if(abs(s.size()-b.size())>2)
        return cout<<"NO"<<endl,0;
    dfs(0,s);
    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
/**
1 1
长度一样，并且有两个不同字母
2 2
3 3
1 2
长度长一，并且有两个不同字母
1 3
长度短一，有一个或零个不同字母
2 3
长度一样，有0个或1个不同字母
*/
