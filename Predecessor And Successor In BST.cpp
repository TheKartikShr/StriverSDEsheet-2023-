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

pair<int,int> predecessorSuccessor(Node* root, int key){
    int suc = -1, pre = -1;
    Node* copy = root;
    while(root){
        if(key >= root -> data){
            root = root -> right;
        }else{
            suc = root -> data;
            root = root -> left;
        }
    }
    root = copy;
    while(root){
        if(key <= root -> data){
            root = root -> left;
        }else{
            pre = root -> data;
            root = root -> right;
        }
    }
    return {pre, suc};
}


int main(){
	Node* root = new Node(8);
	root -> left = new Node(5);
	root -> right = new Node(10);
	root -> left -> left = new Node(2);
	root -> left -> right = new Node(6);
	root -> left -> right -> right = new Node(7);
	pair<int, int> curr = predecessorSuccessor(root, 10);
	cout << curr.first << " " << curr.second << endl;
}

