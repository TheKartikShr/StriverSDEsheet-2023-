#include<bits/stdc++.h>

using namespace std;
int NthRoot(int n, int m) {
  int l = 1, h = m;
  while(l <= h){
    int mid = (l + h) / 2;
    if(pow(mid, n) == m){
      return mid;
    }
    if(pow(mid, n) > m){
      h = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return -1;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		cout << NthRoot(n, m) << endl;
	}
}