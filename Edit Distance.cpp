#include <bits/stdc++.h>
using namespace std; 


// int help(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
//     if(i == 0){
//         return j;
//     }
//     if(j == 0){
//         return i;
//     }
//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }
//     if(s1[i - 1] == s2[j - 1]){
//         return help(i - 1, j - 1, s1, s2, dp);
//     }
//     return dp[i][j] = 1 + min({help(i - 1, j, s1, s2, dp), help(i, j - 1, s1, s2, dp), help(i - 1, j - 1, s1, s2, dp)});
// }
int editDistance(string str1, string str2){
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int j = 0; j <= m; j++){
        dp[0][j] = j;
    }
    for(int i = 0; i <= n; i++){
        dp[i][0] = i;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }else{
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }
    return dp[n][m];
}

int main(){
	string s1, s2;
	cin >> s1 >> s2;
	cout << editDistance(s1, s2) << endl;
}

