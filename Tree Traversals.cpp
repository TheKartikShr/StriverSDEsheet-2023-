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

void inorder(Node* root, vector<int>& ansvec){
    if(root == NULL){
        return;
    }
    inorder(root -> left, ansvec);
    ansvec.push_back(root -> data);
    inorder(root -> right, ansvec);
}
void preorder(Node* root, vector<int>& ansvec){
    if(root == NULL){
        return;
    }
    ansvec.push_back(root -> data);
    preorder(root -> left, ansvec);
    preorder(root -> right, ansvec);
}
void postorder(Node* root, vector<int>& ansvec){
    if(root == NULL){
        return;
    }
    postorder(root -> left, ansvec);
    postorder(root -> right, ansvec);
    ansvec.push_back(root -> data);
}
vector<vector<int>> getTreeTraversal(Node *root){
    vector<vector<int>> ansvec;
    vector<int> ansvec1, ansvec2, ansvec3;
    inorder(root, ansvec1);
    preorder(root, ansvec2);
    postorder(root, ansvec3);
    ansvec.push_back(ansvec1);
    ansvec.push_back(ansvec2);
    ansvec.push_back(ansvec3);
    return ansvec;
}
int main(){
	Node* root1 = new Node(1);
	root1 -> left = new Node(2);
	root1 -> right = new Node(3);
	root1 -> left -> left = new Node(4);
	root1 -> left -> right = new Node(5);
	root1 -> right -> left = new Node(6);
	root1 -> right -> right = new Node(7);
	root1 -> left -> left -> left = new Node(8);
	root1 -> left -> left -> right = new Node(9);
	vector<vector<int>> curr = getTreeTraversal(root1);
	for(auto i : curr){
		for(auto j : i){
			cout << j << " ";
		}
		cout << endl;
	}
}
