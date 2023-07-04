#include<bits/stdc++.h>

using namespace std;

int romanToInt(string s) {
    int n = s.size();
    map<char, int> mp1;
    mp1.insert({'I', 1});
    mp1.insert({'V', 5});
    mp1.insert({'X', 10});
    mp1.insert({'L', 50});
    mp1.insert({'C', 100});
    mp1.insert({'D', 500});
    mp1.insert({'M', 1000});
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(mp1[s[i]] < mp1[s[i + 1]]){
            ans += mp1[s[i + 1]] - mp1[s[i]];
            i++;
        }else{
            ans += mp1[s[i]];
        }
    }
    return ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		cout << romanToInt(s) << endl;
	}
}