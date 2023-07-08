#include<bits/stdc++.h>

using namespace std;
int atoi(string str) {
    stack<char> q;
    int n = str.size();
    int ans = 0, f = 0;
    for(int i = 0; i < n; i++){
        q.push(str[i]);
        while(!q.empty() && (q.top() >= 48 && q.top() <= 57)){
            int x = q.top() - '0';
            ans = ans * 10 + x;
            q.pop();
        }
        if(str[i] == '-'){
            f = 1;
        }
    }
    if(f){
        return -ans;
    }
    return ans;
}
int main(){	
	string str;
	cin >> str;
	cout << atoi(str) << endl;
}