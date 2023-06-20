#include <bits/stdc++.h>
using namespace std; 


int LongestSubsetWithZeroSum(vector < int > arr) {

  int n = arr.size();
  vector<int> pref(n, 0);
  pref[0] = arr[0];
  for(int i = 1; i < n; i++){
    pref[i] = pref[i - 1] + arr[i];
  }
  if(pref[n - 1] == 0){
    return n;
  }          
  map<int, vector<int>> mp1;
  for(int i = 0; i < n; i++){
    mp1[pref[i]].push_back(i);
  }
  int mx = 0;
  for(auto it : mp1){
    vector<int> ansvec = it.second;
      int n1 = ansvec.size();
      if(it.first == 0){
        mx = max(mx, ansvec[n1 - 1] + 1);
        continue;
      }
    if(it.second.size() > 1){
      mx = max(mx, ansvec[n1 - 1] - ansvec[0]);
    }
  }
  return mx;
}int main(){
	int t;
	cin >> t;
	while(t--){	
		int n;
		cin >> n; 
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		cout << LongestSubsetWithZeroSum(a) << endl;
	}
}

   