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

void changeTree(Node* root) {
    if(root == NULL){
        return;
    }
    int child = 0;
    if(root -> left){
        child += root -> left -> data;
    }
    if(root -> right){
        child += root -> right -> data;
    }
    if(child >= root -> data){
        root -> data = child;
    }else{
        if(root -> left){
            root -> left -> data = root -> data;
        }
        if(root -> right){
            root -> right -> data = root -> data;
        }
    }
    changeTree(root -> left);
    changeTree(root -> right);
    int ans = 0;
    if(root -> left){
        ans += root -> left -> data;
    }
    if(root -> right){
        ans += root -> right -> data;
    }
    if(root -> left || root -> right){ 
        root -> data = ans;
    }
} 
void print(Node* root){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		cout << temp -> data << " ";
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
	changeTree(root1);
	print(root1);
}
