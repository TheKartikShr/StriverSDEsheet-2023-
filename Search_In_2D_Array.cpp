#include <bits/stdc++.h>
using namespace std; 

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();
    for(int i = 0; i < n; i++){
        auto it = lower_bound(mat[i].begin(), mat[i].end(), target);
        if(it != mat[i].end() && *it == target){
            return true;
        }
    }
    return false;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m, target;
		cin >> n >> m >> target;
		vector<vector<int>> a(n, vector<int>(m));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> a[i][j];
			}
		}
		cout <<  (searchMatrix(a, target) == 1 ? "true" : "false") << endl;
	}
}