#include<bits/stdc++.h>

using namespace std;

string kthPermutation(int n, int k) {
    int fact = 1;
    vector<int> ansvec;
    for(int i = 1; i < n; i++){
        fact *= i;
        ansvec.push_back(i);
    }
    ansvec.push_back(n);
    k = k - 1;
    string ans = "";
    while(true){
        ans = ans + to_string(ansvec[k / fact]);
        ansvec.erase(ansvec.begin() + (k / fact));
        if(ansvec.size() == 0){
            break;
        }
        k = k % fact;
        fact = fact / ansvec.size();
    }
    return ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		cout << kthPermutation(n, k) << endl;
	}
}