#include<bits/stdc++.h>

using namespace std;

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    vector<pair<int, pair<int, int>>> vp;
    for(int i = 0; i < n; i++){
        vp.push_back({end[i], {i + 1, start[i]}});
    }
    sort(vp.begin(), vp.end());
    vector<int> ansvec;
    int curr = -1;
    for(int i = 0; i < n; i++){
        if(vp[i].second.second > curr - 1){
            ansvec.push_back(vp[i].second.first);
            curr = vp[i].first + 1;
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
		vector<int> a(n), b(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}
		vector<int> ansvec = maximumMeetings(a, b);
		for(auto it : ansvec){
			cout << it << " ";
		}
		cout << endl;
	}
}