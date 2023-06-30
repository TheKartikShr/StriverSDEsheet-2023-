#include<bits/stdc++.h>

using namespace std;
vector<int> subsetSum(vector<int> &nums){
	int n = nums.size();
	vector<int> ansvec;
	for(int i = 0; i < (1 << n); i++){
		int sum = 0;
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				sum += nums[j];
			}
		}
		ansvec.push_back(sum);
	}
	sort(ansvec.begin(), ansvec.end());
	return ansvec;
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
		vector<int> ansvec = subsetSum(a);
		for(auto it : ansvec){
			cout << it << ' ';
		}
		cout << endl;
	}
}