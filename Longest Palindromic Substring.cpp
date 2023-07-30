#include <bits/stdc++.h>
using namespace std; 

string longestPalinSubstring(string str){
    string ans = "";
    int n = str.size(), mx = 0;
    for(int i = 0; i < n; i++){
        int l = i, r = i;
        while(l >= 0 && r < n && str[l] == str[r]){
            if(r - l + 1 > mx){
                mx = r - l + 1;
                string temp = "";
                for(int k = l; k <= r; k++){
                    temp.push_back(str[k]);
                }
                ans = temp;
            }
            l--, r++;
        }
        l = i, r = i + 1;
        while(l >= 0 && r < n && str[l] == str[r]){
            if(r - l + 1 > mx){
                mx = r - l + 1;
                string temp = "";
                for(int k = l; k <= r; k++){
                    temp.push_back(str[k]);
                }
                ans = temp;
            }
            l--, r++;
        }
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << longestPalinSubstring(s) << endl;
}
