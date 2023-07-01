#include<bits/stdc++.h>

using namespace std;

int jobScheduling(vector<vector<int>> &jobs){
    priority_queue<int> pq;
    int mx = 0;
    map<int, vector<int>> mp1;
    for(int i = 0; i < jobs.size(); i++){
        mx = max(mx, jobs[i][0]);
        mp1[jobs[i][0]].push_back(jobs[i][1]);
    }
    int sum = 0;
    while(mx > 0){
        for(auto it : mp1[mx]){
            pq.push(it);
        }
        if(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        mx--;
    }
    return sum;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n = 7;
		vector<vector<int>> a = {{1, 23},
								 {2, 90},
								 {3, 100},
								 {2, 500},
								 {1, 23},
								 {4, 233},
								 {4, 123}};
		cout << jobScheduling(a) << endl;
	}
}