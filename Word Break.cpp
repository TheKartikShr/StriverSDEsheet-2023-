#include <bits/stdc++.h>
using namespace std; 

int n1;
vector<int> dp; 
bool help(int index, string& s, vector<string> &ansvec){
    if(index == n1){
        return true;
    }
    if(dp[index] != -1){
        return dp[index];
    }
    bool ans = false;
    for(auto it : ansvec){
        int sz = it.size();
        if(sz > n1 - index){
            continue;
        }
        string new_word = s.substr(index, sz);
        if(new_word == it){
            ans |= help(index + sz, s, ansvec);
        }
        if(ans == true){
            return ans;
        }
    }
    return dp[index] = ans;
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    n1 = target.size();
    dp = vector<int>(n1, -1);
    return help(0, target, arr);
}
int main(){
	int n;
	cin >> n;
	vector<string> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	string s;
	cin >> s;
	cout << wordBreak(a, n, s) << endl;
}
