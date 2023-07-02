#include<bits/stdc++.h>

using namespace std;

bool isSafe(int node, int n, int color[], vector<vector<int>>& mat, int curr_col){
    for(int k = 0; k < n; k++){
        if(k != node && mat[k][node] == 1 && color[k] == curr_col){
            return false;
        }
    }
    return true;
}
bool solve(int node, int n, int m, int color[], vector<vector<int>>& mat){
    if(node == n){
        return true;
    }
    for(int i = 1; i <= m; i++){
        if(isSafe(node, n, color, mat, i)){
            color[node] = i;
            if(solve(node + 1, n, m, color, mat)){
                return true;
            }
            color[node] = 0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    int color[n] = {0};
    if(solve(0, n, m, color, mat)){
        return "YES";
    }
    return "NO";
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(n));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
		cout << graphColoring(a, m) << endl;
	}
}