#include <bits/stdc++.h>
using namespace std; 

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    int cnt = 0, mx = 0;
    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
    n = arr.size();
    int f = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] - arr[i - 1] == 1){
            if(f == 1){
                cnt += 2;
                f = 0;
            }else{
                cnt++;
            }
        }else{
            mx = max(mx, cnt);
            cnt = 0;
            f = 1;
        }
    }   
    mx = max(mx, cnt);
    if(mx == 0){
        return 1;
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
		cout << lengthOfLongestConsecutiveSequence(a, n) << endl;
	}
}

   