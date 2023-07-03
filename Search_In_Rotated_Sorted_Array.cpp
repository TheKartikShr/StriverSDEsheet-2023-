#include<bits/stdc++.h>

using namespace std;

int search(int* a, int n, int k) {
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(a[mid] == k){
            return mid;
        }
        if(a[low] <= a[mid]){
            if(k >= a[low] && k <= a[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else{
            if(k >= a[mid] && k <= a[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		cout << search(a, n, m) << endl;
	}
}