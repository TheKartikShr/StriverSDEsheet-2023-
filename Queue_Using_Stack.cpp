#include<bits/stdc++.h>

using namespace std;

class Queue {
    // Define the data members(if any) here.
    public:
    stack<int> st1, st2;
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
         st1.push(val);
        // Implement the enqueue() function.
    }

    int deQueue() {
        if(st1.empty()){
            return -1;
        }
         int ans=-1;
        while(st1.size()!=1){
            st2.push(st1.top());
            st1.pop();
        }
        ans=st1.top();
        st1.pop();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
        // Implement the dequeue() function.
    }

    int peek() {
        if(st1.empty()){
            return -1;
        }
        int ans=-1;
        while(!st1.empty()){
            ans=st1.top();
            st2.push(ans);
            st1.pop();
        }
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
        // Implement the peek() function here.
    }

    bool isEmpty() {
        return st1.empty();
        // Implement the isEmpty() function here.
    }
};
int main(){
	Queue st;
	while(1){
		int x;
		cout << "Enter query: ";
		cin >> x;
		cout << endl;
		if(x == 1){
			int y;
			cout << "Enter the value to be pushed into the Queue: ";
			cin >> y;
			st.enQueue(y);
		}
		if(x == 2){
			cout << "Popped Element of Queue: " << st.deQueue() << endl;
		}
		if(x == 3){
			cout << "Top Element of Queue: " << st.peek() << endl;
		}
		if(x == 4){
			cout << "Is Queue Empty: " << (st.isEmpty() == 0 ? "NO" : "YES") << endl;
		}
		if(x == -1){
			break;
		}
	}
}