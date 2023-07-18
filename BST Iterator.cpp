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


class BSTiterator
{
    stack<Node*> s;
    void puush(Node* root){
        while(root != NULL){
            s.push(root);
            root = root -> left;
        }
    }
    public:
        BSTiterator(Node *root){
            puush(root);
        }

        int next(){
            Node* temp = s.top();
            s.pop();
            puush(temp -> right);
            return temp -> data;
        }

        bool hasNext(){
            return !s.empty();
        }
};

int main(){
	Node* root1 = new Node(5);
	root1 -> left = new Node(2);
	root1 -> right = new Node(7);
	root1 -> left -> left = new Node(1);
	root1 -> left -> right = new Node(4);
	root1 -> left -> right -> left = new Node(3);
	root1 -> right -> right = new Node(8);
	root1 -> right -> left = new Node(6);
	BSTiterator* temp = new BSTiterator(root1);
	for(int i = 0;; i++){
		int x;
		cin >> x;
		if(x == 1){
			cout << "Next smallest element in in-order traversal of BST -> " << temp -> next() << endl;
		}else if(x == 2){
			cout << "Is there exists the next smallest element in the traversal -> " << (temp -> hasNext() == 1 ? "YES" : "NO") << endl;
		}else{
			break;
		}
	}
	// vector<int> ans = getLevelOrder(root1);
	// for(auto it : ans){
	// 	cout << it << " ";
	// }
	// cout << endl;
}
