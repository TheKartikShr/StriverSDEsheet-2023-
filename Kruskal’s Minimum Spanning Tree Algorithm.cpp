#include <bits/stdc++.h>
using namespace std; 

class DisjointSet{
	vector<int> rank, parent;
	public:
		DisjointSet(int n){
			rank.resize(n + 1, 0);
			parent.resize(n + 1);
			for(int i = 0; i <= n; i++){
				parent[i] = i;
			}
		}

		int findParent(int node){
			if(node == parent[node]){
				return node;
			}
			return parent[node] = findParent(parent[node]);
		}

		void UnionByRank(int u, int v){
			int ulp_u = findParent(u);
			int ulp_v = findParent(v);
			if(ulp_u == ulp_v){
				return;
			}
			if(rank[ulp_u] < rank[ulp_v]){
				parent[ulp_u] = ulp_v;
			}else if(rank[ulp_u] > rank[ulp_v]){
				parent[ulp_v] = ulp_u;
			}else{
				parent[ulp_v] = ulp_u;
				rank[ulp_u]++;
			}
		}

};

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	vector<pair<int, pair<int, int>>> vp;
	for(int i = 0; i < m; i++){
		int x = graph[i][0];
		int y = graph[i][1];
		int w = graph[i][2];
		vp.push_back({w, {x, y}});
	}
	DisjointSet ds(n);
	sort(vp.begin(), vp.end());
	int mn = 0;
	for(auto it : vp){
		int w = it.first;
		int u = it.second.first;
		int v = it.second.second;
		if(ds.findParent(u) != ds.findParent(v)){
			mn += w;
			ds.UnionByRank(u, v);
		}
	}
	return mn;
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
	cout << kruskalMST(n, m, a) << endl;
}

