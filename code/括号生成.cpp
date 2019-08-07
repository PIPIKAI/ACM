#include<bits/stdc++.h>
using namespace std;
void dfs(int x , int y , string tp , int n){
    if(y==n){
        cout<<tp<<endl;
    }
    if(x<n){
        dfs( x+1 , y , tp+"(" , n);
    }
    if(x>y){
        dfs( x , y+1 , tp+")" , n);
    }
}
int main()
{
    int n;
    cin>>n;
    dfs(0 , 0 , "" , n );
    return 0;
}
