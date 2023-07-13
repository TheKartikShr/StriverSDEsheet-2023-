#include <bits/stdc++.h>
using namespace std; 

struct Node{
	int data;
	Node* left, *right;
	Node(int data){
		this -> data = data;
		this -> left = NULL;
		this -> right = NULL;
	}
};

vector<int> verticalOrderTraversal(Node *root)
{
    map<int, map<int, vector<int>>> mp1; // map<hd, map<lvl, root -> data>>
    vector<int> ansvec;
    if(root == NULL){
        return ansvec;
    }
    queue<pair<Node*, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while(!q.empty()){
        pair<Node*, pair<int, int>> pq = q.front();
        q.pop();
        Node* temp = pq.first;
        int hd = pq.second.first;
        int lvl = pq.second.second;
        mp1[hd][lvl].push_back(temp -> data);
        if(temp -> left){
            q.push({temp -> left, {hd - 1, lvl + 1}});
        }
        if(temp -> right){
            q.push({temp -> right, {hd + 1, lvl + 1}});
        }
    }
    for(auto i : mp1){
        for(auto j : i.second){
            for(auto k : j.second){
                ansvec.push_back(k);
            }
        }
    }
    return ansvec;
}


int main(){
	Node* root = new Node(1);
	root -> left = new Node(2);
	root -> right = new Node(3);
	root -> left -> left = new Node(4);
	root -> left -> right = new Node(5);
	root -> right -> left = new Node(6);
	root -> right -> right = new Node(7);
	root -> left -> left -> left = new Node(8);
	root -> left -> left -> right = new Node(9);
	vector<int> curr = verticalOrderTraversal(root);
	for(auto it : curr){
		cout << it << " ";
	}
	cout << endl;
}
