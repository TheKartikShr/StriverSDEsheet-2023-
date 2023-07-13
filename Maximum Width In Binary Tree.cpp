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

int getMaxWidth(Node* root)
{
    map<int, vector<int>> mp1;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    vector<int> ansvec;
    if(root == NULL){
        return 0;
    }
    while(!q.empty()){
        pair<Node*, int> pq = q.front();
        q.pop();
        Node* temp = pq.first;
        int lvl = pq.second;
        mp1[lvl].push_back(temp -> data);
        if(temp -> left != NULL){
            q.push({temp -> left, lvl + 1});
        }
        if(temp -> right != NULL){
            q.push({temp -> right, lvl + 1});
        }
    }
    int mx = 0;
    for(auto i : mp1){
        mx = max(mx, (int)i.second.size());
    }
    return mx;
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
	cout << getMaxWidth(root) << endl;
	// vector<int> curr = (root);
	// for(auto it : curr){
	// 	cout << it << " ";
	// }
	cout << endl;
}
