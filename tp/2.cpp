//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
string X,s1,s2;
int f[maxn],w[maxn],vis[maxn];
int ans=0;
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    cin>>s1>>s2;
    X=s1;
    string tp=s2;
    sort(X.begin(),X.end());
    sort(tp.begin(),tp.end());
    if(X!=tp){
    	cout<<-1<<endl;
    }
    else{
    	int n=s1.size();
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			if(s2[j]==s1[i] && vis[j]==0){
    				vis[j]=1;
    				f[i]=j;
    				break;
    			}
    		}
    	}

    	for(int i=0;i<n;i++){
    		// cout<<f[i]<<" ";
    		int count=0;
    		for(int j=i+1 ;j < n;j++){
    			if( f[i]  > f[j]){
    				count++;
    			}
    		}
    		ans+=count;
    	}
    	cout<<ans<<endl;
    }
    return 0;
}