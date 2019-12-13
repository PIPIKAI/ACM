#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
int n,m;
#define LOCAL
int d[4];
unordered_map<int,int> mp; 
int main(int argc, char * argv[]) 
{
    
    #ifdef LOCAL
    
    #endif
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;

    while (q--)
    {
    	mem(d,0);
    	string s;
    	cin>>s;
    	int len=s.size();
    	for(int i=0;i<len;i++){
    		if(s[i]=='L'){	
    			d[0]++;
    		}	
    		else if(s[i]=='R'){
    			d[1]++;
    		}
    		else if(s[i]=='U'){
    			d[2]++;
    		}
    		else if(s[i]=='D'){
    			d[3]++;
    		}
    	}
    	int minn=inf;
    	for(int i=0;i<2;i++){
            minn=min(minn,d[i]);
        }
        int minn1=inf;
        for(int i=2;i<4;i++){
            minn1=min(minn1,d[i]);
        }
		 if(d[0]==0||d[1]==0){
	        if(minn1>=1){
	            cout<<"2"<<endl<<"UD"<<endl;
	        }
	        else {
	        	cout<<"0"<<endl;
	        }
        	continue;
        }
        if(d[0]==0||d[1]==0){
            if(minn1>=1){
                cout<<"2"<<endl<<"UD"<<endl;
            }
            else cout<<"0"<<endl;
            continue;
        }
        if(d[2]==0||d[3]==0){
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