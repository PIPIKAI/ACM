#include<bits/stdc++.h>
using namespace std;
int f[27];
int main()
{
    string s,en="END";
    while(cin>>s,s!=en)
    {
        int ans=0;
        memset(f,0,sizeof f);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='_')
                f[26]++;
            else
                f[s[i]-'A']++;
        }
        priority_queue <int ,vector <int >,greater <int> >  q;//把小的放在头
        for(int i=0;i<27;i++)
            if(f[i])
            q.push(f[i]);

        while(q.size()>1)
        {
            int a=q.top();q.pop();
            int b=q.top();q.pop();
            int x=a+b;
            q.push(x);
            ans+=x;
        }
        if(ans==0)
            ans=s.length();

       printf("%d %d %.1lf\n",s.length()*8,ans,(s.length()*8.0/ans*1.0));
    }
    return 0;

}
