#include <bits/stdc++.h>
using namespace std; 

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void dfs(int x, int y, int newColor, int inicolor, vector<vector<int>>& ans, vector<vector<int>>&image){
    int n = ans.size(), m = ans[0].size();
    ans[x][y] = newColor;
    for(int i = 0; i < 4; i++){
        int new_x = dx[i] + x;
        int new_y = dy[i] + y;
        if(new_x >= 0 && new_y >= 0 && new_x < n && new_y < m && image[new_x][new_y] == inicolor && ans[new_x][new_y] != newColor){
            dfs(new_x, new_y, newColor, inicolor, ans, image);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor){
    int inicolor = image[x][y];
    vector<vector<int>> ans = image;
    dfs(x, y, newColor, inicolor, ans, image);
    return ans;
}
int main(){
	int n, m, x, y, c;
	cin >> n >> m >> x >> y >> c;
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	vector<vector<int>> curr = floodFill(a, x, y, c);
	for(auto i : curr){
		for(auto j : i){
			cout << j << " ";
		}
		cout << endl;
	}
}

