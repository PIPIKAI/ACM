#include<bits/stdc++.h>
using namespace std;
int d[60];
vector <int >f[30];
char ans[30],cnt;
int topsort()
{
    cnt=0;
    int cc=0;
    queue<int > q,ans;
        for(int i=0;i<n;i++)
            if(d[i]==0)
            q.push(i),cc++;
            if(cc>1)
                return 0;
        while(!q.empty())
        {
            int t=q.front();
            char ss=t+'A';
            if(ss!=ans[cnt++])
                {
                    ans[cnt-1]=ss;
                    return -1;
                }

            q.pop();
            for(int i=t;i<f[t].size();i++)
            {
                int j=f[t][i];
                d[j]--;
                if(d[j]>0)
                    q.push(j);
            }
        }
    if(cnt<n)
        return -1;
    return 1;
}
int main()
{
    int n,m;
    while(cin>>n>>m,n!=0&&m!=0)
    {
        bool isci=0,dif=0,canot=0;
        int dddd=0;
         memset(d,0,sizeof d);
        memset(f,0,sizeof f);
        for(int i=0;i<m;i++)
        {
            char a,c,b;
            cin>>a>>c>>b;
            if(canot||isci||dif)
                continue;
            if(c=='>')
                swap(a,b);
            int aa=a-'A';
            int bb=b-'A';
            for(int j=0;j<f[bb].size();j++)
            {
                if(f[bb][j]==aa)
                {
                    isci=1;
                    break;
                }
            }
            f[aa].push_back(bb);
            int flla=topsort();
            if(flla==-1)
            {
                dddd=i+1;
                dif=1;
            }
            else if(flla==0)
            {
                canot=1;
            }
            d[bb]++;
        }
        if(isci)
            cout<<"Inconsistency found after "<<dddd<<" relations."<<endl;
        else if(canot)
            cout<<"Sorted sequence cannot be determined."<<endl;
            else
                cout<<"Sorted sequence determined after 4 relations: "<<ans<<"."<<endl;
    }
    return 0;
}
