#include<bits/stdc++.h>

using namespace std;
int singleNonDuplicate(vector<int>& arr)
{
	int n = arr.size();
	if(n == 1){
		return arr[0];
	}
	int l = 0, h = n - 1;
	while(l <= h){
		int mid = (l + h) / 2;
		if(mid == 0 && arr[mid] != arr[mid + 1]){
			return arr[mid];
		}else if(mid == n - 1 && arr[mid] != arr[mid - 2]){
			return arr[mid];
		}else if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]){
			return arr[mid];
		}else if(mid % 2 == 0){
			if(arr[mid] == arr[mid + 1]){
				l = mid + 1;
			}else{
				h = mid - 1;
			}
		}else{
			if(arr[mid] == arr[mid + 1]){
				h = mid - 1;
			}else{
				l = mid + 1;
			}
		}
	}
	return arr[l];
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
		cout << singleNonDuplicate(a) << endl;
	}
}