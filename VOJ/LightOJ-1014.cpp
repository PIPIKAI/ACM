#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int pp,ca=0,a,b,t;
    cin>>pp;
    while(pp--){
        vector<int >ans;
        ca++;
        cin>>a>>b;
        cout<<"Case "<<ca<<": ";
        t=a-b;
        if(t<=b){
            cout<<"impossible"<<endl;
            continue;
        }
        for(int i=1;i<=sqrt(t);i++){
            if(t%i==0){
                ans.push_back(i);
                if(t/i!=i)
                ans.push_back(t/i);
            }
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            if(ans[i]>b){
            cout<<ans[i];
                if(i!=ans.size()-1){
                    cout<<" ";
                }
            } 
        }
        ans.clear();
        cout<<endl;
    }
    return 0;
}