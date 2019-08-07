#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;
int emp[4][2]={1,1,-1,-1,-1,1,1,-1};
int full[4][2]={1,0,0,1,-1,0,0,-1};
string s[600];
int cnt,n,m;
struct node{
	int x,y;
}f[maxn];
bool juge(int x,int y)
{
    bool flag=1;
    for(int i =0;i<4;i++){
        int dx=x+emp[i][0];
        int dy=y+emp[i][1];
        if(dx>=0&&dy>=0&&s[dx][dy] =='*'){
            flag=0;
            break;
        }
        if(dx< 0 || dy< 0 || dx>=n || dy>=m){
            flag=0;break;
        }
    }
    for(int i =0;i<4;i++){
        int dx=x+full[i][0];
        int dy=y+full[i][1];
        if(dx>=0&&dy>=0&&s[dx][dy] =='.'  ){
            flag=0;
            break;
        }
        if(dx< 0 || dy< 0 || dx>=n || dy>=m){
            flag=0;break;
        }
    }
    return flag;
}
void dfs(int x,int y,int dx,int dy){
	if(x<0 || y<0 || x> n-1 || y> m-1 || s[x][y]=='.'){
		return ;
	}
	else{
		s[x][y]='.';
		dfs(x+dx,y+dy,dx,dy);
	}
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='*'&&juge(i,j)){
            	f[cnt++]={i,j};
            }
        }
    }
    if(cnt==1){
        int x=f[0].x,y=f[0].y;
		for(int i=0;i<4;i++){
			dfs(x+full[i][0],y+full[i][1],full[i][0],full[i][1]);
		}
		s[x][y]='.';
		/*
		for(int i=0;i<n;i++){
			cout<<s[i]<<endl;
		}*/
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
					if(s[i][j]=='*' ){
						return cout<<"NO"<<endl,0;
					}
		        }
		    }
		    cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
