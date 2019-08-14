#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<cstring>
#include<set>
using namespace std;
#define Max(x,y) y>x?x=y:x=x
#define mem(a,b)  memset( a,b,sizeof a)
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 1e4+7;
int n,m,q;
int f[maxn];
vector<int> tp;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>q;
    while(q--){
        tp.clear();
        mem(f,0);
        cin>>n;
        int flag=1;
        n=4*n;
        for(int i=0,tp;i<n;i++){
            cin>>tp;
            f[tp]++;
        }
        for(int i=1;i<=10000;i++){
            if(f[i]){
                if(f[i]%2){
                    flag=0;
                    break;
                }
                while (f[i])
                {
                    f[i]-=2;
                    tp.push_back(i);
                }
            }
        }
        if(flag){
            int len=tp.size();
            int are=tp[0]*tp[len-1];
            //cout<<are<<endl;
            for(int i =1;i<len/2;i++){
                int j=len-i-1;
                //cout<<tp[i]*tp[j]<<endl;
                if(tp[i]*tp[j]!=are){
                    //cout<<tp[i]*tp[j]<<endl;
                    flag=0;
                    break;
                }
            }
            flag? cout<<"YES"<<endl : cout<<"NO"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}