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


void connectNodes(Node *root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            Node* temp = q.front();
            q.pop();
            temp -> next = sz > 0 ? q.front() : NULL;
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}
void print(Node* root){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            cout << temp -> data << " ";
            if(temp -> next == NULL){
            	cout << '#' << " ";
            }else{
            	cout << temp -> next -> data << " ";
            }
            if(temp -> left){
                q.push(temp -> left);
            }
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
	connectNodes(root1);
	print(root1);
}
