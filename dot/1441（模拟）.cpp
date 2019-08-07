#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m,cnt;
vector <int> s;
void del(int i)
{
    int t=s[i],v=t;
    while(v<s.size()) v+=t;
    for(v-=t;v>=t;v-=t){
        s.erase(s.begin()+v);
    }
}
void dis()
{
     for(int i=0;i<s.size();i++){
        cout<<s[i]<<" ";
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    s.push_back(0);
    for(int i=1;i<=m;i+=2)
        s.push_back(i);
    for(int i=2;i<s.size();i++){
        del(i);
    }
    //dis();
    for(int i=1;i<s.size();i++)
        if(s[i]>n&&s[i]<m)
        cnt++;
    cout<<cnt<<endl;
    return 0;
}
