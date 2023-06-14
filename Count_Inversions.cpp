#include <bits/stdc++.h>
using namespace std; 


long long merge(long long *arr, long long low, long long mid, long long high){
    vector<long long> ansvec;
    long long left = low;
    long long right = mid + 1;
    long long cnt = 0;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            ansvec.push_back(arr[left]);
            left++;
        }else{
            ansvec.push_back(arr[right]);
            cnt += (mid - left + 1);
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
    for(long long i = low; i <= high; i++){
        arr[i] = ansvec[i - low];
    }
    return cnt;
}
long long merge_Sort(long long *arr, long long low, long long high){
    if(low >= high){
        return 0;
    }
    long long cnt = 0;
    long long mid = (low + high) / 2;
    cnt += merge_Sort(arr, low, mid);
    cnt += merge_Sort(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);
    return cnt;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		long long arr[n];
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		cout << merge_Sort(arr, 0, n - 1) << endl;
		for(int i = 0; i < n; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}

// Fenwick Tree -> To find the count of inversion in an array

// const long long N = 100005;
// long long Fen[N];
// void update(long long i, long long add){
//     while(i < N){
//         Fen[i] += add;
//         i += (i & (-i));
//     }
// }

// long long sum(long long i){
//     long long sum = 0;
//     while(i > 0){
//         sum += Fen[i];
//         i =  i - (i & (-i));
//     }
//     return sum;
// }

// long long getInversions(long long *arr, int n){
//     map<long long, int> mp1;
//     for(int i = 0; i < n; i++){
//         mp1[arr[i]];
//     }
//     int cnt = 1;
//     for(auto& it : mp1){
//         it.second = cnt++;
//     }
//     for(int i = 0; i < n; i++){
//         arr[i] = mp1[arr[i]];
//     }
//     long long ans = 0;
//     for(int i = 0; i < n; i++){
//         ans += (sum(N) - sum(arr[i]));
//         update(arr[i], 1);
//     }
//     return ans;
// }    

   