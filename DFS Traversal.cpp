#include <bits/stdc++.h>
using namespace std; 

void dfs(int node, vector<int>& curr, vector<int>& vis, vector<int> adj[]){
    vis[node] = true;
    curr.push_back(node);
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, curr, vis, adj);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges){
    vector<int> adj[V + 1];
    for(int i = 0; i < E; i++){
       adj[edges[i][0]].push_back(edges[i][1]);
       adj[edges[i][1]].push_back(edges[i][0]); 
    }
    vector<int> vis(V + 1, false);
    vector<vector<int>> ansvec;
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            vector<int> curr;
            dfs(i, curr, vis, adj);
            sort(curr.begin(), curr.end());
            ansvec.push_back(curr);
        }
    }
    return ansvec;
}
int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		a.push_back({x, y});
	}
	vector<vector<int>> curr = depthFirstSearch(n, m, a);
	cout << curr.size() << endl;
	for(auto i : curr){
		for(auto j : i){
			cout << j << ' ';
		}
		cout << endl;
	}
}
