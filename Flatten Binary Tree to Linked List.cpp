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

Node *flattenBinaryTree(Node *root){
    Node* curr = root;
    while(curr != NULL){
        if(curr -> left){
            Node* prev = curr -> left;
            while(prev -> right){
                prev = prev -> right;
            }
            prev -> right = curr -> right;
            curr -> right = curr -> left;
        }
        curr = curr -> right;
    }
    return root;
}
void print(Node* root){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		cout << temp -> data << " ";
		if(temp -> right){
			q.push(temp -> right);
		}
	}
	cout << endl;
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
	Node* temp = flattenBinaryTree(root1);
	print(temp);
}
