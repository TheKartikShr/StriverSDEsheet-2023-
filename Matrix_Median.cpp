#include<bits/stdc++.h>

using namespace std;

int help(vector<int>& ans, int mid){
    int low = 0, high = ans.size() - 1;
    while(low <= high){
        int curr_mid = (low + high) / 2;
        if(ans[curr_mid] <= mid){
            low = curr_mid + 1;
        }else{
            high = curr_mid - 1;
        }
    }
    return low;
}
int getMedian(vector<vector<int>> &matrix){
    int n = matrix.size(), m = matrix[0].size();
    int low = 1, high = 1e9;
    while(low <= high){
        int mid = (low + high) / 2;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += help(matrix[i], mid);
        }
        if(cnt <= (n * m) / 2){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return low;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(n));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
		cout << getMedian(a) << endl;
	}
}