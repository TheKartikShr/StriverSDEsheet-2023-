#include <bits/stdc++.h>
using namespace std; 

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;
    for(int i = 1; i <= n; i++){
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(dist[u] != 1e9 && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }   
    return dist[dest];
}

int main(){
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	vector<vector<int>> a;
	for(int i = 0; i < m; i++){
		int x1, y1, w;
		cin >> x1 >> y1 >> w;
		a.push_back({x1, y1, w});
	}
	cout << bellmonFord(n, m, x, y, a) << endl;
}

