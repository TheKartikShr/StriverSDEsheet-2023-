#include <bits/stdc++.h>
using namespace std; 


void help(int index, string&s, vector<string> &vs){
    if(index == s.size()){
        vs.push_back(s);
        return;
    }
    for(int i = index; i < s.size(); i++){
        swap(s[i], s[index]);
        help(index + 1, s, vs);
        swap(s[i], s[index]);
    }
}
int main(){
	int t;
	cin >> t;
	while(t--){	
		string s;
	    cin >> s;
	    vector<string> vs;
	    help(0, s, vs);
	    for(auto & it : vs){
	        cout << it << endl;
	    }
	} 
}

   