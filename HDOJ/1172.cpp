#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int a,b;
    string s;
}f[101];
int ans;
int a,b;
int h[11]={0},flag;
int juge(int k,int t)
{

    for(int i=0;i<t;i++)
    {
        int ka[10]={0},kb[10]={0};
        int aa=0,bb=0;
        string  a;
        a[0]=k/1000+'0',a[1]=k/100%10+'0',a[2]=k/10%10+'0',a[3]=k%10+'0';
        for(int j=0;j<4;j++)
        {
            ka[a[j]-'0']++;
            kb[f[i].s[j]-'0']++;
            if(f[i].s[j]==a[j])
                bb++;
        }
//cout<<bb<<endl;
        if(bb!=f[i].b)
            return 0;

        for(int j=0;j<10;j++)
        {
            if(ka[j]!=0&&kb[j]!=0)
            {
                while(1)
                {
                    if(ka[j]==0||kb[j]==0)
                        break;
                    ka[j]--,kb[j]--;
                    aa++;
                }
            }
        }
       //cout<<aa<<endl;
        if(aa!=f[i].a)
            return 0;
    }
    return 1;
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	int t;
	while(cin>>t,t!=0)
    {
        int sum=0;
       for(int i=0;i<t;i++)
        {
            cin>>f[i].s>>f[i].a>>f[i].b;
        }
        for(int i=1000;i<10000;i++)
        {
            if(juge(i,t))
            {
                ans=i;
                sum++;
            }
        }

       if(sum==1)
       {
           cout<<ans<<endl;
       }
       else
            cout<<"Not sure"<<endl;
    }
   return 0;
}
