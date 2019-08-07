#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
const int maxn=110;
int n,m,cnt;
ll prime[maxn];
bool vis[maxn];
int ans[maxn][maxn];
void ini(){
     cnt=0;
    for(int i = 2; i <= maxn; i++)
    {
        if(!vis[i])//����Ŀǰ�ҵ��������ı���
        prime[cnt++] = i;//�ҵ�����~
        for(int j = 0; j<cnt && i*prime[j]<=maxn; j++)
        {
            vis[i*prime[j]] = true;//�ҵ��������ı���������
            if(i % prime[j] == 0) break;//�ؼ���������
        }
    }
    for(int jj=2;jj<maxn;jj++){
        int tp=jj;
        while(tp>1){
            for(int i=0;i<cnt;i++){
                if(prime[i]>tp){
                    break;
                }
                while(tp%prime[i]==0){
                    tp/=prime[i];
                    ans[jj][prime[i]]++;
                }
            }
        }
    }

}
int main()
{
    std::ios::sync_with_stdio(false);
    int ca=0,t;
    ini();
    cin>>t;
    while(t--){
        ca++;
        cin>>n;
        cout<<"Case "<<ca<<": "<<n<<" = ";
        int flag=0;
        for(int i=2;i<maxn;i++){
            int t=0;
            for(int j=2;j<=n;j++){
                t+=ans[j][i];
            }
            if(t){
                if(flag) cout<<" * ";
                cout<<i<<" ("<<t<<")";
                if(!flag) flag=1;
            }
        }
        cout<<endl;
    }
    return 0;
}
