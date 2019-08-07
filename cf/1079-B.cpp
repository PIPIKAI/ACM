#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int main()
{
    std::ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int l=s.size();
    int n=(l+19)/20;
    int m=( l +n-1)/n;
    int st= n*m-l;
    cout<<n<<" "<<m<<endl;;
    for(int i=0;i<l;)
    {
        if(st>0)
        {
            cout<<"*";
            st--;
            for(int j=0;j<m-1;j++)
                cout<<s[i++];
        }
        else{
            for(int j=0;j<m;j++)
                cout<<s[i++];
        }
        cout<<endl;
    }
    return 0;
}
