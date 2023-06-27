#include<bits/stdc++.h>

using namespace std;

int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    vector<pair<int, int>> vp;
    for(int i = 0; i < n; i++){
        vp.push_back({start[i], finish[i]});
    }
    sort(vp.begin(), vp.end(), [&](const pair<int, int>& a, const pair<int, int>& b){
        return (a.second <= b.second);
    });
    int cnt = 0;
    int curr = -1;
    for(int i = 0; i < n; i++){
        if(vp[i].first > curr - 1){
            cnt++;
            curr = vp[i].second;
        }
    }
    return cnt;
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
		cout << maximumActivities(a, b) << endl;
	}
}