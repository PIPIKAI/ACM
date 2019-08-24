 for(int i=1;i<=n;i++){
        int tp=lower_bound(li+1,li+tot+1,f[i])-li;
        T[i]=update(T[i-1],1,tot,tp);
    }
    while(m--){
        int l,r,k;
        cin>>l>>r>>k;
        int t=query(T[l-1],T[r],1,m,k);
        cout<<li[t]<<endl;
    }