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


string serializeTree(Node *root){
    if(!root){
        return "";
    }
    string s = "";
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            s.append("#,");
        }else{
            s.append(to_string(temp -> data) + ',');
        }
        if(temp != NULL){
            q.push(temp -> left);
            q.push(temp -> right);
        }
    }
    return s;
}

Node* deserializeTree(string &s){
    if(s.size() == 0){
        return NULL;
    }
    stringstream ss(s);
    string word;
    getline(ss, word, ',');
    Node* root = new Node(stoi(word));
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        getline(ss, word, ',');
        if(word == "#"){
            temp -> left = NULL;
        }else{
            Node* r = new Node(stoi(word));
            temp -> left = r;
            q.push(r);
        }
        getline(ss, word, ',');
        if(word == "#"){
            temp -> right = NULL;
        }else{
            Node* r = new Node(stoi(word));
            temp -> right = r;
            q.push(r);
        }
    }
    return root;
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
    Node* root = new Node(2);
    root -> left = new Node(1);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> right -> right = new Node(5);
    string ans = serializeTree(root);
    cout << "SerializeTree -> ";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
    Node* curr = deserializeTree(ans);
    cout << "deserializeTree -> ";
    print(curr);    
    cout << endl;
}
