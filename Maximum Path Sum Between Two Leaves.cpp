#include <bits/stdc++.h>
using namespace std; 

struct Node{
    public:
        int val;
        Node* left, *right;
        Node(int val){
            this -> val = val;
            this -> left = NULL;
            this -> right = NULL;
        }
};

long long int help(Node* root, long long int& mx){
    if(root == NULL){
        return 0;
    }
    long long int left_sum = max(0ll, help(root -> left, mx));
    long long int right_sum = max(0ll, help(root -> right, mx));
    mx = max(mx, root -> val + (left_sum + right_sum));
    return root -> val + max(left_sum, right_sum);
}

long long int findMaxSumPath(Node *root)
{
    if(!root){
        return -1;
    }
    if(!root -> left || !root -> right){
        return -1;
    }
    long long int mx = INT_MIN;
    help(root, mx);
    return mx;
}

int main(){
    Node* root = new Node(5);
    root -> left = new Node(6);
    root -> right = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(3);
    root -> left -> left -> left = new Node(9);
    root -> left -> left -> left = new Node(9);
    root -> left -> left -> right = new Node(7);
    cout << findMaxSumPath(root);
}
