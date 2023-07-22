#include <bits/stdc++.h>
using namespace std; 

vector<int> dijkstra(vector<vector<int>> &vec, int n, int m, int source) {
    vector<pair<int, int>> adj[n];
    for(int i = 0; i < m; i++){
        int x = vec[i][0], y = vec[i][1], w = vec[i][2];
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0;
    pq.push({0, source});
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it : adj[node]){
            pair<int, int> q = it;
            int w = q.second;
            int adjNode = q.first;
            if(dis + w < dist[adjNode]){
                dist[adjNode] = dis + w;
                pq.push({dist[adjNode], adjNode});
            }
        }
    } 
    return dist;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a;
	for(int i = 0; i < m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		a.push_back({x, y, w});
	}
	vector<int> curr = dijkstra(a, n, m, 0);
	for(auto it : curr){
		cout << it << " ";
	}
	cout << endl;
}

