#include <bits/stdc++.h>
using namespace std; 

int uniqueSubstrings(string s){
        int n = s.size();
        if(n == 0){
            return 0;
        }
        int i = 0, j = 0;
        vector<int> a(256, 0);
        a[s[0]]++;
        int ans = 1;
        while(true){
            if(j == n - 1){
                break;
            }
            if(a[s[j + 1]] == 0){
                j++;
                a[s[j]]++;
                ans = max(ans, j - i + 1);
            }else{
                a[s[i]]--;
                i++;
            }
        }
        return ans;
}
int main(){
	int t;
	cin >> t;
	while(t--){	
		string input;
		cin >> input;
		cout << uniqueSubstrings(input) << endl;
	}
}

   