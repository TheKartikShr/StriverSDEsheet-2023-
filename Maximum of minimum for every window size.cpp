#include <bits/stdc++.h>
using namespace std; 


vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> res(n,INT_MIN);
    
    stack<int> s;
    a.push_back(INT_MIN);
    
    for (int i = 0; i < a.size(); i++)
    {
        while(!s.empty() && a[s.top()]>=a[i]){
            int top = a[s.top()]; s.pop();
            int smal_left = s.empty()? -1 : s.top();
            int range = i - smal_left - 1;
            if(res[range-1]<top) res[range-1] = top;
        }
        s.push(i);
    }

    int max=INT_MIN;

    for(int i = res.size()-1;i>-1;i--){
        if(res[i]>max) max = res[i];
        res[i] = max;
    }
    
    return res;
}
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> curr = maxMinWindow(a, n);
	for(auto it : curr){
		cout << it << " ";
	}
	cout << endl;
}

