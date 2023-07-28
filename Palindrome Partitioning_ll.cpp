#include <bits/stdc++.h>
using namespace std; 

bool isPalindrome(string s){
    int n = s.size();
    for(int i = 0; i < n / 2; i++){
        if(s[i] != s[n - i - 1]){
            return false;
        }
    }
    return true;
}
int palindromePartitioning(string s) {
    int n = s.size();
    vector<int> dp(104, 0);
    for(int i = n - 1; i >= 0; i--){
        int mn = INT_MAX;
        for(int j = i; j < n; j++){
            if(isPalindrome(s.substr(i, j - i + 1))){
                mn = min(mn, 1 + dp[j + 1]);
            }
        }
        dp[i] = mn;
    }
    return dp[0] - 1;
}
int main(){
    string s;
    cin >> s;
    cout << palindromePartitioning(s) << endl;
}


// int help(int index, int n, string& s, vector<int>& dp){
//     if(index == n){
//         return 0;
//     }
//     if(dp[index] != -1){
//         return dp[index];
//     }
//     int mn = INT_MAX;
//     for(int i = index; i < n; i++){
//         if(isPalindrome(s.substr(index, i - index + 1))){
//             mn = min(mn, 1 + help(i + 1, n, s, dp));
//         }
//     }
//     return dp[index] = mn;
// }