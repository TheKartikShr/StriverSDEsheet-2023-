#include <bits/stdc++.h>
using namespace std; 

struct Node{
    Node* links[26];
    int flag;

    bool isContains(char ch){
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


class Trie {

private: Node* root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node -> isContains(word[i])){
                node -> put(word[i], new Node());
            }
            node = node -> get(word[i]);
        }
        node -> setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node -> isContains(word[i])){
                return false;
            }
            node = node -> get(word[i]);
        }
        return node -> isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.size(); i++){
            if(!node -> isContains(prefix[i])){
                return false;
            }
            node = node -> get(prefix[i]);
        }
        return true;
    }
};
int main(){
	Trie* obj = new Trie();
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x == 1){
			string s;
			cout << "Insert a word: ";
			cin >> s;
			obj -> insert(s);
		}else if(x == 2){
			string s;
			cin >> s;
			cout << "Is the string " << s << "present in Trie -> " << (obj -> search(s) == 1 ? "YES" : "NO") << endl;
		}else{
			string s;
			cin >> s;
			cout << "Is there any string in the Trie that starts wit the given prefix string " << s << " -> " << (obj -> startsWith(s) == 1 ? "YES" : "NO") << endl;
		}
	}
}
