#include <bits/stdc++.h>
using namespace std; 


// int help(int index, int n, vector<int>& a, vector<vector<int>>& dp){
// 	if(index == 0){
// 		return n * a[0];
// 	}
// 	if(dp[index][n] != -1){
// 		return dp[index][n];
// 	}
// 	int notTake = help(index - 1, n, a, dp);
// 	int take = INT_MIN;
// 	if(index + 1 <= n){
// 		take = a[index] + help(index, n - (index + 1), a, dp);
// 	}
// 	return dp[index][n] =  max(take, notTake);
// }
int cutRod(vector<int> &price, int n){
	vector<vector<int>> dp(n, vector<int>(n + 1, 0));
	for(int i = 0; i <= n; i++){
		dp[0][i] = i * price[0];
	}
	for(int i = 1; i < n; i++){
		for(int j = 0; j <= n; j++){
			int notTake = dp[i - 1][j];
			int take = INT_MIN;
			if(i + 1 <= j){
				take = price[i] + dp[i][j - (i + 1)];
			}
			dp[i][j] = max(take, notTake);
		}
	}
	return dp[n - 1][n];
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << cutRod(a, n) << endl;
}

