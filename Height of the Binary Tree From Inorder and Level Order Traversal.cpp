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

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
	int mx = 0;
	queue<pair<int, pair<int, int>>> q; // height, left_index, right_index
	if(N >= 1){
		q.push({0, {0, N - 1}});
	}
	unordered_map<int, int> mp1;
	for(int i = 0; i < N; i++){
		mp1[inorder[i]] = i;
	}
	for(int i = 0; i < N; i++){
		pair<int, pair<int, int>> pq = q.front();
		q.pop();
		mx = max(mx, pq.first);
		int x = pq.second.first;
		int y = pq.second.second;
		int curr = mp1[levelOrder[i]];
		if(curr - 1 >= x){
			q.push({pq.first + 1, {x, curr - 1}});
		}
		if(curr + 1 <= y){
			q.push({pq.first + 1, {curr + 1, y}});
		}
	}
	return mx;
}


int main(){
	int n;
	cin >> n;
	vector<int> inorder(n), levelOrder(n);
	for(int i = 0; i < n; i++){
		cin >> inorder[i];
	}
	for(int i = 0; i < n; i++){
		cin >> levelOrder[i];
	}
	cout << heightOfTheTree(inorder, levelOrder, n) << endl;
	cout << endl;
	// Node* root = new Node(1);
	// root -> left = new Node(2);
	// root -> right = new Node(3);
	// root -> left -> left = new Node(4);
	// root -> left -> right = new Node(5);
	// root -> right -> left = new Node(6);
	// root -> right -> right = new Node(7);
	// root -> left -> left -> left = new Node(8);
	// root -> left -> left -> right = new Node(9);
	// vector<int> curr = heightOfTheTree(inorder, levelOrder, n);
	// for(auto it : curr){
	// 	cout << it << " ";
	// }
}
