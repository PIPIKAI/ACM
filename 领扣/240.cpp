#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& f, int tar) {
        int n=f.size(),m=f[0].size();
        for(int i=0;i<n;i++)
        {
            if(f[i][0]>tar||f[i][m-1]<tar)
                continue;
           int j=lower_bound(f[i].begin(),f[i].end(),tar)-f[i].begin();
            if(f[i][j]==tar)
                return true;
        }
    return false;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution a;
    return 0;
}
