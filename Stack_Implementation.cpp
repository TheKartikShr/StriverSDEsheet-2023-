#include<bits/stdc++.h>

using namespace std;

class Stack {
    
public:
    vector<int> a;
    int index, curr_size;
    Stack(int capacity) {
        a.resize(capacity);
        curr_size = capacity;
        index = 0;
    }

    void push(int num) {
        if(index !=  curr_size){
            a[index] = num;
            index++;
        }
    }

    int pop() {
        if(index != 0){
            index--;
            return a[index];
        }
        return -1;
    }
    
    int top() {
        if(index != 0){
            return a[index - 1];
        }
        return -1;
    }
    
    int isEmpty() {
        if(index == 0){
            return 1;
        }
        return 0;
    }
    
    int isFull() {
        if(index >= curr_size){
            return 1;
        }
        return 0;
    }
    
};

int main(){
	Stack* s = new Stack(10);
	for(int i = 1; i <= 10; i++){
		s -> push(i);
	}
	cout << "Top Element of Stack -> " << s -> top() << endl;
	s -> pop(); // Deleting Top Most element of stack
	cout << "Top Element of Stack after deleting -> " << s -> top() << endl;
	if(s -> isFull()){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	if(s -> isEmpty()){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}