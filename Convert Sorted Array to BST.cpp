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

Node* help(int start, int end, vector<int>&arr){
    if(start > end) return NULL;
    int mid=(start + end) / 2;
    Node* root= new Node(arr[mid]);
    root -> left = help(start, mid - 1, arr);
    root -> right = help(mid + 1, end, arr);
    return root;
}
Node* sortedArrToBST(vector<int> &arr, int n){
    return help(0, n - 1, arr);
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
	vector<int> a = {1, 2, 3, 4, 5};
	Node* root = sortedArrToBST(a, 5);
	print(root);
}

