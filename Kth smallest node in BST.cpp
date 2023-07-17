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


void inorder(Node* root, int &ans, int &k){
    if(root == NULL || k < 0){
        return;
    }
    inorder(root -> left, ans, k);
    k--;
    if(k == 0){
        ans = root -> data;
        return;
    }
    inorder(root -> right, ans, k);
}
int kthSmallest(Node *root, int k){
    int ans = 0;
    inorder(root, ans, k);
    return ans;
}
int main(){
	Node* root1 = new Node(2);
	root1 -> left = new Node(1);
	root1 -> right = new Node(3);
	root1 -> right -> right = new Node(5);
	cout << kthSmallest(root1, 2) << endl;
	// vector<int> ans = getLevelOrder(root1);
	// for(auto it : ans){
	// 	cout << it << " ";
	// }
	// cout << endl;
}
