#include<bits/stdc++.h>

using namespace std;


void help(int index, int n, int k, vector<int>& arr, vector<int>& curr, vector<vector<int>>& ansvec){
    if(index == n){
        if(k == 0){
            ansvec.push_back(curr);
        }
        return;
    }
    curr.push_back(arr[index]);
    help(index + 1, n, k - arr[index], arr, curr, ansvec);
    curr.pop_back();
    help(index + 1, n, k, arr, curr, ansvec);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<int> curr;
    vector<vector<int>> ansvec;
    help(0, n, k, arr, curr, ansvec);
    return ansvec;
}

int main(){
	int n, target;
	cin >> n >> target;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<vector<int>> ansvec = findSubsetsThatSumToK(a, n, target);
	for(auto it : ansvec){
		for(auto i : it){
			cout << i << " ";
		}
		cout << endl;
	}
}