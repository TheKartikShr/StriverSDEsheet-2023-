#include <bits/stdc++.h>
using namespace std; 
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){
    vector<vector<int>> ansvec;
    if(intervals.size() == 0){
        return {};
    }
    sort(intervals.begin(), intervals.end());
    vector<int> curr = intervals[0];
    for(auto it : intervals){
        if(it[0] <= curr[1]){
            curr[1] = max(it[1], curr[1]);
        }else{
            ansvec.push_back(curr);
            curr = it;
        }
    }
    ansvec.push_back(curr);
    return ansvec;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<vector<int>> a(2, vector<int>(n));
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
		vector<vector<int>> ansvec1 = mergeIntervals(a);
		for(auto it : ansvec1){
			for(auto i : it){
				cout << i << " ";
			}
			cout << endl;
		}
	}
}