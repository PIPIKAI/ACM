#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int ans[2000],cnt=0;
    memset(ans,0,sizeof ans);
    string s1,s2;
    while(cin>>n)
    {
        vector<char > q;
        cnt=0;
        cin>>s1>>s2;
        int i=0,j=0;
        while(i<=n)
        {
            if(q.size()==0)
            {
                ans[cnt++]=1,q.push_back(s1[i++]);
            }
            else
            {
                char c=q.back();
                if(c==s2[j])
                ans[cnt++]=0,q.pop_back(),j++;
                else
                ans[cnt++]=1,q.push_back(s1[i++]);
            }

        }
        if(j==n)
        {
            cout<<"Yes."<<endl;
            for(int i=0;i<cnt-1;i++)
                if(ans[i])
                cout<<"in"<<endl;
                else
                cout<<"out"<<endl;
        }
        else
        {
            cout<<"No."<<endl;
        }
        cout<<"FINISH"<<endl;
    }
    return 0;
}


