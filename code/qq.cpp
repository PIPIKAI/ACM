#include<bits/stdc++.h>
#define lll __int128_t
#define read(x) x=fread()
inline lll fread() {char c = getchar(); lll x = 0, f = 1;
while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;}
inline lll fout(lll x){
    if(x<0) {x=-x,putchar('-');x>9 ?fout(x/10) :0;}
    else if(x>9) fout(x/10);
    putchar('0'+x%10);
}
int main(){

    lll a;
    while(read(a)){
        fout(a);
        puts("");
    }
    
    return 0;
}