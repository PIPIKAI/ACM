#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll E[500];
/**
����һ��������n��С��n�Һ�n���ʵ�������������1���ĸ�����������(n) ��

ŷ��������ͨʽ����(n)=n*(1-1/p1)*(1-1/p2)*(1-1/p3)*(1-1/p4)��..(1-1/pn),
����p1, p2����pnΪn��������������n�ǲ�Ϊ0����������(1)=1��Ψһ��1���ʵ�������1������
*/
ll phi(ll n)
{
    ll s=n;
     for(ll i=2;i*i<=n;i++)
        if(n%i==0)
        {
            s-=s/i;
            while(n%i==0)
                n/=i;
        }
     if(n>1) s=s/n*(n-1);
     return s;
}
int maxn=200;

void euler()
{
    for(int i=2;i<maxn;i++){
        if(!E[i])
        for(int j=i;j<maxn;j+=i){
            if(!E[j])E[j]=j;
            E[j]=E[j]/i*(i-1);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    euler();
    for(int i=0;i<=100;i++)
        cout<<E[i]<<endl;
    return 0;
}
