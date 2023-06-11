#include <bits/stdc++.h>
using namespace std; 

void swapp(vector<int>& arr1, vector<int>& arr2, int i, int j){
	if(arr1[i] > arr2[j]){
		swap(arr1[i], arr2[j]);
	}
}
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int len = n + m;
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len) {
            // case 1: left in arr1[]
            //and right in arr2[]:
            if (left < m && right >= m) {
                swapp(arr1, arr2, left, right - m);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= m) {
                swapp(arr2, arr2, left - m, right - m);
            }
            // case 3: both pointers in arr1[]:
            else {
              swapp(arr1, arr1, left, right);
            }
            left++, right++;
        }
        if (gap == 1) break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
	vector<int> vp;
	for(int i = 0; i < m; i++){
		vp.push_back(arr1[i]);
	}
	for(int i = 0; i < n; i++){
		vp.push_back(arr2[i]);
	}
	return vp;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < m; i++){
			cin >> b[i];
		}
		vector<int> ansvec = ninjaAndSortedArrays(a, b, n, m);
		for(auto it : ansvec){
			cout << it << " ";
		}
		cout << endl;
	}
}