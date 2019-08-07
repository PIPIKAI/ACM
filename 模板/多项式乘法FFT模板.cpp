#include<bits/stdc++.h>
using namespace std;
const double Pi = acos(-1.0);
const int MAXN=1e7+10;
int n,m,l,r[MAXN];
struct fcomplex {
    double x, y;
    fcomplex (double xx = 0, double yy = 0) {x = xx, y = yy;}
} a[MAXN], b[MAXN];
fcomplex operator + (fcomplex a, fcomplex b) { return fcomplex(a.x + b.x , a.y + b.y);}
fcomplex operator - (fcomplex a, fcomplex b) { return fcomplex(a.x - b.x , a.y - b.y);}
fcomplex operator * (fcomplex a, fcomplex b) { return fcomplex(a.x * b.x - a.y * b.y , a.x * b.y + a.y * b.x);} //不懂的看复数的运算那部分
//  递归版是时间复杂度O(n*logn) 
void fast_fast_tle0(int limit, fcomplex *a, int type) {
    if (limit == 1) return ; //只有一个常数项
    fcomplex a1[limit >> 1], a2[limit >> 1];
    for (int i = 0; i <= limit; i += 2) //根据下标的奇偶性分类
        a1[i >> 1] = a[i], a2[i >> 1] = a[i + 1];
    fast_fast_tle0(limit >> 1, a1, type);
    fast_fast_tle0(limit >> 1, a2, type);
    fcomplex Wn = fcomplex(cos(2.0 * Pi / limit) , type * sin(2.0 * Pi / limit)), w = fcomplex(1, 0);
    //Wn为单位根，w表示幂
    for (int i = 0; i < (limit >> 1); i++, w = w * Wn) //这里的w相当于公式中的k
        a[i] = a1[i] + w * a2[i],
               a[i + (limit >> 1)] = a1[i] - w * a2[i]; //利用单位根的性质，O(1)得到另一部分
}
//  合并是时间复杂度O(n)！ 
void fast_fast_tle(int limit, fcomplex *a, int type) {
    for (int i = 0; i < limit; i++)
        if (i < r[i]) swap(a[i], a[r[i]]); //求出要迭代的序列
    for (int mid = 1; mid < limit; mid <<= 1) { //待合并区间的长度的一半
        fcomplex Wn( cos(Pi / mid) , type * sin(Pi / mid) ); //单位根
        for (int R = mid << 1, j = 0; j < limit; j += R) { //R是区间的长度，j表示前已经到哪个位置了
            fcomplex w(1, 0); //幂
            for (int k = 0; k < mid; k++, w = w * Wn) { //枚举左半部分
                fcomplex x = a[j + k], y = w * a[j + mid + k]; //蝴蝶效应
                a[j + k] = x + y;
                a[j + mid + k] = x - y;
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        cin>>a[i].x;a[i].y=0;
    }
    for(int i=0;i<=m;i++){
        cin>>b[i].x;b[i].y=0;
    }
    int limit=1;
    while(limit<=n+m){
        limit<<=1,l++;
    }
    for (int i = 0; i < limit; i++)
        r[i] = ( r[i >> 1] >> 1 ) | ( (i & 1) << (l - 1) ) ;
    // 在原序列中 i 与 i/2 的关系是 ： i可以看做是i/2的二进制上的每一位左移一位得来
    // 那么在反转后的数组中就需要右移一位，同时特殊处理一下奇数
    for (int i = 0; i < limit; i++)
        r[i] = ( r[i >> 1] >> 1 ) | ( (i & 1) << (l - 1) ) ;
    // 在原序列中 i 与 i/2 的关系是 ： i可以看做是i/2的二进制上的每一位左移一位得来
    // 那么在反转后的数组中就需要右移一位，同时特殊处理一下奇数
    fast_fast_tle(limit,a,1);
    fast_fast_tle(limit,b,1);
    //后面的1表示要进行的变换是什么类型
    //1表示从系数变为点值
    //-1表示从点值变为系数
    //至于为什么这样是对的，可以参考一下c向量的推导过程，
    for(int i=0;i<=limit;i++){
        a[i]=a[i]*b[i];
    }
    fast_fast_tle(limit,a,-1);
    for(int i=0;i<=n+m;i++){
        cout<<(int)(a[i].x / limit +0.5)<<" ";
    }
    return 0;
}