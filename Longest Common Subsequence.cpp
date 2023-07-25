#include <bits/stdc++.h>
using namespace std; 


int lcs(string s, string t){
	vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
	for(int i = s.size() - 1; i >= 0; i--){
		for(int j = t.size() - 1; j >= 0; j--){
			int ans = 0;
			if(s[i] == t[j]){
				ans = 1 + dp[i + 1][j + 1];
			}else{
				ans = max(dp[i + 1][j], dp[i][j + 1]);
			}
			dp[i][j] = ans;
		}
	}
	return dp[0][0];
}
int main(){
	string s, t;
	cin >> s >> t;
	cout << lcs(s, t) << endl;
}

