#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
    char a[14];
    scanf("%s",a);
    int i, j = 1, t = 0;
    for(i = 0; i < 12; i++)
    {
        if(a[i] == '-')continue;
        t += (a[i]-'0')*j++;
    }
    string mod="0123456789X";
    if(mod[t%11] == a[12])printf("Right");
    else
    {
        a[12] = mod[t%11];
        puts(a);
    }
    return 0;
}
