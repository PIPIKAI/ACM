#include<bits/stdc++.h>
#include"pointhead.h"
#include"linehead.h"
using namespace std;
typedef long long ll;
int main()
{
    std::ios::sync_with_stdio(false);
    point p(2,3);
    line l(1,2,1);
    double d=dis(l,p);
    cout<<"点到直线的距离是 :"<<d<<endl;
    return 0;
}


/// 友元不是类的成员但可以访问类的所有成员
