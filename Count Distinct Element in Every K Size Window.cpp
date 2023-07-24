#include <bits/stdc++.h>
using namespace std; 

vector<int> countDistinctElements(vector<int> &arr, int k) {
    vector<int> ans;

    unordered_map<int,int>mp;

    for(int i=0;i<arr.size();i++){

    mp[arr[i]]++;

    if(i>=k-1){

    ans.push_back(mp.size());

    if(--mp[arr[i-k+1]]==0)mp.erase(arr[i-k+1]);//if its freq is 0 remove it from map

    }

    }

    return ans;
}



int main(){
	int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> curr = countDistinctElements(arr, k);
    for(auto it : curr){
    	cout << it << " ";
    }
    cout << endl;
}

