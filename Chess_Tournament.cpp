#include <bits/stdc++.h>
using namespace std; 


bool help(int mid, vector<int>& positions, int c){
	int partition = 1, curr = positions[0];
	for(int i = 0; i < positions.size(); i++){
		if(positions[i] - curr >= mid){
			partition++;
			if(partition == c){
				return true;
			}
			curr = positions[i];
		}
	}
	return false;
}
int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(), positions.end());
	int mx = *max_element(positions.begin(), positions.end());
	int mn = *min_element(positions.begin(), positions.end());
	int low = 1, high = mx - mn;
	while(low <= high){
		int mid = (low + high) / 2;
		if(help(mid, positions, c)){
			low = mid + 1;
		}else{
			high = mid - 1;
		}
	}
	return high;
}
int main(){
	int t;
	cin >> t;
	while(t--){	
		int n, c;
		cin >> n >> c;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		cout << chessTournament(a, n, c) << endl;
	} 
}

   