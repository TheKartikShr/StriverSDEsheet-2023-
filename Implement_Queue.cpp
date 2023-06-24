#include<bits/stdc++.h>

using namespace std;

class Queue {
public:
    vector<int> a;
    int start, end, size;
    Queue() {
        size = 12;
        a.resize(size);
        start = 0;
        end = 0;
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(start == end){
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        if(end != size){
            a[end++] = data;
        }
    }

    int dequeue() {
        if(start == end){
            return -1;
        }
        int curr = a[start];
        start++;
        if(start == end){
            start = end = 0;
        }
        return curr;
    }

    int front() {
        if(start == end){
            return -1;
        }
        return a[start];
    }
};

int main(){
	Queue* s = new Queue();
	for(int i = 1; i <= 10; i++){
		s -> enqueue(i);
	}
	cout << "Front Element of queue -> " << s -> front() << endl;
	s -> dequeue(); // Deleting Top Most element of stack
	cout << "Front Element of queue after deleting -> " << s -> front() << endl;
	if(s -> isEmpty()){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}