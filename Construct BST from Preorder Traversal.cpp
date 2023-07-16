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


Node* build(vector<int>& preOrder, int &i, int bound){
    if(i == preOrder.size() || preOrder[i] > bound){
        return NULL;
    }
    Node* root = new Node(preOrder[i++]);
    root -> left = build(preOrder, i, root -> data);
    root -> right = build(preOrder, i, bound);
    return root;
}
Node* preOrderTree(vector<int> &preOrder){
    int i = 0;
    return build(preOrder, i, INT_MAX);
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
	vector<int> preOrder = {10, 5, 1, 7, 40, 50};
	Node* temp = preOrderTree(preOrder);
	print(temp);
	// Node* root1 = new Node(1);
	// root1 -> left = new Node(2);
	// root1 -> right = new Node(3);
	// root1 -> left -> left = new Node(4);
	// root1 -> left -> right = new Node(5);
	// root1 -> right -> left = new Node(6);
	// root1 -> right -> right = new Node(7);
	// root1 -> left -> left -> left = new Node(8);
	// root1 -> left -> left -> right = new Node(9);
}
