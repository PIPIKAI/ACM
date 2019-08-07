#include<bits/stdc++.h>
using namespace std;
class comp
{
public :
    comp(int rea=0,int ima=0);
    friend comp add(compl a,compl b);
private :
    int rea,ima;

};
comp::comp(int r,int m)
{
    this->rea=r;
    this->ima=m;
}
comp add(comp a,comp b)
{
    int r= a.rea+b.read;
    int m= a.ima+b.ima;
    comp reasult(r,m);
    cout<<"最后的结果是："<<reasult.r<<" + "reasult.m<<"i"<<endl;
    return reasult;
}
int main()
{
    std::ios::sync_with_stdio(false);
    comp c1(1,2);
    comp c2(4,9);
    comp reasult=add(c1,c2);
    return 0;
}
