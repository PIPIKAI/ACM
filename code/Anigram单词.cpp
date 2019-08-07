#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin>>n;
    map <string , int > map1,map2;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        map1[s]++;
        sort(s.begin(),s.end());
        map2[s]++;
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        string s,ss;
        cin>>s;
        int a=map1[s];
        sort(s.begin(),s.end());
        int b=map2[s];
        cout<<b-a<<endl;
    }
    return 0;
}
