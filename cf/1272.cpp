#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstdio>
using namespace std;
const int maxn=1e5+10;
int a[maxn];
int main()
{
    int t ;
    cin>>t;
    while(t--){
        string s;
        memset(a,0,sizeof(a));
        cin>>s;
        for(int i=0;i<s.length();i++){
            if(s[i]=='L')a[0]++;
            else if(s[i]=='R')a[1]++;
            else if(s[i]=='U')a[2]++;
            else a[3]++;
        }
        int minn=100000;
        for(int i=0;i<2;i++){
            minn=min(minn,a[i]);
        }
        int minn1=100000;
        for(int i=2;i<4;i++){
            minn1=min(minn1,a[i]);
        }
        if(a[0]==0||a[1]==0){
            if(minn1>=1){
                cout<<"2"<<endl<<"UD"<<endl;
            }
            else cout<<"0"<<endl;
            continue;
        }
        if(a[2]==0||a[3]==0){
            if(minn>=1){
                cout<<"2"<<endl<<"RL"<<endl;
            }
            else cout<<"0"<<endl;
            continue;
        }
        cout<<2*minn+2*minn1<<endl;
        for(int i=0;i<minn1;i++){
            cout<<"U";
        }
        for(int i=0;i<minn;i++){
            cout<<"R";
        }
        for(int i=0;i<minn1;i++){
            cout<<"D";
        }
        for(int i=0;i<minn;i++){
            cout<<"L";
        }
        cout<<endl;
    }
    return 0;
}
