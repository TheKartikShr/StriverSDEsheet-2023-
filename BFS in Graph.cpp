#include <bits/stdc++.h>
using namespace std; 


class Node{
	public:
		int data;
		Node* left, *right;
		Node(int data){
			this -> data = data;
			this -> left = NULL;
			this -> right = NULL;
		}
};

void bfs(int node, vector<int>& ans, vector<int>& vis, vector<int> adj[]){
    vis[node] = 1;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for(auto it : adj[curr]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
} 
vector<int> BFS(int n, vector<pair<int, int>> edges)
{
    int m = edges.size();
    vector<int> adj[n + 1];
    for(int i = 0; i < m; i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 
    for(int i = 0; i < n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    vector<int> vis(n, 0);
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            bfs(i, ans, vis, adj);
        }
    }
    return ans;
}


int main(){
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> vp;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		vp.push_back({x, y});
	}
	vector<int> ans = BFS(n, vp);
	for(auto it : ans){
		cout << it << " ";
	}
	cout << endl;
}

