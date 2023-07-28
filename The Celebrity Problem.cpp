#include <bits/stdc++.h>
using namespace std; 
vector<vector<int>> a = {{0, 0, 1, 1, 1},
							{1, 0, 0, 1, 1},
							{0, 0, 0, 0, 1},
							{0, 1, 1, 0, 1},
						    {0, 0, 0, 0, 0}};

bool knows(int i, int j){
	return a[i][j] == 1;
}

int findCelebrity(int n) {
	stack<int> s;
	for(int i = 0; i < n; i++){
		s.push(i);
	}
	while(s.size() != 1){
		int a = s.top();
		s.pop();
		int b = s.top();
		s.pop();
		if(knows(a, b)){
			s.push(b);
		}else{
			s.push(a);
		}
	}
	int potentialCandidate = s.top();
	for(int i = 0; i < n; i++){
		if(knows(potentialCandidate, i)){
			return -1;
		}
		if(i != potentialCandidate && !knows(i, potentialCandidate)){
			return -1;
		}
	}
	return potentialCandidate;
}
int main(){
	int n;
	cin >> n;
	cout << findCelebrity(n) << endl;
}

