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

void preorder(Node* root, vector<int>& ansvec){
    if(root == NULL){
        return;
    }
    ansvec.push_back(root -> data);
    preorder(root -> left, ansvec);
    preorder(root -> right, ansvec);
}
vector<int> getPreOrderTraversal(Node* root)
{
    vector<int> ansvec;
    preorder(root, ansvec);
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
	vector<int> curr = getPreOrderTraversal(root);
	for(auto it : curr){
		cout << it << " ";
	}
	cout << endl;
}
