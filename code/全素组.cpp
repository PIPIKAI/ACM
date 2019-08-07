#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int p[10030];
int book[3030];
void inti(int n)
{
    memset(p,1,sizeof(p));
    p[1]=0;
    for(int i=2;i<3*n;i++)
        if(p[i])
    {
        for(int j=2;j*i<=3*n;j++)
            p[i*j]=0;
    }
}
int main()
{

    int n,sum=0,maxn=0;
    cin>>n;
    inti(n);
    int t=0;
    int a,b,c;
    for(int i=1;i<=n;i++)
        if(p[i])
        book[t++]=i;

    for(int i=0;i<t-2;i++)
    {
        for(int j=i+1;j<t-1;j++)
        {
            for(int k=j+1;k<t;k++)
            {
                if(p[book[i]+book[j]+book[k]])
                {
                    sum++;
                    if(maxn<book[i]+book[j]+book[k])
                    {
                        a=book[i],b=book[j],c=book[k];
                        maxn=a+b+c;
                    }
                   // cout<<a<<" "<<b<<" "<<c<<endl;
                  //  if(sum=46662)
                    {
                      //  cout<<sum<<endl<<a<<" "<<b<<" "<<c<<endl;
                      //  return 0;
                    }

                }

            }
        }
    }
    cout<<sum<<endl<<a<<" "<<b<<" "<<c<<endl;


    return 0;
}
