#include<algorithm>
#include<vector>
#include<cstring>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
    vector<int> f;
    /* iterator*/
    while(1)
    {

        int ca;
        cin>>ca;
        if(ca==1)
        {
            int temp;
            cin>>temp;
            f.push_back(temp);
        }
        else if(ca==2)
        {
            vector <int> ::iterator t;
            /*for(t=f.begin();t!=f.end();t++)
                cout<<*t<<" ";*/
            for(int i=0;i<f.size();i++)
                cout<<f[i]<<" ";
        }
        else if(ca==3)
        {
            int n,temp;
            cin>>n>>temp;
            f.insert(f.begin()+n,temp);
        }
        else if(ca==4)
        {
            sort(f.begin(),f.end());
        }
        else if(ca==5)
        {
            reverse(f.begin(),f.end());
        }
        else if(ca==6)
        {
            int a,b;
            cin>>a>>b;
            f.erase(f.begin()+a,f.begin()+b);
        }
        else
            break;
    }

    return 0;
}
