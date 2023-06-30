#include<bits/stdc++.h>

using namespace std;
int longestSubSeg(vector<int> &arr , int n, int k){
    int mx = 0, cnt = 0, j = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            cnt++;
        }
        while(cnt > k){
            if(arr[j++] == 0){
                cnt--;
            }
        }
        mx = max(mx, i - j + 1);
    }
    return mx;
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
		cout << longestSubSeg(a, n, k) << endl;
	}
}