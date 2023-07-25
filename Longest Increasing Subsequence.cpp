#include <bits/stdc++.h>
using namespace std; 


int longestIncreasingSubsequence(int arr[], int n){
    vector<int> dp;
    int ans = 1;
    dp.push_back(arr[0]);
    for(int i = 1; i < n; i++){
        if(arr[i] > dp.back()){
            dp.push_back(arr[i]);
        }else{
            int index = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            dp[index] = arr[i];
        }
    }
    for(auto it : dp){
    	cout << it << " ";
    }
    cout << endl;
    return dp.size();
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << longestIncreasingSubsequence(arr, n) << endl;
}

