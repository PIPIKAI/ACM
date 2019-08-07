#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
template <typename T,int Ksize>
class Container
{
public :
    Container(T m);
    void dis();
private :
    T jb;
};
template <typename T,int Ksize>
Container < T,Ksize >::Container(T m)
{
    this->jb=m;
}
template <typename T,int Ksize>
void Container < T,Ksize >:: dis()
{
    for(int i=0;i<Ksize;i++)
    cout<<this->jb<<endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    Container < int,5> c(30);
    c.dis();
    return 0;
}
