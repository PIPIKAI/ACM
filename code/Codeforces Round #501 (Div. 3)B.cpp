#include<bits/stdc++.h>
using namespace std;
int len,flag;
int ans[10005],cnt=0;
char s1[5001],s2[5001];
int main()
{
    cin>>len>>s1>>s2;
    int i,j,k;
    flag=1;
    for( i=0;i<len;i++)
    {
        for( j=i;j<len;j++)
        {
            if(s2[i]==s1[j]&&i!=j)
            {
                for( k=j;k>i;k--)
                {
                    swap(s1[k-1],s1[k]);
                    ans[cnt++]=k;
                }
                break;
            }
        }
        if(j==len&&s1[i]!=s2[i])
        {
             flag=0;break;
        }
    }
    if(flag)
    {
        cout<<cnt<<endl;
        for(int i=0;i<cnt;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    else
        cout<<"-1"<<endl;
    return 0;
}

