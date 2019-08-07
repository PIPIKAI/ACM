#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
int ask[4][2]={1,2,2,3,4,5,5,6};
int f[8]={4,8,15,16,23,42},k[8],ans[8];
int main()
{
    for(int i=0;i<4;i++){
        cout<<"? "<<ask[i][0]<<" "<<ask[i][1]<<endl;
        fflush(stdout);
       cin>>k[i];
    }
    int a,b,c,d;
    for(int l=0;l<4;l++)
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
             if(f[i]*f[j]==k[l]){
                    if(l==0){
                        a=i,b=j;
                    }
                    else if(l==1){
                        c=i,d=j;
                        if(a==c){
                            ans[0]=f[b],ans[1]=f[a],ans[2]=f[d];
                        }
                        else if(a==d){
                            ans[0]=f[b],ans[1]=f[a],ans[2]=f[c];
                        }
                        else if(b==c){
                            ans[0]=f[a],ans[1]=f[b],ans[2]=f[d];
                        }
                        else{
                            ans[0]=f[a],ans[1]=f[b],ans[2]=f[c];
                        }
                    }
                    else if(l==2){
                        a=i,b=j;
                    }
                    else{
                        c=i,d=j;
                        if(a==c){
                            ans[3]=f[b],ans[4]=f[a],ans[5]=f[d];
                        }
                        else if(a==d){
                            ans[3]=f[b],ans[4]=f[a],ans[5]=f[c];
                        }
                        else if(b==c){
                            ans[3]=f[a],ans[4]=f[b],ans[5]=f[d];
                        }
                        else{
                            ans[3]=f[a],ans[4]=f[b],ans[5]=f[c];
                        }
                    }

             }
        }
    }
    fflush(stdout);
    cout<<"! ";
    for(int i=0;i<6;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    fflush(stdout);
    return 0;
}
