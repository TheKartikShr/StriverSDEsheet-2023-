#include<bits/stdc++.h>

using namespace std;

vector<int> help(vector<int>& arr, int n){
    vector<int> ans(n);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[i] > arr[st.top()]){
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        ans[st.top()] = -1;
        st.pop();
    }
    return ans;
}
vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int> nge = help(arr, n);
    vector<int> ansvec;
    for(int i = 0; i < n; i++){
        if(nge[i] == -1){
            ansvec.push_back(-1);
        }else{
            ansvec.push_back(arr[nge[i]]);
        }
    }
    return ansvec;
}
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> nge = nextGreater(a, n);
	for(int i = 0; i < n; i++){
		cout << nge[i] << ' ';
	}
	cout << endl;
}