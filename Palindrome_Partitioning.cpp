#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string s, int i, int j){
    while(i <= j){
        if(s[i++] != s[j--]){
            return false;
        }
    }
    return true;
}
void help(int index, string s, vector<string>& path, vector<vector<string>>& ans){
    if(index == s.size()){
        ans.push_back(path);
        return;
    }
    for(int i = index; i < s.size(); i++){
        if(isPalindrome(s, index, i)){
            path.push_back(s.substr(index, i - index + 1));
            help(i + 1, s, path, ans);
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s){
    vector<vector<string>> ans;
    vector<string> path;
    help(0, s, path, ans);
    return ans;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		vector<vector<string>> vs = partition(s);
		for(auto it : vs){
			for(auto i : it){
				cout << i << ", ";
			}
			cout << endl;
		}
	}
}