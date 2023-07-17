#include <bits/stdc++.h>
using namespace std; 

struct Node{
	int data;
	Node* left, *right, *next;
	Node(int data){
		this -> data = data;
		this -> left = NULL;
		this -> right = NULL;
		this -> next = NULL;
	}
};


void inorder(Node* root, int x, int& curr){
    if(root == NULL){
        return;
    }
    if(root -> data <= x){
        curr = root -> data;
        inorder(root -> right, x, curr);
    }else{
        inorder(root -> left, x, curr);
    }
}
int floorInBST(Node * root, int X){
    int curr = INT_MAX;
    inorder(root, X, curr);
    return curr;
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
	cout << floorInBST(root1, 4) << endl;
	// vector<int> ans = getLevelOrder(root1);
	// for(auto it : ans){
	// 	cout << it << " ";
	// }
	// cout << endl;
}
