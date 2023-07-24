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

void inorder(Node* root, vector<int>& ansvec){
    if(root == NULL){
        return;
    }
    inorder(root -> left, ansvec);
    ansvec.push_back(root -> data);
    inorder(root -> right, ansvec);
}
bool pairSumBst(Node *root, int k){
    vector<int> ansvec;
    inorder(root, ansvec);
    vector<pair<int, int>> vp;
    for(int i = 0; i < ansvec.size(); i++){
        vp.push_back({ansvec[i], i});
    }
    int i = 0, j = ansvec.size() - 1;
    while(i < j){
        if(vp[i].first + vp[j].first == k){
            return true;
        }
        if(vp[i].first + vp[j].first > k){
            j--;
        }else{
            i++;
        }
    }
    return false;
}


int main(){
	Node* root = new Node(8);
	root -> left = new Node(5);
	root -> right = new Node(10);
	root -> left -> left = new Node(2);
	root -> left -> right = new Node(6);
	root -> left -> right -> right = new Node(7);
	cout << (pairSumBst(root, 13) == 1 ? "YES" : "NO") << endl;
}

