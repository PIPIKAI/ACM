#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int n,m;
vector <int > f;
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n,n!=-1)
    {
        for(int i=0;i<n;i++)
        {
            int t;cin>>t;
            if(f.empty())
                f.push_back(t);
            else
            {
                if(t!=f.back())
                    f.push_back(t);
            }
        }
       for(int i=0;i<f.size();i++)
        if(i!=f.size()-1)
        cout<<f[i]<<" ";
       else
        cout<<f[i]<<endl;
       f.clear();
    }
    return 0;
}
