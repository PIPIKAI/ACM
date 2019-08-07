#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
#define Max(x,y) y>x?x=y:x=x
int n,m;
string s;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>s;
    vector<int >  id;
    for(int i=0;i<n;i++){
        if(s[i]=='8'){
            id.push_back(i);
        }
    }
    int step=n-11;
    int sz=id.size();
    step/=2;
    if(step >= sz){
        cout<<"NO"<<endl;
    }
    else{
            //cout<<id[step] - 2*step<<endl;
        (id[step] - 2*step )<=0 ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
    return 0;
}
