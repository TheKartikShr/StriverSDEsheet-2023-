#include<bits/stdc++.h>

using namespace std;

vector<int> help(vector<int>& arr){
    vector<int> curr(arr.size());
    stack<int> st;
    for(int i = 0; i < arr.size(); i++){
        while(!st.empty() && arr[i] < arr[st.top()]){
            curr[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        curr[st.top()] = -1;
        st.pop();
    }
    return curr;
}
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> nse = help(arr);
    vector<int> ansvec;
    for(int i = 0; i < n; i++){
        if(nse[i] == -1){
            ansvec.push_back(-1);
        }else{
            ansvec.push_back(arr[nse[i]]);
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
	vector<int> nse = nextSmallerElement(a, n);
	for(int i = 0; i < n; i++){
		cout << nse[i] << ' ';
	}
	cout << endl;
}