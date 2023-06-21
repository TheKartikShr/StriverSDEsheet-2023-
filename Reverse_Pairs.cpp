#include <bits/stdc++.h>
using namespace std; 

void merge(vector<int> &arr, int low, int mid, int high){
	vector<int> ansvec;
	int left = low;
	int right = mid + 1;
	while(left <= mid && right <= high){
		if(arr[left] <= arr[right]){
			ansvec.push_back(arr[left]);
			left++;
		}else{
			ansvec.push_back(arr[right]);
			right++;
		}
	}
	while(left <= mid){
		ansvec.push_back(arr[left]);
		left++;
	}
	while(right <= high){
		ansvec.push_back(arr[right]);
		right++;
	}
	for(int i = low; i <= high; i++){
		arr[i] = ansvec[i - low];
	}
}

int count(vector<int> &arr, int low, int mid, int high){
	int right = mid + 1, cnt  = 0;
	for(int i = low; i <= mid; i++){
		while(right <= high && arr[i] > 2 * arr[right]){
			right++;
		}
		cnt += (right - (mid + 1));
	}
	return cnt;
}
int mergeSort(vector<int> &arr, int low, int high){
	if(low >= high){
		return 0;	
	}
	int cnt = 0;
	int mid = (low + high) / 2;
	cnt += mergeSort(arr, low, mid);
	cnt += mergeSort(arr, mid + 1, high);
	cnt += count(arr, low, mid, high);
	merge(arr, low, mid, high);
	return cnt;
	
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
		cout << mergeSort(a, 0, n - 1) << endl;
	} 
}

   