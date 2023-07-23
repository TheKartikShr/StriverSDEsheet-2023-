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

Node* help(vector<int>& inorder, vector<int>& preorder, unordered_map<int, int>& mp1, int& index, int s, int e){
    if(s == e){
        Node* temp = new Node(preorder[index]);
        index++;
        return temp;
    }
    if(s > e){
        return NULL;
    }
    Node* root = new Node(preorder[index]);
    int curr_index = mp1[preorder[index]];
    index++;
    root -> left = help(inorder, preorder, mp1, index, s, curr_index - 1);
    root -> right = help(inorder, preorder, mp1, index, curr_index + 1, e);
    return root;
}
Node *buildBinaryTree(vector<int> &inorder, vector<int> &preorder){
    unordered_map<int, int> mp1;
    int n = inorder.size();
    for(int i = 0; i < n; i++){
        mp1[inorder[i]] = i;
    }
    int index = 0;
    Node* temp = help(inorder, preorder, mp1, index, 0, n - 1);
    return temp;
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
	vector<int> inorder = {4, 2, 7, 1, 3};
	vector<int> preorder = {1, 2, 4, 7, 3};
	Node* temp = buildBinaryTree(inorder, preorder);
	print(temp);
}

