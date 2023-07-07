#include<bits/stdc++.h>

using namespace std;

vector<int> slidingWindowMaximum(vector<int> &arr, int &k){
    int n = arr.size();
    vector<int> ans;
    priority_queue<pair<int, int>> pq;

    for(int i = 0; i < k; i++){
        pq.push({arr[i], i});
    }

    ans.push_back(pq.top().first);

    for(int i = k; i < n; i++){
        pq.push({arr[i], i});
        if(pq.top().second <= i-k){
            while(pq.top().second <= i-k){
                pq.pop();
            }
        }
        ans.push_back(pq.top().first);
    }
   return ans;
}
int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> nse = slidingWindowMaximum(a, k);
	for(auto it : nse){
		cout << it << " ";
	}
	cout << endl;
}