#include <bits/stdc++.h>
using namespace std; 

int help(int i, int j, int n, int m, vector<vector<int>> &dp){
    if(i < 0 || j < 0 || i >= n || j >= m){
        return 0;
    }
    if(i == n - 1 && j == m - 1){
        return 1;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    return dp[i][j] = help(i, j + 1, n, m, dp) + help(i + 1, j, n, m, dp);
}
int main(){
	int t;
	cin >> t;
	while(t--){	
		int n, m;
		cin >> n >> m;
		vector<vector<int>> dp(n, vector<int>(m, -1));
		cout << help(0, 0, n, m, dp) << endl;
	}
}

   