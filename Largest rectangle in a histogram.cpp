#include <bits/stdc++.h>
using namespace std; 



vector<int> nextSmallerElement(vector<int>& a){
  vector<int> nxt(a.size());
  stack<int> s;
  for(int i = 0; i < a.size(); i++){
    while(!s.empty() && a[i] < a[s.top()]){
      nxt[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }
  while(!s.empty()){
    nxt[s.top()] = -1;
    s.pop();
  }
  return nxt;
}

vector<int> prevSmallerElement(vector<int>& a){
  vector<int> prev(a.size());
  stack<int> s;
  s.push(-1);
  for(int i = 0; i < a.size(); i++){
    while(s.top() != -1 && a[i] <= a[s.top()]){
      s.pop();
    }
    prev[i] = s.top();
    s.push(i);
  }
  return prev;
}

int largestRectangle(vector < int > & heights) {
  int n = heights.size();
  vector<int> nxt = nextSmallerElement(heights);
  vector<int> prev = prevSmallerElement(heights);
  int ans = INT_MIN;
  for(int i = 0; i < n; i++){
    int l = heights[i];
    if(nxt[i] == -1){
      nxt[i] = n;
    }
    int b = nxt[i] - prev[i] - 1;
    ans = max(ans, l * b);
  }
  return ans;
}



int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << largestRectangle(a) << endl;
}

