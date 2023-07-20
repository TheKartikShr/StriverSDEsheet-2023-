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

void help(Node* root, Node* &head, Node* &prev){
    if(!root){
        return;
    }
    help(root -> left, head, prev);
    if(head == NULL){
        head = root;
        prev = root;
    }else{
        prev -> right = root;
        root -> left = prev;
    }
    prev = root;
    help(root -> right, head, prev);
}
Node* BTtoDLL(Node* root) {
    Node* head = NULL;
    Node* prev = NULL;
    help(root, head, prev);
    return head;
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
	Node* head = BTtoDLL(root);
	while(head != NULL){
		cout << head -> data << " ";
		head = head -> right;
	}
	// print(head);
}
