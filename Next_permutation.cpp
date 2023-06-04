#include <bits/stdc++.h>

using namespace std;

vector<int> nextPermutation(vector<int> &permutation, int n)
{
	int i, j;
    for(i = n - 2; i >= 0; i--){
        if(permutation[i] < permutation[i + 1]){
            break;
        }
    }
    if (i < 0) {
      reverse(permutation.begin(), permutation.end());
    }else{
        for(j = n - 1; j > i; j--){
            if(permutation[j] > permutation[i]){
                break;
            }
        }
        swap(permutation[j], permutation[i]);
        reverse(permutation.begin() + i + 1, permutation.end());
    }
    return permutation;
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
		vector<int> curr = nextPermutation(a, n);
		for(int i = 0; i < n; i++){
			cout << curr[i] << " ";
		}
		cout << endl;
	}
}