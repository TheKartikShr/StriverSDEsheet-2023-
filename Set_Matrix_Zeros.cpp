#include <bits/stdc++.h>

using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == 0){
				for(int k = 0; k < m; k++){
					if(matrix[i][k] != 0){
						matrix[i][k] = -1;
					}
				}
				for(int k = 0; k < n; k++){
					if(matrix[k][j] != 0){
						matrix[k][j] = -1;
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == -1){
				matrix[i][j] = 0;
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		setZeros(matrix);
		for(auto it : matrix){
			for(auto i : it){
				cout << i << " ";
			}
			cout << endl;
		}
	}
}