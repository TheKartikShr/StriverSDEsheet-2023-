#include <bits/stdc++.h>
using namespace std; 

bool dfs(int node,int parent,vector<vector<int>> &adj,vector<int> &vis){
    vis[node] =1;
    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfs(it,node,adj,vis))return true;
        }
        else if(it!=parent)return true;
    }
    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    vector<vector<int>> adj(n + 1);
    vector<int> vis(n + 1, 0);
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if(!vis[i] && dfs(i,-1,adj,vis))return "Yes";
    }
    return "No";
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
	cout << cycleDetection(a, n, m) << endl;
}

