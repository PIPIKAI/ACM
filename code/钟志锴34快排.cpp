#include<iostream>
using namespace std;
void qsort(int f[],int l,int r)
{
    int tl=l;
    int b=f[l];
    if(l<r)
    {
        cout<<l<<" "<<r<<endl;
        for(int i=l+1;i<=r;i++)
        {
            if(f[i]<b)
            {
                swap(f[++tl],f[i]);
            }
        }
        swap(f[tl],f[l]);
        qsort(f,l,tl-1);
        qsort(f,tl+1,r);
    }
}
int main()
{
    int f[10000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>f[i];
    qsort(f,0,n-1);
    for(int i=0;i<n;i++)
        cout<<f[i]<<" ";
    cout<<endl;
    return 0;
}
