#include<bits/stdc++.h>
using namespace std;
int c1[10000],c2[10000];
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0;i<=n;i++) //首先对c1初始化，由第一个表达式(1+x+x^2+..x^n)初始化，把质量从0到n的所有砝码都初始化为1.
        {
            c1[i]=1;
            c2[i]=0;
        }                           //i从2到n遍历，这里i就是指第i个表达式，上面给出的第二种母
        for(int i=2;i<=n;i++)       //函数关系式里，每一个括号括起来的就是一个表达式。
        {
            for(int j=0;j<=n;j++)//j 从0到n遍历，这里j就是(前面i個表达式累乘的表达式)里第j个变量，。
                                //如(1+x)(1+x^2)(1+x^3)，j先指示的是1和x的系数，i=2执行完之后变为
            {
                for(int k=0;k+j<=n;k+=i)// k表示的是第j个指数，所以k每次增i（因为第i个表达式的增量是i）。
                {
                    c2[j+k]+=c1[j];
                }
            }
            for(int j=0;j<=n;j++)//把c2的值赋给c1,而把c2初始化为0，因为c2每次是从一个表达式中开始的。
            {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        cout<<c1[n]<<endl;
    }
    return 0;
}
