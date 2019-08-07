#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
    queue<char> q;
    char c;
    while(cin>>c,c!='@')
    {
        if(c=='('||c==')')
        {
            if(q.empty())
            q.push(c);
            else
            {
                char t=q.front();
                if(c==')'&&t=='(')
                {
                    q.pop();
                }
                else
                    q.push(c);
            }


        }
    }
    if(q.empty())
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
   return 0;
}
