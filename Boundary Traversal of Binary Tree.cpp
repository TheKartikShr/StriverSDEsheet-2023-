#include <bits/stdc++.h>
using namespace std; 

struct Node{
    public:
        int data;
        Node* left, *right;
        Node(int data){
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

bool isLeaf(Node* root){
    if(!root -> left && !root -> right){
        return true;
    }
    return false;
}

void addLeft(Node* root, vector<int>& ansvec){
    Node* curr = root -> left;
    while(curr){
        if(!isLeaf(curr)){
            ansvec.push_back(curr -> data);
        }
        if(curr -> left){
            curr = curr -> left;
        }else{
            curr = curr -> right;
        }
    }
}

void addBottom(Node* root, vector<int>& ansvec){
    if(isLeaf(root)){
        ansvec.push_back(root -> data);
        return;
    }
    if(root -> left){
        addBottom(root -> left, ansvec);
    }
    if(root -> right){
        addBottom(root -> right, ansvec);
    }
}

void addRight(Node* root, vector<int>& ansvec){
    Node* curr = root -> right;
    vector<int> temp;
    while(curr){
        if(!isLeaf(curr)){
            temp.push_back(curr -> data);
        }
        if(curr -> right){
            curr = curr -> right;
        }else{
            curr = curr -> left;
        }
    }
    for(int i = temp.size() - 1; i >= 0; i--){
        ansvec.push_back(temp[i]);
    }
}

vector<int> traverseBoundary(Node* root){
    vector<int> ans;
    if(!root){
        return ans;
    }
    if(!isLeaf(root)){
        ans.push_back(root -> data);
    }
    addLeft(root, ans);
    addBottom(root, ans);
    addRight(root, ans);
    return ans;
}

int main(){
    Node* root = new Node(10);
    root -> left = new Node(5);
    root -> right = new Node(20);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(8);
    root -> left -> right -> left = new Node(7);
    root -> right -> right = new Node(25);
    root -> right -> left = new Node(18);
    vector<int> curr = traverseBoundary(root);
    for(auto it : curr){
        cout << it << ' ';
    }
    cout << endl;
}
