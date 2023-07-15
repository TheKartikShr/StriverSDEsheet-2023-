#include <bits/stdc++.h>
using namespace std; 

void insert(int x, priority_queue<int, vector<int>, greater<int>>& pqmin, priority_queue<int>& pqmax){
    if(pqmax.size() == pqmin.size()){
        if(pqmax.size() == 0){
            pqmax.push(x);
            return;
        }
        if(x >= pqmax.top()){
            pqmin.push(x);
        }else{
            pqmax.push(x);
        }
    }else{
        // tow possible cases
        // Case 1: size of pqmax > size of pqmin
        // Case 2: size of pqmax < size of pqmin
        if(pqmax.size() > pqmin.size()){
            if(x >= pqmax.top()){
                pqmin.push(x);
            }else{
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        }else{
            if(x <= pqmin.top()){
                pqmax.push(x);
            }else{
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
}
int find(priority_queue<int, vector<int>, greater<int>>& pqmin,priority_queue<int>& pqmax){
    if(pqmax.size() == pqmin.size()){
        return (pqmax.top() + pqmin.top()) / 2;
    }
    if(pqmax.size() > pqmin.size()){
        return pqmax.top();
    }
    return pqmin.top();
}
void findMedian(int *arr, int n){
    priority_queue<int, vector<int>, greater<int>> pqmin;
    priority_queue<int> pqmax;
    for(int i = 0; i < n; i++){
        insert(arr[i], pqmin, pqmax);
        cout << find(pqmin ,pqmax) << " ";
    }
}
int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	findMedian(a, n);
}
