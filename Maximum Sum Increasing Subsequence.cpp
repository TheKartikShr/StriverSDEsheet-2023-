#include <bits/stdc++.h>
using namespace std; 


int maxIncreasingDumbbellsSum(vector<int> &a, int n){
	int ans = a[0];
	vector<int> dp = a;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(a[i] > a[j]){
				if(dp[j] + a[i] > dp[i]){
					dp[i] = dp[j] + a[i];
				}
			}
		}
		ans = max(ans, dp[i]);
	}
	return ans;
}
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << maxIncreasingDumbbellsSum(a, n) << endl;
}

