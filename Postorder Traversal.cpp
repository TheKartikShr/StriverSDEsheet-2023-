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

void postorder(Node* root, vector<int>& ansvec){
    if(root == NULL){
        return;
    }
    postorder(root -> left, ansvec);
    postorder(root -> right, ansvec);
    ansvec.push_back(root -> data);
}
vector<int> getPostOrderTraversal(Node* root)
{
    vector<int> ansvec;
    postorder(root, ansvec);
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
	vector<int> curr = getPostOrderTraversal(root);
	for(auto it : curr){
		cout << it << " ";
	}
	cout << endl;
}
