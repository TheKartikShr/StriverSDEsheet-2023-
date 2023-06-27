#include<bits/stdc++.h>

using namespace std;

int findMinimumCoins(int amount) {
    int a[9] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int cnt = 0;
    for(int i = 8; i >= 0;){
        if(a[i] <= amount){
            amount -= a[i];
            cnt++;
        }else{
            i--;
        }
    }
    return cnt;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int amount;
		cin >> amount;
		cout << findMinimumCoins(amount) << endl;
	}
}