#include<bits/stdc++.h>

using namespace std;

int maximumXor(vector<int>& a){
    int n = a.size();
    int mx = 0, mask = 0;
    set<int> s;
    for(int i = 30; i >= 0; i--){
        mask |= (1 << i);
        for(int j = 0; j < n; j++){
            s.insert(a[j] & mask);
        }
        int newmx = mx | (1 << i);
        for(auto it : s){
            if(s.count(newmx ^ it)){
                mx = newmx;
                break;
            }
        }
        s.clear();
    }
    return mx;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		cout << maximumXor(a) << endl;
	}
}