#include<bits/stdc++.h>

using namespace std;

const int N = 610;
const int inf = 1e9;
int dist[N][N];
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j){
                dist[i][j] = 0;
            }else{
                dist[i][j] = inf;
            }
        }
    }
    for(int i = 0; i < m; i++){
        int x = edges[i][0];
        int y = edges[i][1];
        int wt = edges[i][2];
        dist[x][y] = wt;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dist[i][k] != 1e9 && dist[k][j] != 1e9){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    return dist[src][dest];
}
int main(){
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	vector<vector<int>> edges(m, vector<int>(3));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < 3; j++){
			cin >> edges[i][j];
		}
	}
	cout << floydWarshall(n, m, x, y, edges) << endl;
}