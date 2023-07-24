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

int cnt = 0;
void help(int& ans, int k, int& cnt, Node* root){
    if(root == NULL){
        return;
    }
    help(ans, k, cnt, root -> right);
    cnt++;
    if(cnt == k){
        ans = root -> data;
    }
    help(ans, k, cnt, root -> left);
}
int KthLargestNumber(Node* root, int k) {
    int ans = -1;
    cnt = 0;
    help(ans, k, cnt, root);
    return ans;
}


int main(){
	Node* root = new Node(8);
	root -> left = new Node(5);
	root -> right = new Node(10);
	root -> left -> left = new Node(2);
	root -> left -> right = new Node(6);
	root -> left -> right -> right = new Node(7);
	cout << KthLargestNumber(root, 3) << endl;
}

