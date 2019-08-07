#include<iostream>
using namespace std;
int main()
{
    int n,sum=0,temp=0,bei_cheng;
    cin>>n;
    int f[n];
    int i;
    for(i=0;i<n;i++)
    {
        cin>>f[i];
        if(f[i]>temp)
        {
            bei_cheng=6;
            sum+=bei_cheng*(f[i]-temp)+5;

        }
        else if(f[i]<temp)
        {
            bei_cheng=4;
            sum+=bei_cheng*(temp-f[i])+5;
        }
        else
        {
            sum+=5;
        }
        temp=f[i];

    }
    cout<<sum<<endl;

    return 0;
}
