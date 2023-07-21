#include <bits/stdc++.h>
using namespace std; 


struct graphNode{
	int data;
	vector<graphNode*> neighbours;
	graphNode(){
		data = 0;
		neighbours = vector<graphNode*>();
	}
	graphNode(int val){
		data = val;
		neighbours = vector<graphNode*>();
	}
};


graphNode* rec(graphNode* node,map<graphNode*,graphNode*>&mp)
{
	graphNode* newNode= new graphNode(node->data);
	mp[node]=newNode;
	vector<graphNode*>v;
	for (auto it: node->neighbours)
	{
		if (mp.find(it)!=mp.end())
		{
			v.push_back(mp[it]);
		}
		else v.push_back(rec(it,mp));
	}
	newNode->neighbours=v;
	return newNode;
	
}
graphNode *cloneGraph(graphNode *node)
{
    map<graphNode*,graphNode*>mp;
	return rec(node,mp);
}


void bfs(graphNode* node){
	map<graphNode*, bool> mp1;
	queue<graphNode*> q;
	q.push(node);
	mp1[node] = true;
	while(!q.empty()){
		graphNode* newnode = q.front();
		q.pop();
		cout << newnode -> data << " ";
		vector<graphNode*> temp = newnode -> neighbours;
		for(int i = 0; i < temp.size(); i++){
			if(!mp1[temp[i]]){
				mp1[temp[i]] = true;
				q.push(temp[i]);
			}
		}
	}
	cout << endl;
}

int main(){
	graphNode *node1 = new graphNode();
    node1->data = 1;
    graphNode *node2 = new graphNode();
    node2->data = 2;
    graphNode *node3 = new graphNode();
    node3->data = 3;
    graphNode *node4 = new graphNode();
    node4->data = 4;
    vector<graphNode *> v;
    v.push_back(node2);
    v.push_back(node4);
    node1->neighbours = v;
    v.clear();
    v.push_back(node1);
    v.push_back(node3);
    node2->neighbours = v;
    v.clear();
    v.push_back(node2);
    v.push_back(node4);
    node3->neighbours = v;
    v.clear();
    v.push_back(node3);
    v.push_back(node1);
    node4->neighbours = v;
    graphNode* before = node1;
    cout << "Graph before cloning: ";
    bfs(before);
    graphNode* temp = cloneGraph(node1);
    cout << "Graph after cloning: ";
    bfs(temp);
}

