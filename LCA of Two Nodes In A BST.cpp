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


Node* help(Node* root, int x, int y){
    if(root == NULL){
        return NULL;
    }
    if(root -> data == x || root -> data == y){
        return root;
    }
    Node* l = help(root -> left, x, y);
    Node* r = help(root -> right, x, y);
    if(l && r){
        return root;
    }else if(l && !r){
        return l;
    }else if(!l && r){
        return r;
    }else{
        return NULL;
    }
}
Node* LCAinaBST(Node* root, Node* P, Node* Q)
{
	int x = P -> data;
    int y = Q -> data;
    return help(root, x, y);
}
int main(){
	Node* root1 = new Node(2);
	root1 -> left = new Node(1);
	root1 -> right = new Node(3);
	root1 -> right -> right = new Node(5);
	cout << LCAinaBST(root1, new Node(3), new Node(5)) -> data << endl;
	// vector<int> ans = getLevelOrder(root1);
	// for(auto it : ans){
	// 	cout << it << " ";
	// }
	// cout << endl;
}
