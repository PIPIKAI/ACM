#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
ll n,l,r;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>l>>r;
    cout<< (r-l+1 -(ll)sqrt(r) +(ll)sqrt(l))<<endl;
    return 0;
}
/**
��Ϊ��ȫƽ������Լ������Ϊ ���� ����1�ֲ��ܸı俪��
��������������Ϊż�������������ת��Ϊ���������ж��ٸ�����ȫƽ����������һ������
 ��1��n�е���ȫƽ������sqrt(n)������������L-R�й���sqrt(R)-sqrt(L)����ȫƽ������
����ȫƽ������R-L+1-(sqrt(R)-sqrt(L))
*/
