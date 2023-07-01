#include<bits/stdc++.h>

using namespace std;

int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at + n);
    sort(dt, dt + n);
    int mx = 0, cnt = 0;
    int i = 0, j = 0;
    while(i < n){
        if(at[i] <= dt[j]){
            cnt++;
            mx = max(mx, cnt);
            i++;
        }else{
            cnt--;
            j++;
        }
    }
    return mx;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n], b[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}
		cout << calculateMinPatforms(a, b, n) << endl;
	}
}