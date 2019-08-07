#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{
    int len;
    char str[9];
    scanf("%s",str);
    len=strlen(str);
    sort(str,str+len);
    /*do{
        printf("%s\n",str);
    }while(next_permutation(str,str+len));*/
    printf("%s",str);
    return 0;
}
