#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>> ansvec;
	sort(arr.begin(), arr.end());
	for(int i = 0; i < n; i++){
		if(i > 0 && arr[i] == arr[i - 1]){
			continue;
		}
		int j = i + 1, k = n - 1;
		while(j < k){
			int sum = arr[i] + arr[j] + arr[k];
			if(sum < K){
				j++;
			}else if(sum > K){
				k--;
			}else{
				ansvec.push_back({arr[i], arr[j], arr[k]});
				j++, k--;
				while(j < k && arr[j] == arr[j - 1]){
					j++;
				}
				while(j < k && arr[k] == arr[k + 1]){
					k--;
				}
			}
		}
	}
	return ansvec;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(long i = 0; i < n; i++){
			cin >> a[i];
		}
		vector<vector<int>> curr = findTriplets(a, n, k);
		for(int i = 0; i < curr.size(); i++){
			cout << curr[i][0] << " " << curr[i][1] << " " << curr[i][2] << endl;
		}
	}
}