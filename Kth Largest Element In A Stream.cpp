#include <bits/stdc++.h>
using namespace std; 

class Kthlargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int kk;
public:
    Kthlargest(int k, vector<int> &arr) {
        kk = k;
        for(auto it: arr){
            pq.push(it);
            if(pq.size() > kk){
                pq.pop();
            }
        }
    }

    void add(int num) {
        pq.push(num);
        if(pq.size() > kk){
            pq.pop();
        }
    }

    int getKthLargest() {
        return pq.top();
    }

};

int main(){
	int q, n;
	cin >> q >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	Kthlargest* temp = new Kthlargest(n, a);
	while(q--){
		int x;
		cin >> x;
		if(x == 1){
			int y;
			cout << "Store it in the Pool: ";
			cin >> y;
			temp -> add(y);
		}else{
			cout << "kth largest number from the current pool of integers -> " << temp -> getKthLargest() << endl;
		}
	}
}
