#include <bits/stdc++.h>
using namespace std; 

int findDuplicate(vector<int> &arr, int n){
	map<int, int> mp1;
	int curr = 0;
	for(int i = 0; i < n; i++){
		mp1[arr[i]]++;
		if(mp1[arr[i]] == 2){
			curr = arr[i];
			break;
		}
	}
	return curr;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		cout << findDuplicate(a, n) << endl;
	}
}