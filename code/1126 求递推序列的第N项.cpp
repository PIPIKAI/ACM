#include<iostream>
using namespace std;
int main()
{
    int d[1005]={1,1,1},a,b,n;
    while(cin>>a>>b>>n)
    {
        int i=3;
        for(;i<300;i++)
        {
            d[i]=((a*d[i-1]+b*d[i-2])%7+7)%7;
            if(d[i-1]==1&&d[i]==1)       //Ѱ��ѭ����
              break;
        }
        d[0]=d[i-2];     //��ѭ����ǰ�油��
        cout<<d[n%(i-2)]<<endl;
    }
    return 0;
}
