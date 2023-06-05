#include <bits/stdc++.h> 
using namespace std;
long long maxSubarraySum(int a[], int n)
{
    long long sum = 0, mx = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        if(sum < 0){
            mx = max(mx, sum);
            sum = 0;
        }
        mx = max(mx, sum);
    }
    return mx;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		cout << maxSubarraySum(a, n) << endl;
	}
}