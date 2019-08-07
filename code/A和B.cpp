#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int juge,big,small;
    string a,b;
    while(cin>>a>>b)
    {
        if(a[0]=='-')
        {
            if(b[0]=='-')
            {
                big=1;
                small=-1;
            }
            else
                {
                    cout<<"<"<<endl;
                    continue;
                }
        }
        else
        {
            if(b[0]=='-')
            {
                cout<<">"<<endl;
                continue;

            }
            else
            {
                big=-1;
                small=0;
            }
        }
        int anod,bnod;
        int alen=a.size(),blen=b.size();
        for(int i=a.size()-1,flag=0;i>0;i--)
        {
            if(a[i]=='.')
            {
                anod=alen-i;
                break;
            }
            if(flag)
               if(a[i]=='0')
                {
                    a.erase(i);
                }
                else
                {
                    flag=0;
                }
        }
        for(int i=b.size()-1,flag=1;i>0;i--)
        {
            if(b[i]=='.')
            {
                bnod=blen-i;
                break;
            }
            if(flag)
               if(b[i]=='0')
                {
                    b.erase(i);
                }
                else
                {
                    flag=0;
                }

        }
        //cout<<a<<" "<<b<<endl;
        if(a==b)
        {
            cout<<"="<<endl;
            continue;
        }
        for(int i=0;i<a.size();i++)
            if(a[i]=='.')
            {
                anod=i;
                break;
            }
        for(int i=0;i<b.size();i++)
            if(b[i]=='.')
            {
                bnod=i;
                break;
            }
        if(anod>bnod)
            juge=big;
        else if(anod<bnod)
            juge=small;
        else
        {
            int i;
            for( i=0;i<anod;i++)
            {
                int l=a[i]-'0';
                int ll=b[i]-'0';
                if(l>ll)
                    juge=big;
                else if(l<ll)
                juge=small;
            }
            int j;
            if(i==anod)
            for( j=i+1;j<a.size()&&j<b.size();j++)
            {
                int l=a[i]-'0',ll=b[i]-'0';
                if(l>ll)
                    juge=big;
                else if(l<ll)
                    juge=small;
            }
            if(j==a.size())
                juge=small;
            else if(j==b.size())
                juge=big;
        }
        if(juge==1)
            cout<<">"<<endl;
        else
            cout<<"<"<<endl;
    }
    return 0;
}
