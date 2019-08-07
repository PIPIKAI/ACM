#include<iostream>
using namespace std;
int main()
{
    int f[4][3];
    int n;
    cin>>n;
    for(int pp=0;pp<n;pp++)
    {
        int a,b,c,x,y,z;
        int t[2][3];
        for(int k=0;k<4;k++)
            cin>>f[k][0]>>f[k][1]>>f[k][2];
        x=f[0][0];y=f[0][1];z=f[0][2];
            for(int i=0;i<3;i++)
             t[0][i]=f[1][i]-f[0][i];
            for(int i=0;i<3;i++)
             t[1][i]=f[2][i]-f[0][i];

             a=t[0][1]*t[1][2]-t[0][2]*t[1][1];
             b=t[1][0]*t[0][2]-t[0][0]*t[1][2];
             c=t[0][0]*t[1][1]-t[0][1]*t[1][0];
             if(((f[3][0]-x)*a+(f[3][1]-y)*b+(f[3][2]-z)*c)==0)
                cout<<"Yes"<<endl;
             else
                cout<<"No"<<endl;
         }


    return 0;
}
