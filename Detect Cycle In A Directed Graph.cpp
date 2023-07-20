#include <bits/stdc++.h>
using namespace std; 

bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj){
  vis[node] = 1;
  pathVis[node] = 1;
  for(auto it : adj[node]){
    if(!vis[it]){
      if(dfs(it, vis, pathVis, adj)){
        return true;
      }
    }else if(pathVis[it]){
      return true;
    }
  }
  pathVis[node] = 0;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  int m = edges.size();
  vector<vector<int>> adj(n + 1);
  vector<int> vis(n + 1, 0), pathVis(n + 1, 0);
  for(int i = 0; i < m; i++){
    adj[edges[i].first].push_back(edges[i].second);
  }
  for(int i = 0; i < n; i++){
    if(!vis[i]){
      if(dfs(i, vis, pathVis, adj)){
        return true;
      }
    }
  }
  return false;
}



int main(){
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		a.push_back({x, y});
	}
	cout << (detectCycleInDirectedGraph(n, a) == 1 ? "YES" : "NO") << endl;
}

