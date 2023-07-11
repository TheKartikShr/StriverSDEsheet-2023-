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

vector<int> getTopView(Node *root) {
    vector<int> ansvec;
    if(root == NULL){
        return ansvec;
    }
    map<int, int> mp1;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        pair<Node*, int> pq = q.front();
        q.pop();
        Node* temp = pq.first;
        int lvl = pq.second;
        if(mp1.find(lvl) == mp1.end()){
            mp1[lvl] = temp -> data;
        }
        if(temp -> left){
            q.push({temp -> left, lvl - 1});
        }
        if(temp -> right){
            q.push({temp -> right, lvl + 1});
        }
    }
    for(auto it : mp1){
        ansvec.push_back(it.second);
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
	vector<int> curr = getTopView(root);
	for(auto it : curr){
		cout << it << " ";
	}
	cout << endl;
}
