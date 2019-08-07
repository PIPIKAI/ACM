#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    while(cin>>t)
    {
        bitset<11> q=t;
        int i;
        for( i=10;i>=0;i--)
            if(q[i]!=0)
            break;
        while(i>=0)
        {
            cout<<q[i];
            i--;
        }
        cout<<endl;
    }
    return 0;
}
