#include <bits/stdc++.h>

using namespace std;

vector<vector<long long int>> printPascal(int n) {
  vector<vector<long long int>> ansvec;
  ansvec.push_back({1});
  for(int i = 1; i < n; i++){
    vector<long long int> ans = ansvec[i - 1];
    vector<long long int> curr;
    curr.push_back(1);
    for(int i = 1; i < ans.size(); i++){
      long long int x = ans[i] + ans[i - 1];
      curr.push_back(x);
    }
    curr.push_back(1);
    ansvec.push_back(curr);
  }
  return ansvec;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<vector<long long int>> matrix = printPascal(n);
		for(auto it : matrix){
			for(auto i : it){
				cout << i << " ";
			}
			cout << endl;
		}
	}
}