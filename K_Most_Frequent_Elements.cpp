#include<bits/stdc++.h>

using namespace std;

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    map<int, int> mp1;
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < n; i++){
        mp1[arr[i]]++;
    }
    for(auto it : mp1){
        pq.push({it.second, it.first});
    }
    vector<int> ansvec;
    while(k--){
        ansvec.push_back(pq.top().second);
        pq.pop();
    }
    sort(ansvec.begin(), ansvec.end());
    return ansvec;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		vector<int> curr = KMostFrequent(n, k, a);
		for(auto i : curr){
			cout << i << " ";
		}
		cout << endl;
	}
}