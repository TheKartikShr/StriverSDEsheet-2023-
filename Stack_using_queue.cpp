#include<bits/stdc++.h>

using namespace std;

class Stack {
	// Define the data members.
    queue<int> q1, q2;
   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q1.size();
    }

    bool isEmpty() {
        return q1.empty();
    }

    void push(int element) {
        q1.push(element);
        // Implement the push() function.
    }

    int pop() {
        if(q1.empty()){
            return -1;
        }
         int ans=-1;
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        ans=q1.front();
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return ans;
        // Implement the pop() function.
    }

    int top() {
        if(q1.empty()){
            return -1;
        }
        int ans=-1;
        while(!q1.empty()){
            ans=q1.front();
            q2.push(ans);
            q1.pop();
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return ans;
        // Implement the top() function.
    }
};

int main(){
	Stack st;
	while(1){
		int x;
		cout << "Enter query: ";
		cin >> x;
		cout << endl;
		if(x == 1){
			int y;
			cout << "Enter the value to be pushed into the stack: ";
			cin >> y;
			st.push(y);
		}
		if(x == 2){
			cout << "Popped Element of stack: " << st.pop() << endl;
		}
		if(x == 3){
			cout << "Top Element of Stack: " << st.top() << endl;
		}
		if(x == 4){
			cout << "Size of the Stack: " << st.getSize() << endl;
		}
		if(x == 5){
			cout << "Is Stack Empty: " << (st.isEmpty() == 0 ? "NO" : "YES") << endl;
		}
		if(x == -1){
			break;
		}
	}
}