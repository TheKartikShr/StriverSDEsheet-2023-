#include <bits/stdc++.h>
using namespace std; 


vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
    set<int> prev;
    map<int, int> mp1;
    vector<int> ansvec;
    for(int i = 0; i < n; i++){
        mp1[arr[i]]++;
        if(mp1[arr[i]] > n / 3 && !prev.count(arr[i])){
            ansvec.push_back(arr[i]);
            prev.insert(arr[i]);
        }
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
		vector<int> curr = majorityElementII(a);
		for(auto it : curr){
			cout << it << " ";
		}
		cout << endl;
	}
}

   