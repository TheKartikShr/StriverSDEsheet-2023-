#include <bits/stdc++.h>
using namespace std; 


vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<vector<int>> ansvec;
   sort(arr.begin(), arr.end());
   unordered_map<int, int> mp1;
   int n = arr.size();
   for(int i = 0; i < n; i++){
      int cnt = mp1[s - arr[i]];
      int x = arr[i], y = s - arr[i];
      while(cnt--){
         ansvec.push_back({min(x, y), max(x, y)});
      }
      mp1[arr[i]]++;
   }
   sort(ansvec.begin(), ansvec.end());
   return ansvec;
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
		vector<vector<int>> curr = pairSum(a, target);
		for(auto it : curr){
			for(auto i : it){
				cout << i << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}

   