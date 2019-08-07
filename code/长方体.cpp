#include<iostream>
using namespace std;
typedef long long ll;
int dfs(int a,int b,int c)
{
    int i;
    for( i=1;i<=10000;i++)
    {
        int j=a/i;
        int k=b/i;
        if(j*k==c&&i*k==b&&i*j==a)
            return (i+j+k)*4;
    }
    return 0;
}
int main()
{
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        cout<<dfs(a,b,c)<<endl;
    }
    return 0;
}
