#include<bits/stdc++.h>

using namespace std;

bool isSafe(int i, int j, int matrix[][9], int val){
    for(int k = 0; k < 9; k++){
        if(matrix[i][k] == val){
            return false;
        }
        if(matrix[k][j] == val){
            return false;
        }
        if(matrix[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] == val){
            return false;
        }
    }
    return true;
}
bool isPossible(int matrix[][9]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(matrix[i][j] == 0){
                for(int val = 1; val <= 9; val++){
                    if(isSafe(i, j, matrix, val)){
                        matrix[i][j] = val;
                        bool possible = isPossible(matrix);
                        if(possible){
                            return true;
                        }else{
                            matrix[i][j] = 0;

                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
bool isItSudoku(int matrix[9][9]) {
    return isPossible(matrix);
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int a[9][9];
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				cin >> a[i][j];
			}
		}
		cout << (isPossible(a) == 1 ? "YES" : "NO") << endl;
	}
}