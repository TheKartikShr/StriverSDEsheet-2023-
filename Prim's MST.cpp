#include <bits/stdc++.h>
using namespace std; 

vector<pair<pair<int, int>, int>> help(int n, int m, vector<pair<pair<int, int>, int>> &g){
    vector<int>par(n+1,-1);
    vector<int>key(n+1,INT_MAX);
    vector<bool>mst(n+1,false);
    vector<vector<pair<int,int>>>adj(n+1);
    for (auto it:g)
    {
     adj[it.first.first].push_back({it.first.second,it.second});
     adj[it.first.second].push_back({it.first.first,it.second});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    key[1]=0;
    while(!pq.empty())
    {
        auto node=pq.top();
        pq.pop();
        int u=node.second;
        mst[u]=true;
        for (auto it:adj[u])
        {
            int v=it.first;
            int wt=it.second;
            if (mst[v]==false && wt<key[v])
            {
                key[v]=wt;
                par[v]=u;
                pq.push({key[v],v});
            }
        }

    }
    vector<pair<pair<int, int>, int>> ans;
    for (int i=2;i<=n;i++)
    {
        ans.push_back({{i,par[i]},key[i]});
    }
    return ans;
}


int main(){
	int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, int>> a;
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        a.push_back({{x, y}, w});
    }
    vector<pair<pair<int, int>, int>> curr = help(n, m, a);
    for(auto it : curr){
        cout << it.first.second << " " << it.first.first << " " <<  it.second << endl;
    }
}

