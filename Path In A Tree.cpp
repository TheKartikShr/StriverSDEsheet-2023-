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

bool help(Node* root, int x, vector<int>& ansvec){
	if(!root){
		return false;
	}
	ansvec.push_back(root -> data);
	if(root -> data == x){
		return true;
	}
	if(help(root -> left, x, ansvec) || help(root -> right, x, ansvec)){
		return true;
	}
	ansvec.pop_back();
	return false;
}
vector<int> pathInATree(Node *root, int x)
{
    vector<int> ansvec;
	bool f = help(root, x, ansvec);
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
	vector<int> curr = pathInATree(root, 8);
	for(auto it : curr){
		cout << it << " ";
	}
	cout << endl;
}
