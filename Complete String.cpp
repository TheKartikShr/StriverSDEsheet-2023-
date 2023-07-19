#include <bits/stdc++.h>
using namespace std; 

struct Node{
    Node* links[26];
    bool flag;

    bool containKey(char ch){
        return links[ch - 'a'];
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
}; 

class Trie{
    private: Node* root;
    public: 
        Trie(){
            root = new Node();
        }
        void insert(string word){
            Node* node = root;
            for(int i = 0; i < word.size(); i++){
                if(!node->containKey(word[i])){
                    node -> put(word[i], new Node());
                }
                node = node -> get(word[i]);
            }
            node -> setEnd();
        }
        bool help(string word){
            int flag = true;
            Node* node = root;
            for(int i = 0; i < word.size(); i++){
                if(node -> containKey(word[i])){
                    node = node -> get(word[i]);
                    flag = flag & node -> isEnd();
                }else{
                    return false;
                }
            }
            return flag;
        }

};

string completeString(int n, vector<string> &a){
    Trie* temp = new Trie();
    for(auto& it : a){
        temp -> insert(it);
    }
    string longest = "";
    for(auto& it : a){
        if(temp -> help(it)){
            if(it.size() > longest.size()){
                longest = it;
            }else if(it.size() == longest.size() && it < longest){
                longest = it;
            }
        }
    }
    if(longest == ""){
        return "None";
    }
    return longest;
}
int main(){
	int n;
	cin >> n;
	vector<string> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << completeString(n, a) << endl;
}
