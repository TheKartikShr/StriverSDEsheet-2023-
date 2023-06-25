#include<bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int> &arr, int n) {
	int cnt = 0, curr = 0;
	for(int i = 0; i < n; i++){
		auto it = upper_bound(arr.begin(), arr.end(), curr);
		if(it != arr.end()){
			cnt++;
			curr = *it;
		}else{
			break;
		}
	}
	return cnt;
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << removeDuplicates(a, n) << endl;
}