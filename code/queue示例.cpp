#include <iostream>
#include <queue>
#include <assert.h>
/*
调用的时候要有头文件： #include<stdlib.h> 或 #include<cstdlib> +
#include<queue>       #include<queue>
详细用法:
定义一个queue的变量     queue<Type> M
查看是否为空范例        M.empty()    是的话返回1，不是返回0;
从已有元素后面增加元素   M.push()
输出现有元素的个数      M.size()
显示第一个元素          M.front()
显示最后一个元素        M.back()
清除第一个元素          M.pop()
*/
using namespace std;
void dispaly(queue<int > q)
{
    while(!q.empty())
    {
        cout<<q.front();
        q.pop();
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<"input  "<<n<<"number"<<endl;
    queue<int>q;
    while(n)
    {
        int temp;
        cin>>temp;
        q.push(temp);
        n--;
    }
    dispaly(q);

    return 0;
}
