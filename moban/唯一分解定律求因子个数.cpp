#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+7;
int prime[maxn],cnt=0;//������
bool vis[maxn];//��֤���������ı���
void ini(){
    for(int i = 2; i <= maxn; i++){
        if(!vis[i])//����Ŀǰ�ҵ��������ı���
        prime[cnt++] = i;//�ҵ�����~
        for(int j = 0; j<cnt && i*prime[j]<=maxn; j++){
            vis[i*prime[j]] = true;//�ҵ��������ı���������
            if(i % prime[j] == 0) break;//�ؼ���������
        }
    }
}
int main(){
    ll ca=0,t,n;
    cin>>t;
    ini();
    while(t--){
        ca++;
        cin>>n;
        ll t=sqrt(n),ans=1;
        cout<<"Case "<<ca<<": ";
        for(int i=0;i<cnt&& prime[i] <=sqrt(n);i++){
            int tp=0;
            while(n%prime[i]==0){
                tp++;
                n/=prime[i];
            }
            ans*=(tp+1);
        }
        if(n>1){
            ans*=2;
        }
        cout<<ans-1<<endl;
    }
    return 0;
}
