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

pair<bool, int> help(Node* root){
    if(root == NULL){
        pair<bool, int> p = {true, 0};
        return p;
    }
    pair<bool, int> left = help(root -> left);
    pair<bool, int> right = help(root -> right);
    bool leftans = left.first;
    bool rightans = right.first;
    bool diff = abs(left.second - right.second) <= 1;
    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
    if(leftans && rightans && diff){
        ans.first = true;
    }else{
        ans.first = false;
    }
    return ans;
}
bool isBalancedBT(Node* root) {
    return help(root).first;
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
	cout << (isBalancedBT(root) == 1 ? "YES" : "NO") << endl;
	// vector<int> curr = heightOfTheTree(inorder, levelOrder, n);
	// for(auto it : curr){
	// 	cout << it << " ";
	// }
}
