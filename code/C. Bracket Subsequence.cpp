#include<bits/stdc++.h>
using namespace std;
bool flag[200001]={0};
stack<char > q;
stack <int > qq;
int main()
{
    string s,ans;
    int n,m;
    while(cin>>n>>m)
    {
        memset(flag,0,sizeof(flag));
        int j=0,ff=0;
        cin>>s;
        for(int i=0;i<n;i++)
        {
            if(ff>=m)
                break;
           if(s[i]=='(')
           {
               q.push('(');
               qq.push(i);
           }
           else
           {
               q.pop();
               int j=qq.top();
               flag[j]=1;
               qq.pop();
               flag[i]=1;
               ff+=2;
           }
        }
        for(int i=0;i<n;i++)
        {
            if(flag[i])
                cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}
/*

8 4
(()(()))

*/
