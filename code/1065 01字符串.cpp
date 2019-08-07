#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main()
{
    int n,i,j,k,flag;
    long long sum=0;
    char s[50];
    cin>>n;
    if(!n)
    {
        cout<<0<<endl;
        return 0;
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<i;j++)
            s[j]='0';
            for(k=i;k<n;k++)
                s[k]='1';
                s[n]='\0';
            do{
                   // cout<<s<<endl;
                    flag=1;
                for(k=1;k<n;k++)
                {
                    if(flag==3)
                        break;
                    if(s[k]==s[k-1])
                    flag++;
                    else
                        flag=1;
                }
                if(flag!=3)
                {
                    sum++;
                    cout<<s<<endl;
                }


            }while(next_permutation(s,s+n));
    }
    cout<<sum<<endl;
    return 0;
}
