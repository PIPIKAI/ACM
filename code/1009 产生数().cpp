#include<iostream>
#include<cstring>
using namespace std;
int a[20],b[20];
int f[10];
int main()
{
    char str[50];
    int k;
    cin<<str<<k;
    int i=0;
    for(i=0;i<k;i++)
        cin>>a[i]>>b[i];
    for(i=0;i<strlen(str);i++)
        f[str[i]-'0']++;

    return 0;
}
