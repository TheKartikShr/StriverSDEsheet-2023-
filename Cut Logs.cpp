#include <bits/stdc++.h>
using namespace std; 

int help(int n, int k, vector<vector<int>>& dp){
    if(n <= 0 || k <= 0){
        return 0;
    }
    if(k == 1){
        return n;
    }
    if(n == 1){
        return 1;
    }
    if(dp[n][k] != -1){
        return dp[n][k];
    }
    int ans = INT_MAX;
    int l = 1, h = n;
    while(l <= h){
        int mid = l + (h - l) / 2;
        int broke = help(mid - 1, k - 1, dp);
        int notBroke = help(n - mid, k, dp);
        int res = max(broke, notBroke);
        ans = min(ans, res + 1);
        if(broke < notBroke){
            l = mid + 1;
        }else{
            h = mid - 1;
        }
    }
    return dp[n][k] = ans;
}
int cutLogs(int k, int n){
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return help(n, k, dp);
}

int main(){
    int k, n;
    cin >> k >> n;
    cout << cutLogs(k, n) << endl;
}
