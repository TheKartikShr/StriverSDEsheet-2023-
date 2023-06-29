#include<bits/stdc++.h>

using namespace std;
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	priority_queue<pair<int, int>> pq;
	for(int i = 0; i < n; i++){
		pq.push({a[i] + b[n - 1], n - 1});
	}
	vector<int> ansvec;
	while(k--){
		int index = pq.top().second;
		ansvec.push_back(pq.top().first);
		if(index - 1 >= 0){
			pq.push({pq.top().first - b[index] + b[index - 1], index - 1});
		}
		pq.pop();
	}
	return ansvec;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> a(n), b(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}
		vector<int> ansvec = kMaxSumCombination(a, b, n, k);
		for(auto it : ansvec){
			cout << it << " ";
		}
		cout << endl;
	}
}