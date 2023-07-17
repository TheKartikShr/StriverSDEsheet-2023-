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


pair<int, int> help(Node* root){
    if(root == NULL){
        pair<int, int> p = {0, 0};
        return p;
    }
    pair<int, int> leftt = help(root -> left);
    pair<int, int> rightt = help(root -> right);
    int height = leftt.second + rightt.second + 1;
    pair<int, int> ans = {max({(int)leftt.first, (int)rightt.first, height}), max(leftt.second, rightt.second) + 1};
    return ans;
}
int diameterOfBinaryTree(Node *root){
    return help(root).first - 1;
}

// void print(Node* root){
// 	queue<Node*> q;
// 	q.push(root);
// 	while(!q.empty()){
//             Node* temp = q.front();
//             q.pop();
//             cout << temp -> data << " ";
//             if(temp -> next == NULL){
//             	cout << '#' << " ";
//             }else{
//             	cout << temp -> next -> data << " ";
//             }
//             if(temp -> left){
//                 q.push(temp -> left);
//             }
//             if(temp -> right){
//                 q.push(temp -> right);
//             }
// 	}
// 	cout << endl;
// }
void print(Node* root){
	if(root == NULL){
		return;
	}
	print(root -> left);
	cout << root -> data << " ";
	print(root -> right);
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
	cout << diameterOfBinaryTree(root1) << endl;
	// vector<int> ans = getLevelOrder(root1);
	// for(auto it : ans){
	// 	cout << it << " ";
	// }
	// cout << endl;
}
