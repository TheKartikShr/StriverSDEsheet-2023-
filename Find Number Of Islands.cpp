#include <bits/stdc++.h>
using namespace std; 

int dx[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
void dfs(int i, int j, int n, int m, vector<vector<int>>& vis, int** arr){
   if(i < 0 || j < 0 || i >= n || j >= m){
      return;
   }
   if(arr[i][j] == 0 || vis[i][j]){
      return;
   }
   vis[i][j] = 1;
   for(int k = 0; k < 8; k++){
      dfs(i + dx[k], j + dy[k], n, m, vis, arr);
   }
}
int getTotalIslands(int** arr, int n, int m)
{
   vector<vector<int>> vis(n, vector<int>(m, 0));
   int cnt = 0;
   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         if(!vis[i][j] && arr[i][j] == 1){
            dfs(i, j, n, m, vis, arr);
            cnt++;
         }
      }
   }
   return cnt;
}


int main(){
	int n, m;
	cin >> n >> m;
	int** arr = new int*[n];
	for(int i = 0; i < n; i++){
		arr[i] = new int[m];
		for(int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	cout << getTotalIslands(arr, n, m) << endl;
}

