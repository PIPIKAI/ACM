#include<bits/stdc++.h>
using namespace std;
int a[5000],n;
int main(){
    int t;
    cin>>t;
    while(t--){
        cin >> n;
        n= 1<<n;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++) a[j]=1;
            for (int p=0;p<10;p++) if (i&(1<<p))
                for (int j=0;j<n;j++) if (j&(1<<p))
                    a[j]=-a[j];
            for (int j=n-1;j>=0;j--) printf("%c",a[j]==1 ? 'C' : 'P');
            printf("\n");
        }
    }
    
    return 0;
}