#include <bits/stdc++.h>
using namespace std; 

struct Node{
	int data;
	struct Node* next;
	Node(int data){
		this -> data = data;
		next = NULL;
	}
};

struct Linkedlist{
	Node* head;
	Linkedlist() {head = NULL; }

	Node *reverseLinkedlist(Node *head){
	    Node* prev;
	    Node* current;
	    Node* next;
	    prev = NULL, current = head;
	    while(current != NULL){
	        next = current -> next;
	        current -> next = prev;
	        prev = current;
	        current = next;
	    }
	    return prev;
	}
	void print(){
		struct Node* temp = head;
		while(temp != NULL){
			cout << temp -> data << " ";
			temp = temp -> next;

		}
	}
	void push(int data){
		Node* temp = new Node(data);
		temp -> next = head;
		head = temp;
	}
};
int main(){
	int t;
	cin >> t;
	while(t--){	
		int n;
		cin >> n;
		Linkedlist list;
		for(int i = 1; i <= n; i++){
			list.push(i);
		}
		list.print();
		cout << endl;
		list.head = list.reverseLinkedlist(list.head);
		list.print();
	} 
}

   