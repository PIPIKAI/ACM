#include<bits/stdc++.h>
using namespace std;
string f[30];
bool cmp(string a,string b)
{
    return a+b>b+a;
}
int main()
{
    int n=7;
    for(int i=0;i<n;i++)
    cin>>f[i];
    sort(f,f+n,cmp);
    for(int i=0;i<n;i++)
        cout<<f[i];
    return 0;
}
