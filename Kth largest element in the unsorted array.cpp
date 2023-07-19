#include <bits/stdc++.h>
using namespace std; 

int kthLargest(vector<int>& arr, int size, int K)
{
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < size; i++){
		pq.push(arr[i]);
		if(pq.size() > K){
			pq.pop();
		}
	}
	return pq.top();
}
int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << kthLargest(a, n, k) << endl;
}
