#include <bits/stdc++.h>
using namespace std; 

string fourSum(vector<int> a, int target, int n) {
    sort(a.begin(), a.end());
     for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int rem = target - (a[i] + a[j]);
            int l = j + 1, r = n - 1;
            while(l < r){
                int curr = a[l] + a[r];
                if(curr < rem){
                    l++;
                }else if(curr > rem){
                    r--;
                }else{
                    return "Yes";
                }
            }
        }
    }
    return "No";
}
int main(){
	int t;
	cin >> t;
	while(t--){	
		int n, target;
		cin >> n >> target;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		cout << fourSum(a, target, n) << endl;
	}
}

   