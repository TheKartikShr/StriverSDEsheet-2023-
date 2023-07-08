#include<bits/stdc++.h>

using namespace std;

bool areAnagram(string &str1, string &str2){
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}
int main(){
	string s1, s2;
	cin >> s1 >> s2;
	cout << areAnagram(s1, s2) << endl;
}