#include<iostream>
#include<cstring>
using namespace std;
string aa,bb,cc;
int a[600],b[600],c[600];
int main()
{
    int i,j,len=0,x,y;
    cin>>aa>>bb;

    if(aa.length()<bb.length()||(aa.length()==bb.length())&&(aa<bb))
    {
        cc=aa;
        aa=bb;
        bb=cc;
        cout<<"-";
    }
    for(i=1;i<=aa.length()+1;i++)
        a[i]=aa[i-1]-'0';
    for(i=1;i<=bb.length()+1;i++)
    b[i]=bb[i-1]-'0';
//--------------------------------------------------------
    x=aa.length();
    y=bb.length();
    while(x>0)
    {
        if(a[x]<b[y])
        {
            a[x]+=10;
            a[x-1]--;
        }
           c[++len]=a[x]-b[y];
      x--;
      y--;
    }
    int f=1;
   for(i=aa.length();i>0;i--)
    if(f)
    {
        if(c[i]!=0||i==1)
        {
            cout<<c[i];
            f=0;
        }
    }
    else
        cout<<c[i];
    return 0;
}
