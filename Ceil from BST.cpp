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

int findCeil(Node *node, int x){
    int ans = -1;
    while(node){
        if(node -> data < x){
            node = node -> right;
        }else{
            ans = node -> data;
            node = node -> left;
        }
    }
    return ans;
}


int main(){
	Node* root = new Node(8);
	root -> left = new Node(5);
	root -> right = new Node(10);
	root -> left -> left = new Node(2);
	root -> left -> right = new Node(6);
	root -> left -> right -> right = new Node(7);
	cout << findCeil(root, 3) << endl;
}

