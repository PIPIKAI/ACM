#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
class OUbou
{
public :
    OUbou(int i)
    {
        this->i=i;
    }
    void erre()
    {
        cout<<"数组越界"<<endl;
    }
private:
    int i;
};
class aa
{
    public :
    int  &operator[](int i)
    {
        if(i<0||i>=10)
        {
            throw OUbou(i);
            return a[i];
        }
    }
    private :
        int a[10];
};
int main()
{
    std::ios::sync_with_stdio(false);
    aa m;
    try
    {
        m[11]=3;
    }
    catch(OUbou(&e))
    {
        e.erre();
    }
    return 0;
}
