#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    while(n--){
        string s,t,p;
        int st[27],tt[27],pt[27];
        mem(st,0);mem(tt,0);mem(pt,0);
        cin>>s>>t>>p;
        for(int i=0;i<s.size();i++){
            st[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++){
            tt[t[i]-'a']++;
        }
        for(int i=0;i<p.size();i++){
            pt[p[i]-'a']++;
        }
        int flag;
        int cnt=0;
        for(int i=0;i<t.size();i++){
            if(s[cnt]==t[i]){
                cnt++;
            }
        }
        if(cnt==s.size()){
            flag=1;
        }
        else{
            flag=0;
        }
        for(int i=0;i<26;i++){
            if(tt[i] >st[i]+pt[i])
            {
                flag=0;break;
            }
        }
        flag ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
    return 0;
}
