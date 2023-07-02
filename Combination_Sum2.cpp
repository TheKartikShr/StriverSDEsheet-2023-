#include<bits/stdc++.h>

using namespace std;

void help(int index, int target, vector<int> &arr, vector<int>& ans, vector<vector<int>>& ansvec){
	if(target == 0){
		ansvec.push_back(ans);
		return;
	}
	for(int i = index; i < arr.size(); i++){
		if(i > index && arr[i] == arr[i - 1]){
			continue;
		}
		if(arr[i] > target){
			break;
		}
		ans.push_back(arr[i]);
		help(i + 1, target - arr[i], arr, ans, ansvec);
		ans.pop_back();
	}
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	sort(arr.begin(), arr.end());
	vector<vector<int>> ansvec;
	vector<int> ans;
	help(0, target, arr, ans, ansvec);
	return ansvec;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, target;
		cin >> n >> target;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		vector<vector<int>> curr = combinationSum2(a, n, target);
		for(auto it : curr){
			for(auto i : it){
				cout << i << " ";
			}
			cout << endl;
		}
	}
}