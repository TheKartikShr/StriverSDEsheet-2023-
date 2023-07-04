#include<bits/stdc++.h>

using namespace std;

class Node{
    Node* links[26];
    public:
        bool isPresent(char ch){
            return links[ch - 'a'];
        }
        void push(char ch, Node* node){
            links[ch - 'a'] = node;
        }
        Node* get(char ch){
            return links[ch - 'a'];
        }
};
int distinctSubstring(string &word) {
    Node* root = new Node();
    int cnt = 0, n = word.size();
    for(int i = 0; i < n; i++){
        Node* temp = root;
        for(int j = i; j < n; j++){
            if(!temp -> isPresent(word[j])){
                cnt++;
                temp -> push(word[j], new Node());
            }
            temp = temp -> get(word[j]);
        }
    }
    return cnt;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		string word;
		cin >> word;
		cout << distinctSubstring(word) << endl;
	}
}