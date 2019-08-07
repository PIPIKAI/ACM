#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    string s;
    cin>>n>>k>>s;
    int cnt=0,ans=0;
    char t='\0';
    sort(s.begin(),s.end());
    for(int i=0;i<n;i++)
    {
        if(t+1!=s[i]&&t!=s[i])
        {
            t=s[i];
           // cout<<s[i]<<" ";
            ans+=s[i]-'a'+1;
            cnt++;
        }
        if(cnt>=k)
            break;
    }
    if(cnt<k)
        cout<<"-1"<<endl;
    else
        cout<<ans<<endl;
    return 0;
}
