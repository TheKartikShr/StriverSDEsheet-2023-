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

Node* solver(vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &hash, int &index, int start, int end){
    if(start == end){
        Node* root;
        root = new Node(postorder[index]);
        index--;
        return root;
    }
    if(start > end || end < 0) return NULL;
    
    Node* root;
    root = new Node(postorder[index]);
    int mid = hash[postorder[index]];
    index--;
    root->right = solver(inorder, postorder, hash, index, mid + 1, end);
    root->left = solver(inorder, postorder, hash, index, start, mid-1);
    return root;
}


Node* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
    int n = postOrder.size();
    unordered_map<int, int> hash;
    for(int i = 0; i < n; i++){
        hash[inOrder[i]] = i;
    }
    int index = n - 1;
    return solver(inOrder, postOrder, hash, index, 0, n - 1);
}

void print(Node* root){
	if(root == NULL){
		return;
	}
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
	int n;
	cin >> n;
	vector<int> inOrder(n), postorder(n);
	for(int i = 0; i < n; i++){
		cin >> inOrder[i];
	}
	for(int i = 0; i < n; i++){
		cin >> postorder[i];
	}
	Node* root = getTreeFromPostorderAndInorder(inOrder, postorder);
	print(root);
	// vector<int> curr = heightOfTheTree(inorder, levelOrder, n);
	// for(auto it : curr){
	// 	cout << it << " ";
	// }
	// Node* root1 = new Node(1);
	// root1 -> left = new Node(2);
	// root1 -> right = new Node(3);
	// root1 -> left -> left = new Node(4);
	// root1 -> left -> right = new Node(5);
	// root1 -> right -> left = new Node(6);
	// root1 -> right -> right = new Node(7);
	// root1 -> left -> left -> left = new Node(8);
	// root1 -> left -> left -> right = new Node(9);
	// cout << (identicalTrees(root1, root2) == 1 ? "YES" : "NO") << endl;
}
