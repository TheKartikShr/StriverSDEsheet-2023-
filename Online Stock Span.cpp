#include<bits/stdc++.h>

using namespace std;

vector<int> prevSmallerElement(vector<int>& heights, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans;
        int x = 1;
        for(int i=0; i<n; i++) {
            int curr = heights[i];
            while(s.top() != -1 && heights[s.top()] <= curr)
            {
                s.pop();
            }
            //ans is stack ka top
          	cout << s.top() << endl;
            if(s.top() == -1){
            	ans.push_back(i + 1);
            }else{
            	ans.push_back(i - s.top());
            }
            s.push(i);
        }
        return ans; 
}
vector<int> findSpans(vector<int> &price) {
    return prevSmallerElement(price, price.size());
}
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> nse = findSpans(a);
	for(int i = 0; i < n; i++){
		cout << nse[i] << " ";
	}

	cout << endl;
}