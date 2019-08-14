#include<bits/stdc++.h>
int n,i,a, s;
int t[150021];
int main() {
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		scanf("%d",&a);
		t[a]++;
	}
	for(i=1; i<=150001; i++) {
		if(t[i-1]) {
			t[i-1]--;
			s++;
		} else if(t[i]) {
			t[i]--;
			s++;
		} else if(t[i+1]) {
			t[i+1]--;
			s++;
		}
	}
	printf("%d",s);
}