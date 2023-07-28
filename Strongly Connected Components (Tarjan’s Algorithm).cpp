#include <bits/stdc++.h>
using namespace std; 

void dfs1(int node, vector<int>& vis, stack<int>& s, vector<int> adj[]){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs1(it, vis, s, adj);
        }
    }
    s.push(node);
}
void dfs2(int node, vector<int>& vis, vector<int> adjT[], vector<int>& ans){
    vis[node] = 1;
    for(auto it : adjT[node]){
        if(!vis[it]){
            dfs2(it, vis, adjT, ans);
        }
    }
    ans.push_back(node);
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges){
    vector<int> adj[n];
    int m = edges.size();
    for(int i = 0; i < m; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> vis(n, 0);
    stack<int> s;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs1(i, vis, s, adj);
        }
    }
    vector<int> adjT[n];
    for(int i = 0; i < n; i++){
        vis[i] = 0;
        for(auto it : adj[i]){
            adjT[it].push_back(i);
        }
    }
    vector<vector<int>> ansvec;
    while(!s.empty()){
        vector<int> ans;
        int node = s.top();
        s.pop();
        if(!vis[node]){
            dfs2(node, vis, adjT, ans);
        }
        ansvec.push_back(ans);
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
	vector<vector<int>> curr = stronglyConnectedComponents(n, a);
	for(auto i : curr){
		for(auto j : i){
			cout << j << " ";
		}
		cout << endl;
	}
}

