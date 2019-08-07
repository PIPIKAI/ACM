#include<string.h>
#include<stdio.h>
typedef struct
{
    int top=0;
    char s[255];

}_stack;
typedef struct
{
    int tail=0;
    char s[255];
}_que;
void push(_stack a,char c)
{
    int n=a.top+1;
    a.s[n]='\0';
    while(n>1)
    {
        a.s[n]=a.s[n-1];
        n--;
    }
    a.top++;
    a.s[0]=c;
}
void add(_que b,char c)
{
    b.s[b.tail]=c;
    b.s[b.tail+1]='\0';
}
void solve()
{
    _stack a;
    _que b;
    char s[255];
    gets(s);
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[') {push(a,s[i]);}

        if(s[i]==')'||s[i]=='}'||s[i]==']') {add(b,s[i]);}
    }
    printf("a=%s\nb=%s\n",a.s,b.s);
    if(1==strcmp(a.s,b.s))
        printf("YES\n");
    else
        printf("NO\n");
}
int main()
{
    solve();
    return 0;
}
