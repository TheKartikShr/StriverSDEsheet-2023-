#include <bits/stdc++.h>
using namespace std; 
void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int row = 0, col = 0, prev_row = n, prev_col = m, x, y;
    while(row < prev_row && col < prev_col){
        if(row + 1 == prev_row || col + 1 == prev_col){
            break;
        }
        x = mat[row + 1][col];
        for(int i = col; i < prev_col; i++){
            y = mat[row][i];
            mat[row][i] = x;
            x = y;
        }
        row++;
        for(int i = row; i < prev_row; i++){
            y = mat[i][prev_col - 1];
            mat[i][prev_col - 1] = x;
            x = y;
        }
        prev_col--;
        if(row < prev_row){
            for(int i = prev_col - 1; i >= col; i--){
                y = mat[prev_row - 1][i];
                mat[prev_row - 1][i] = x;
                x = y;
            } 
        }
        prev_row--;
        if(col < prev_col){
            for(int i = prev_row - 1; i >= row; i--){
                y = mat[i][col];
                mat[i][col] = x;
                x = y;
            }
        }
        col++;
    }

}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> a[i][j];
			}
		}
		rotateMatrix(a, n, m);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
}