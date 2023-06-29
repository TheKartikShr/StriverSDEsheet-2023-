#include<bits/stdc++.h>

using namespace std;
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	sort(arr.begin(), arr.end());
	return {arr[k - 1], arr[n - k]};
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
		vector<int> curr = kthSmallLarge(a, n, k);
		cout << curr[0] << " " << curr[1] << endl;
	}
}