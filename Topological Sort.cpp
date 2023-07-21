#include <bits/stdc++.h>
using namespace std; 



// Topological Sort using Kahn's Algo

// vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
//     vector<vector<int>> adj(v + 1);
//     for (int i = 0; i < e; i++) {
//       adj[edges[i][0]].push_back(edges[i][1]);
//     }
//     vector<int> indegree(v);
//     for(auto i : adj){
//         for(auto j : i){
//             indegree[j]++;
//         }
//     }
//     queue<int> q;
//     for(int i = 0; i < v; i++){
//         if(indegree[i] == 0){
//             q.push(i);
//         }
//     }
//     vector<int> ansvec;
//     while(!q.empty()){
//         int frnt = q.front();
//         q.pop();
//         ansvec.push_back(frnt);
//         for(auto it : adj[frnt]){
//             indegree[it]--;
//             if(indegree[it] == 0){
//                 q.push(it);
//             }
//         }
//     }
//     return ansvec;
// }


// Topological Sort using dfs
void dfs(int node, vector<bool>& vis, stack<int>& s, vector<vector<int>>& adj){
    vis[node] = true;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, vis, s, adj);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>> adj(v + 1);
    for(int i = 0; i < e; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<bool> vis(v + 1, false);
    stack<int> s;
    for(int i = 0; i < v; i++){
        if(!vis[i]){
            dfs(i, vis, s, adj);
        }
    }
    vector<int> ansvec;
    while(!s.empty()){
        ansvec.push_back(s.top());
        s.pop();
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
	vector<int> ans = topologicalSort(a, n, m);
	for(auto it : ans){
		cout << it << ' ';
	}
	cout << endl;
}

