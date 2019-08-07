#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int main()
{
    std::ios::sync_with_stdio(false);
    string ts,s;
    while(cin>>s)
    {
        ts=s;
        int flag=0;
        do
        {
            if(flag==1)
            {
                flag++;
                cout<<s<<endl;break;
            }
            flag=1;
        }while(next_permutation(s.begin(),s.end()));
        if(flag==1)
        cout<<ts<<endl;
    }
    return 0;
}
