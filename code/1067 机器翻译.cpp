#include<iostream>
using namespace std;
int M,sum=0,val;
int is_have(int f[],int k)
{
    for(int i=0;i<M;i++)
    {
        if(f[i]==k)
            return 1;
    }
    return 0;
}
int main()
{
    int n;
    cin>>M>>n;
    int nei_cun[M],_count=0;
    for(int i=0;i<M;i++)
    {
        nei_cun[i]=-1;
    }


    for(int i=0;i<n;i++)
    {
        cin>>val;
        if(0==is_have(nei_cun,val))
            {
                if(_count<M)
                {
                     nei_cun[_count%M]=val;
                    sum++;
                    _count++;
                }
                else
                {
                    nei_cun[_count%M]=val;
                     _count++;
                    sum++;
                }
            }
    }
cout<<sum<<endl;
    return 0;
}
