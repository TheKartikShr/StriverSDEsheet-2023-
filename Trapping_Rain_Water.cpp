#include<bits/stdc++.h>

using namespace std;


long getTrappedWater(long *arr, int n){
    long ans = 0;
    vector<long> pref(n), suff(n);
    pref[0] = arr[0];
    for(int i = 1; i < n; i++){
        pref[i] = max(pref[i - 1], arr[i]);
    }
    suff[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--){
        suff[i] = max(suff[i + 1], arr[i]);
    }
    for(int i = 1; i < n - 1; i++){
        ans += min(pref[i], suff[i]) - arr[i];
    }
    return ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		long n ;
		cin >> n;
		long arr[n];
		for(long i = 0; i < n; i++){
			cin >> arr[i];
		}
		cout << getTrappedWater(arr, n) << endl;
	}
}