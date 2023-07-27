#include <bits/stdc++.h>
using namespace std; 

// int help(int index, int w, int n, vector<int>& a, vector<int>& b, vector<vector<int>>&dp){
//     if(index == 0){
// 		if(w >= a[0]){
// 			return b[0];
// 		}else{
// 			return 0;
// 		}
//     }
//     if(dp[index][w] != -1){
//         return dp[index][w];
//     }
//     int notTake = help(index - 1, w, n, a, b, dp);
//     int take = INT_MIN;
//     if(w >= a[index]){
//         take = b[index] + help(index - 1, w - a[index], n, a, b, dp);
//     }
//     return dp[index][w] = max(take, notTake);
// }
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w){
	vector<vector<int>> dp(n, vector<int>(w + 1, 0));
	for(int i = weights[0]; i <= w; i++){
		dp[0][i] = values[0];
	}
	for(int i = 1; i < n; i++){
		for(int j = 0; j <= w; j++){
			int notTake = dp[i - 1][j];
			int take = INT_MIN;
			if(j >= weights[i]){
				take = values[i] + dp[i - 1][j - weights[i]];
			}
			dp[i][j] = max(take, notTake);
		}
	}
	return dp[n - 1][w];
}
int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	cout << maxProfit(b, a, n, k) << endl;
}

