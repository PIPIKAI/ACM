#include<stdio.h>
#include<string.h>
struct infor
{
    char name[255];
    char bumeng[255];
    char gongzi[255];
    char butie[255];
};
int main()
{
    int n,i;
    char fi[255];
    scanf("%d\n",&n);
    struct infor q[n];
    for(i=0;i<n;i++)
    {
        scanf("%s%s%s%s",q[i].name,q[i].bumeng,q[i].gongzi,q[i].butie);
    }
    scanf("%s",fi);
    for(i=0;i<n;i++)
    {
        if(strcmp(fi,q[i].name)==0)
        {
            printf("%s %s %s %s\n",q[i].name,q[i].bumeng,q[i].gongzi,q[i].butie);
            return 0;
        }
    }
    printf("not found\n");
    return 0;
}
