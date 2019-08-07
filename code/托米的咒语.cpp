#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 10;
char str[maxn];
int num[maxn][9];
int ap[9];
int anum[10];
int main()
{
    cin >> str;
    for(int i = 0;i < 9;i++)
        ap[i] = -1;
    int len = strlen(str);
    for(int i=0;i<10;i++)
        anum[i]=i;
    for(int i = len - 1;i >= 0;i--)
    {
        ap[str[i] - 'a'] = i;
        for(int j = 0;j < 9;j++)
            num[i][j] = ap[j];
    }
    for(int j = 0;j < 9;j++)
        cout<<ap[j]<<" ";
    cout<<endl;
     for(int i = len - 1;i >= 0;i--)
    {
        for(int j = 0;j < 9;j++)
            cout<<num[i][j]<<" ";
            cout<<endl;
    }
    int ans = 0;

    do{
        int t = 0;
        int k = ap[anum[0]];
        while(k != -1)
        {
            t++;
            if(t == 9){
            ans ++;
            break;
            }
            k = num[k][anum[t]];
        }

    }while(next_permutation(anum,anum + 9));
    cout << ans << endl;
    return 0;
}
