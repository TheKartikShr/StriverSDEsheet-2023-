#include<bits/stdc++.h>

using namespace std;

bool isSafe(int i, int j, int n, vector<vector<int>>& vis, vector<vector<int>>& m){
  if(i >= 0 && j >= 0 && i < n && j < n && m[i][j] == 1 && !vis[i][j]){
    return true;
  }
  return false;
}
void help(int i, int j, int n, vector<vector<int>>& vis, vector<vector<int>>& m, vector<vector<int>>& ansvec){
  if(i == n - 1 && j == n - 1){
    vector<int> ans;
    vis[i][j] = 1;
    for(int i1 = 0; i1 < n; i1++){
      for(int j1 = 0; j1 < n; j1++){
        ans.push_back(vis[i1][j1]);
      }
    }
    vis[i][j] = 0;
    ansvec.push_back(ans);
    return;
  }
  vis[i][j] = 1;
  if(isSafe(i + 1, j, n, vis, m)){
    help(i + 1, j, n, vis, m, ansvec);
  }
  if(isSafe(i, j + 1, n, vis, m)){
    help(i, j + 1, n, vis, m, ansvec);
  }
  if(isSafe(i - 1, j, n, vis, m)){
    help(i - 1, j, n, vis, m, ansvec);
  }
  if(isSafe(i, j - 1, n, vis, m)){
    help(i, j - 1, n, vis, m, ansvec);
  }
  vis[i][j] = 0;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>> vis(n, vector<int>(n, 0));
  vector<vector<int>> ansvec;
  if(maze[0][0] == 0){
    return ansvec;
  }
  help(0, 0, n, vis, maze, ansvec);
  return ansvec;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<vector<int>> maze(n, vector<int>(n));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> maze[i][j];
			}
		}
		vector<vector<int>> curr = ratInAMaze(maze, n);
		for(int i = 0; i < curr.size(); i++){
			for(int j = 0; j < curr.size(); j++){
				cout << curr[i][j] << " ";
			}
			cout << endl;
		}
	}
}