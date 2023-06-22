#include <bits/stdc++.h>
using namespace std; 

void help(int index, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ansvec){
    ansvec.push_back(ds);
    for(int i = index; i < arr.size(); i++){
        if(i != index && arr[i] == arr[i - 1]){
            continue;
        }
        ds.push_back(arr[i]);
        help(i + 1, arr, ds, ansvec);
        ds.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr){
    vector<vector<int>> ansvec;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    help(0, arr, ds, ansvec);
    return ansvec;
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
		vector<vector<int>> curr = uniqueSubsets(n, a);
		for(auto it : curr){
			for(auto i : it){
				cout << i << " ";
			}
			cout << endl;
		}
		cout << endl;
	} 
}

   