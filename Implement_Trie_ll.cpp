#include<bits/stdc++.h>

using namespace std;

struct Node{
    Node* links[26];
    bool flag = false;
    int cntEndsWith = 0, cnt_Prefix = 0;
    bool isPresent(char ch){
        return links[ch - 'a'];
    }
    bool push(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    void increaseEnd(){
        cntEndsWith++;
    }
    void increase_Prefx(){
        cnt_Prefix++;
    }
    void decreaseEnd(){
        cntEndsWith--;
    }
    void decrease_Prefix(){
        cnt_Prefix--;
    }
    int getEnd(){
        return cntEndsWith;
    }
    int getPrefix(){
        return cnt_Prefix;
    }
    bool setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
    Node* root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node -> isPresent(word[i])){
                node -> push(word[i], new Node());
            }
            node = node -> get(word[i]);
            node -> increase_Prefx();
        }
        node -> setEnd();
        node -> increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node -> isPresent(word[i])){
                return 0;
            }else{
                node = node -> get(word[i]);
            }
        }
        return node -> getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node -> isPresent(word[i])){
                return 0;
            }else{
                node = node -> get(word[i]);
            }
        }
        return node -> getPrefix();
    }

    void erase(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node -> isPresent(word[i])){
                return;
            }
            node = node -> get(word[i]);
            node -> decrease_Prefix();
        }
        node -> decreaseEnd();
    }
};

int main(){
	int t;
	cin >> t;
	while(t--){
		Trie t;
		vector<string> vs = {"coding", "ninja", "coding", "nin", "coding"};
		for(int i = 0; i < 5; i++){
			string x;
			cin >> x;
			cout << endl;
			if(x == "insert"){
				t.insert(vs[i]);
			}else{
				t.erase(vs[i]);
			}
			int cnt_word_equal = t.countWordsEqualTo(vs[i]);
			int Prefix_cnt = t.countWordsStartingWith(vs[i]);
			cout << "Number of Equal String: " << cnt_word_equal << endl;
			cout << "Number of Strings start With the given Prefix: " << Prefix_cnt << endl;
			cout << endl;
		}

	}
}