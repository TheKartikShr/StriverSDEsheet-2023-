#include<bits/stdc++.h>

using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < kArrays[i].size(); j++){
            pq.push(kArrays[i][j]);
        }
    }
    vector<int> ansvec;
    while(!pq.empty()){
        ansvec.push_back(pq.top());
        pq.pop();
    }
    return ansvec;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<vector<int>> a = {{3, 5, 9}, {1, 2, 3, 8}};
		vector<int> ansvec = mergeKSortedArrays(a, n);
		for(auto it : ansvec){
			cout << it << " ";
		}
		cout << endl;
	}
}