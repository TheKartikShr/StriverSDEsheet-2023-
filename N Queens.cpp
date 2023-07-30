#include <bits/stdc++.h>
using namespace std; 

void psh(int n, vector<vector<int>>& ansvec, vector<vector<int>>& board){
    vector<int> temp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            temp.push_back(board[i][j]);
        }
    }
    ansvec.push_back(temp);
}
bool isSafe(int i, int j, int n, vector<vector<int>>& board){
    int ii = i, jj = j;
    while(i >= 0 && j >= 0){
        if(board[i][j] == 1){
            return false;
        }
        i--, j--;
    }
    i = ii, j = jj;
    while(j >= 0){
        if(board[i][j] == 1){
            return false;
        }
        j--;
    }
    i = ii, j = jj;
    while(i < n && j >= 0){
        if(board[i][j] == 1){
            return false;
        }
        i++, j--;
    }
}
void help(int col, int n, vector<vector<int>>& ansvec, vector<vector<int>>& board){
    if(col == n){
        psh(n, ansvec, board);
        return;
    }
    for(int i = 0; i < n; i++){
        if(isSafe(i, col, n, board)){
            board[i][col] = 1;
            help(col + 1, n, ansvec, board);
            board[i][col] = 0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> a(n, vector<int>(n, 0));
    vector<vector<int>> ansvec;
    help(0, n, ansvec, a);
    return ansvec;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> curr = solveNQueens(n);
    for(auto i : curr){
        for(int j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
