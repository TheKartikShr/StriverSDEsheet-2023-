#include<bits/stdc++.h>

using namespace std;

void insertNode(stack<int>& stack, int curr){
	if(stack.empty() || stack.top() < curr){
		stack.push(curr);
		return;
	}
	int val = stack.top();
	stack.pop();
	insertNode(stack, curr);
	stack.push(val);
}
void sortStack(stack<int> &stack){
	if(stack.empty()){
		return;
	}
	int curr = stack.top();
	stack.pop();

	sortStack(stack);
	insertNode(stack, curr);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		stack<int> s;
		vector<int> curr = {1, 2, 5, 3, 2, 3, 4, 5};
		for(int i = 0; i < 8; i++){
			s.push(curr[i]);
		}
		sortStack(s);
		while(!s.empty()){
			cout << s.top() << endl;
			s.pop();
		}
	}
}