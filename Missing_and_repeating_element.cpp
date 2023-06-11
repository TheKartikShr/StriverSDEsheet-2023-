#include <bits/stdc++.h>
using namespace std; 
pair<int,int> missingAndRepeating(vector<int> &a, int n)
{
	sort(a.begin(), a.end());
	int f1 = 0, f2 = 0;
	int x, y;
	if (a[0] > 1){
		x = 1;
		f1 = 1;
	}
	map<int, int> mp1;
	mp1[a[0]]++;
	for (int i = 1; i < n; i++) {
		if(f1 == 1 && f2 == 1){
			break;
		}
		mp1[a[i]]++;
		if(mp1[a[i]] == 2){
			f2 = 1;
			y = a[i];
		} 
		if (a[i] > a[i - 1] + 1 && f1 == 0){
			x = a[i - 1] + 1;
			f1 = 1;
		}
	}
	if(f1 == 0){
		return {a.back() + 1, y};
	}	
	return {x, y};
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
		pair<int, int> vp = missingAndRepeating(a, n);
		cout << vp.first << " " << vp.second << endl;
	}
}