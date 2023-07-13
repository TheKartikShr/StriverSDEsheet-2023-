#include <bits/stdc++.h>
using namespace std; 

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
       if(m<n) return ninjaAndLadoos(row2, row1, n, m, k);

    int left = max(0, k-n), right = min(k, m), mid;
    while(left<=right){
        mid = (left+right)>>1;
        int mid2 = k-mid;
        int l1 = mid?    row1[mid-1]:INT_MIN;
        int l2 = mid2?   row2[mid2-1]: INT_MIN;
        int r1 = mid<m?  row1[mid]: INT_MAX;
        int r2 = mid2<n? row2[mid2]: INT_MAX;
        if(l1<=r2 and l2<=r1) return max(l1, l2);
        else if(l1>r2) right = mid-1;
        else left = mid+1;
    }
    return 0;
}


int main(){
	int n, m, k;
    cin >> n >> m >> k;
    vector<int> row1(n), row2(m);
    for(int i = 0; i < n; i++){
        cin >> row1[i];
    }
    for(int i = 0; i < m; i++){
        cin >> row2[i];
    }
    cout << ninjaAndLadoos(row1, row2, n, m, k) << endl;
}
