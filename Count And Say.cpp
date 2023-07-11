#include <bits/stdc++.h>
using namespace std; 

string writeAsYouSpeak(int n){
	string s = "1";
	if(n == 1){
		return s;
	}
	for(int i = 2; i <= n; i++){
		string curr = "";
		for(int j = 0; j < s.size();){
			int cnt = 0, c = j;
			while(j < s.size() && s[j] == s[c]){
				cnt++;
				c++;
			}
			curr += to_string(cnt) + s[j];
			j = c;
		}
		s = curr;
	}
	return s;
} 
int main(){
	int t;
	cin >> t;
	while(t--){	
		int n;
		cin >> n;
		cout << writeAsYouSpeak(n) << endl;
	} 
}
