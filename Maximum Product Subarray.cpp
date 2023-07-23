#include <bits/stdc++.h>
using namespace std; 

int maximumProduct(vector<int> &arr, int n){
	int pre = 1, suff = 1, mx = INT_MIN;
	for(int i = 0; i < n; i++){
		if(pre == 0){
			pre = 1;
		}
		if(suff == 0){
			suff = 1;
		}
		pre *= arr[i];
		suff *= arr[n - i - 1];
		mx = max({mx, pre, suff});
	}
	return mx;
}


int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << maximumProduct(arr, n) << endl;
}

