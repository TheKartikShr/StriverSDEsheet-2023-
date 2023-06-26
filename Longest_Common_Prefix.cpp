#include<bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    string curr = arr[0];
    for(int i = 0; i < curr.size(); i++){
        int cnt = 1, f = 0;
        for(int j = 1; j < n; j++){
            if(curr[i] == arr[j][i]){
                cnt++;
            }else{
                f = 1;
                break;
            }
        }
        if(f == 1){
            break;
        }
        if(cnt == n){
            ans.push_back(curr[i]);
        }
    }
    return ans;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<string> vs(n);
		for(int i = 0; i < n; i++){
			cin >> vs[i];
		}
		cout << longestCommonPrefix(vs, n) << endl;
	}
}