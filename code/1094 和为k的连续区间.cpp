    #include<iostream>
    #include<algorithm>
    #include<cstring>
    using namespace std;
    typedef long long ll;
    ll f[10005];
    int n,k,flag=1;
    void init()
    {
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                f[j]-=f[i-1];
                if(flag)
                if(f[j]==k)
                {
                    cout<<i<<" "<<j<<endl;
                    flag=0;
                }
            }
        }
        if(flag)
            cout<<"No Solution"<<endl;
    }
    void solve ()
    {
    memset(f,0,sizeof(0));
        for(int i=1;i<=n;i++)
        {
            cin>>f[i];
            f[i]+=f[i-1];
        }
        init();
    }
    int main()
    {
        cin>>n>>k;
            solve();
        return 0;
    }
