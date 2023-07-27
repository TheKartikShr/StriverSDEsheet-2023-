#include <bits/stdc++.h>
using namespace std; 

struct Node {
  Node * links[2];
 
  bool containsKey(int ind) {
    return (links[ind] != NULL);
  }
  Node * get(int ind) {
    return links[ind];
  }
  void put(int ind, Node * node) {
    links[ind] = node;
  }
};
class Trie {
  private: Node * root;
  public:
    Trie() {
      root = new Node();
    }
 
  public:
    void insert(int num) {
      Node * node = root;
      // cout << num << endl; 
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!node -> containsKey(bit)) {
          node -> put(bit, new Node());
        }
        node = node -> get(bit);
      }
    }
  public:
    int findMax(int num) {
      Node * node = root;
      int maxNum = 0;
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (node -> containsKey(!bit)) {
          maxNum = maxNum | (1 << i);
          node = node -> get(!bit);
        } else {
          node = node -> get(bit);
        }
      }
      return maxNum;
    }
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &q){
	sort(arr.begin(), arr.end());
	vector<pair<int, pair<int, int>>> vp;
	int n = q.size(), j = 0;
	for(int i = 0; i < n; i++){
		vp.push_back({q[i][1], {q[i][0], i}});
	}
	sort(vp.begin(), vp.end());
	vector<int> ansvec(n, 0);
	Trie t;
	for(int i = 0; i < n; i++){
		int ai = vp[i].first;
		int xi = vp[i].second.first;
		int ind = vp[i].second.second;
		while(j < arr.size() && arr[j] <= ai){
			t.insert(arr[j]);
			j++;
		}
		if(j == 0){
			ansvec[ind] = -1;
		}else{
			ansvec[ind] = t.findMax(xi);
		}
	}
	return ansvec;
} 
int main(){
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<vector<int>> q1;
	while(q--){
		int x, y;
		cin >> x >> y;
		q1.push_back({x, y});
	}
	vector<int> curr = maxXorQueries(a, q1);
	for(auto it : curr){
		cout << it << ' ';
	}
	cout << endl;
}

