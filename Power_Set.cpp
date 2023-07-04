#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> pwset(vector<int>v){
    int n = v.size();
    vector<vector<int>> ansvec;
    for(int i = 0; i < (1 << n); i++){
        vector<int> ans;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                ans.push_back(v[j]);
            }
        }
        ansvec.push_back(ans);
    }
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
		vector<vector<int>> curr = pwset(a);
		for(auto i : curr){
			for(auto j : i){
				cout << j << " ";
			}
			cout << endl;
		}
	}
}