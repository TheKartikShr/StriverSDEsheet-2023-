#include <bits/stdc++.h>
using namespace std; 

class Node{
	public:
		int data;
		Node* left, *right;
		Node(int data){
			this -> data = data;
			this -> left = NULL;
			this -> right = NULL;
		}
};

bool help(Node* root, int x){
    if(root == NULL){
        return false;
    }
    if (root->data == x) {
        return true;
    }
    bool left = help(root -> left, x);
    bool right = help(root -> right, x);
    return left || right;
}
bool searchInBST(Node *root, int x) {
    return help(root, x);
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
	Node* root = new Node(4);
	root -> left = new Node(2);
	root -> right = new Node(6);
	root -> left -> left = new Node(1);
	root -> left -> right = new Node(3);
	root -> right -> right = new Node(7);
	root -> right -> left = new Node(5);
	cout << (searchInBST(root, 5) == 1 ? "YES" : "NO") << endl;
}

