#include <bits/stdc++.h>
using namespace std; 

void insert(int x, priority_queue<int, vector<int>, greater<int>>& pq_min, priority_queue<int>& pq_max){
    if(pq_min.size() == pq_max.size()){
        if(pq_max.size() == 0){
            pq_max.push(x);
        }
        if(x < pq_max.top()){
            pq_max.push(x);
        }else{
            pq_min.push(x);
        }
    }
    if(pq_max.size() > pq_min.size()){
        if(x >= pq_max.top()){
            pq_min.push(x);
        }else{
            int temp = pq_max.top();
            pq_max.pop();
            pq_min.push(temp);
            pq_max.push(x);
        }
    }
    if(pq_max.size() < pq_min.size()){
        if(x <= pq_min.top()){
            pq_max.push(x);
        }else{
            int temp = pq_min.top();
            pq_min.pop();
            pq_max.push(temp);
            pq_min.push(x);
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
vector<int> findMedian(vector<int> &arr, int n){
    priority_queue<int, vector<int>, greater<int>> pq_min;
    priority_queue<int> pq_max; 
    vector<int> ansvec;
    for(int i = 0; i < n; i++){
        insert(arr[i], pq_min, pq_max);
        ansvec.push_back(find(pq_min, pq_max));
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
    vector<int> curr = findMedian(a, n);
    for(auto i : curr){
        cout << i << " ";
    }
    cout << endl;
}
