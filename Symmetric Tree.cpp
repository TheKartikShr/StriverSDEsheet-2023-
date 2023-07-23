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

bool isPalindrome(vector<int>& curr){
    int n = curr.size();
    for(int i = 0; i < n / 2; i++){
        if(curr[i] != curr[n - i - 1]){
            return false;
        }
    }
    return true;
}
bool isSymmetric(Node* root){
    if(root == NULL){
        return true;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> curr;
        int sz = q.size();
        while(sz-->0){
            Node* temp = q.front();
            q.pop();
            curr.push_back(temp -> data);
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
        if(!isPalindrome(curr)){
            return false;
        }
    }
    return true;
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
	Node* root = new Node(1);
	root -> left = new Node(2);
	root -> right = new Node(3);
	root -> left -> left = new Node(4);
	cout << (isSymmetric(root) == 1 ? "YES" : "NO") << endl;
}

