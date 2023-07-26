#include <bits/stdc++.h>
using namespace std; 


// int help(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp){
//     if(i == 0 && j == 0){
//         return grid[0][0];
//     }
//     if(i < 0 || j < 0){
//         return INT_MAX;
//     }
//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }
//     int curr = grid[i][j] + min(help(i - 1, j, n, m, grid, dp), help(i, j - 1, n, m, grid, dp));
//     return dp[i][j] = curr;
// }
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 && j == 0){
                dp[i][j] = grid[i][j];
            }else{
                int up = grid[i][j] + (i > 0 ? dp[i - 1][j] : 1e9);
                int left = grid[i][j] + (j > 0 ? dp[i][j - 1] : 1e9);
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n - 1][m - 1];
}
int main(){
	int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    cout << minSumPath(a) << endl;
}

