#include <bits/stdc++.h>
using namespace std; 


int findMajorityElement(int arr[], int n) {
	map<int, int> mp1;
	for(int i = 0; i < n; i++){
		mp1[arr[i]]++;
		if(mp1[arr[i]] > n / 2){
			return arr[i];
		}
	}
	return -1;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		cout << findMajorityElement(a, n) << endl;
	}
}

   