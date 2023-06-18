#include <bits/stdc++.h>
using namespace std; 

int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    unordered_map<int, int> mp1;
    int ans = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        ans ^= arr[i];
        if(ans == x){
            cnt++;
        }
        if(mp1.count(ans ^ x)){
            cnt += mp1[ans ^ x];
        }
        mp1[ans]++;
    }
    return cnt;
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
		cout << subarraysXor(a, k) << endl;
	}
}

   