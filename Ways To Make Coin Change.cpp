#include <bits/stdc++.h>
using namespace std; 


// long help(int index, int x, int n, int *denominations, vector<vector<long>>& dp){
//     if(index == 0){
//         return (x % denominations[0] == 0);
//     }
//     if(dp[index][x] != -1){
//         return dp[index][x];
//     }
//     long notTake = help(index - 1, x, n, denominations, dp);
//     long take = 0;
//     if(x >= denominations[index]){
//         take = help(index, x - denominations[index], n, denominations, dp);
//     }
//     return dp[index][x] = take + notTake;
// }
long countWaysToMakeChange(int *denominations, int n, int value){
    vector<vector<long>> dp(n, vector<long>(2001, 0));
    for(int i = 0; i <= value; i++){
        dp[0][i] = (i % denominations[0] == 0);
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= value; j++){
            long notTake = dp[i - 1][j];
            long take = 0;
            if(j >= denominations[i]){
                take = dp[i][j - denominations[i]];
            }
            dp[i][j] = take + notTake;
        }
    }
    return dp[n - 1][value];
}
int main(){
	int n, x;
	cin >> n >> x;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << countWaysToMakeChange(a, n, x) << endl;
}

