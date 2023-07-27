#include <bits/stdc++.h>
using namespace std; 

// bool help(int index, int target, int n, vector<int> &a, vector<vector<int>>& dp){
//     if(target == 0){
//         return true;
//     }
//     if(index == 0){
//         return a[0] == target;
//     }
//     if(dp[index][target] != -1){
//         return dp[index][target];
//     }
//     bool notTake = help(index - 1, target, n, a, dp);
//     bool take = false;
//     if(target >= a[index]){
//         take = help(index - 1, target - a[index], n, a, dp);
//     }
//     return dp[index][target] = take | notTake;
// }
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(k+1,vector<int> (n,0));
    for(int j=0;j<n;j++){
        dp[0][j]=1;
    }
    for(int i=1;i<=k;i++){
        if(i==arr[0])
        dp[i][0]=1;
    }
    for(int j=1;j<n;j++){
        for(int i=1;i<=k;i++){
            int nottake = dp[i][j-1];
            int take = 0;
            if(i-arr[j]>=0){
                take = dp[i-arr[j]][j-1];
            }
            if(take==1||nottake==1){
                dp[i][j]=1;
            }
        }
    }
    return dp[k][n-1];
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << (subsetSumToK(n, k, a) == 1 ? "YES" : "NO") << endl;
}

