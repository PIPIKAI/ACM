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
因为完全平方数的约数数量为 奇数 但是1又不能改变开关
所以因数数量恒为偶数，所以问题就转换为在区间内有多少个非完全平方数，对于一个数，
 从1到n有的完全平方数有sqrt(n)个，则在区间L-R中共有sqrt(R)-sqrt(L)个完全平方数，
非完全平方数：R-L+1-(sqrt(R)-sqrt(L))
*/
