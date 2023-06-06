#include <bits/stdc++.h>
using namespace std; 
int maximumProfit(vector<int> &prices){
    int mn = INT_MAX, mx = INT_MIN;
    for(int i = 0; i < prices.size(); i++){
        mn = min(mn, prices[i]);
        mx = max(mx, prices[i] - mn);
    }
    return mx;
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
		cout << maximumProfit(a) << endl;
	}
}