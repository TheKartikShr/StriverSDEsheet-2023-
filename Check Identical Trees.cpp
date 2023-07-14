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

bool identicalTrees(Node* root1, Node* root2) {
    if(root1 == NULL || root2 == NULL){
        return root1 == root2;
    } 
    if(root1 -> data == root2 -> data){
        return identicalTrees(root1 -> left, root2 -> left) && identicalTrees(root1 -> right, root2 -> right);
    }
    return false;
}


int main(){
	Node* root1 = new Node(1);
	Node* root2 = new Node(1);
	root1 -> left = new Node(2);
	root1 -> right = new Node(3);
	root1 -> left -> left = new Node(4);
	root1 -> left -> right = new Node(5);
	root1 -> right -> left = new Node(6);
	root1 -> right -> right = new Node(7);
	root1 -> left -> left -> left = new Node(8);
	root1 -> left -> left -> right = new Node(9);
	root2 -> left = new Node(2);
	root2 -> right = new Node(3);
	root2 -> left -> left = new Node(4);
	root2 -> left -> right = new Node(5);
	root2 -> right -> left = new Node(6);
	root2 -> right -> right = new Node(7);
	root2 -> left -> left -> left = new Node(8);
	root2 -> left -> left -> right = new Node(9);
	cout << (identicalTrees(root1, root2) == 1 ? "YES" : "NO") << endl;
	// vector<int> curr = heightOfTheTree(inorder, levelOrder, n);
	// for(auto it : curr){
	// 	cout << it << " ";
	// }
}
