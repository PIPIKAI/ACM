#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int n,m;
vector<string> f[2000];
map <string ,int > d;
map <string ,int > ppd;
int main()
{
    std::ios::sync_with_stdio(false);
    string name;
    while(cin>>n>>name)
    {
        int cnt=0;
        d[name]=cnt++;
        for(int i=0;i<n;i++)
        {
            string ts,tname,tson;
            cin>>ts;
            if(ts=="birth")
            {
                cin>>tname>>tson;
                if(d[tname]!=0)
                {
                    d[tname]=cnt++;
                }
                int id=d[tname];
                f[id].push_back(tson);
            }
            if(ts=="death")
            {
                cin>>tname;
                ppd[tname]=1;
            }
        }
        for(int i=1;i<cnt;i++)
        {
            for(int j=0;j<f[i].size();j++)
            {
                string ts=f[i][j];
                if(!ppd[ts])
                {
                    cout<<ts<<endl;
                }
            }
        }
    }
    return 0;
}
