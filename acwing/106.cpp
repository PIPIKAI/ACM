#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
priority_queue<int ,vector<int>, less<int> > big; // 降序
priority_queue<int ,vector<int>, greater<int> > litter; // 升序 ,top 是最小的
int main(){
	std::ios::sync_with_stdio(false);
	int P,no,n;
	cin>>P;
	while(P--){
		while(!big.empty()) big.pop();
		while(!litter.empty()) litter.pop();
		cin>>no>>n;
		int ed=0;
		cout<<no<<" "<<(n+1>>1)<<endl;
		for(int now , i = 0;i < n;i++){
			cin>>now;
			if(big.empty()){
				big.push(now);
			}
			else{
				if(now <big.top()){
					big.push(now);
				}
				else{
					litter.push(now);
				}
				while(big.size() <litter.size()){
					big.push(litter.top());
					litter.pop();
				}
				while(big.size()-1 >litter.size()){
					litter.push(big.top());
					big.pop();
				}

			}
			if(i%2==0){
				ed++;
				cout<<big.top()<<" ";
				if(ed%10==0) cout<<endl;
			}
		}
		if(ed%10!=0) cout<<endl;
	}
	return 0;
}