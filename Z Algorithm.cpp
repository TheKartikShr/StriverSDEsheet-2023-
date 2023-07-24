#include <bits/stdc++.h>
using namespace std; 


vector<int> prefix_fun(string s){
    int n = s.size();
    vector<int> curr(n, 0);
    for(int i = 1; i < n; i++){
        int curr_index = curr[i - 1];
        while(curr_index > 0 && s[i] != s[curr_index]){
            curr_index = curr[curr_index - 1];
        } 
        if(s[i] == s[curr_index]){
            curr_index++;
        }
        curr[i] = curr_index;
    }
    return curr;
}
int coutOccur(string parent, string sub){
    int answer;
    vector<int> prefix_arr = prefix_fun(sub);
    int pos = -1;
    int cnt = 0;
    int j = 0, i = 0;
    while(i < parent.size()){
        if(parent[i] == sub[j]){
            j++,i++;
        }else{
            if(j != 0){
                j = prefix_arr[j - 1];
            }else{
                i++;
            }
        }
        if(j == sub.size()){
            cnt++;
        }
    }
    return cnt;
}
int main(){
	int n, m;
    cin >> n >> m;
    string parent, sub;
    cin >> parent >> sub;
    cout << coutOccur(parent, sub) << endl;
}

