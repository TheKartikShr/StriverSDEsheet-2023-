#include <bits/stdc++.h> 
using namespace std;
void sort012(int *a, int n)
{
   int cnt_0 = 0, cnt_1 = 0, cnt_2 = 0;
   for(int i = 0; i < n; i++){
      if(a[i] == 0){
         cnt_0++;
      }else if(a[i] == 1){
         cnt_1++;
      }else{
         cnt_2++;
      }
   }
   int i = 0;
   while(cnt_0 > 0){
      a[i++] = 0;
      cnt_0--;
   }
   while(cnt_1 > 0){
      a[i++] = 1;
      cnt_1--;
   }
   while(cnt_2 > 0){
      a[i++] = 2;
      cnt_2--;
   }
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort012(a, n);
		for(int i = 0; i < n; i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}
}