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

	void deleteNode(Node* node) {
	    *node = *node -> next;
	}

	Node *findMiddle(Node *head) {
	    Node* slow = head;
	    Node* fast = head;
	    while(fast != NULL && fast -> next != NULL){
	        slow = slow -> next;
	        fast = fast -> next -> next;
	    }
	    return slow;
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

Node* findIntersection(Node *firstHead, Node *secondHead){
	    if(firstHead == NULL || secondHead == NULL){
	        return NULL;
	    }
	    Node* temp1 = firstHead;
	    Node* temp2 = secondHead;
	    while(temp1 != temp2){
	        temp1 = temp1 == NULL ? secondHead : temp1 -> next;
	        temp2 = temp2 == NULL ? firstHead : temp2 -> next;
	    }
	    return temp1;
}


void intersect(Node* temp1, Node* temp2, int pos){
		Node* curr1 = temp1;
		while(pos-- > 1){
			curr1 = curr1 -> next;
		}
		Node* curr2 = temp2;
		while(curr2 -> next != NULL){
			curr2 = curr2 -> next;
		}
		curr2 -> next = curr1;
}


Node* help(Node* head, int n, int b[], int index){
	if(n < 1 || head == NULL || head -> next == NULL){
		return head;
	}
	Node* prev = NULL;
	Node* current = head;
	Node* next;
	int cnt = 0;
	while(b[index] == 0 && index < n){
		index++;
	}
	while(current != NULL && cnt < b[index] && index < n){
		next = current -> next;
		current -> next = prev;
		prev = current;
		current = next;
		cnt++;
	}
	if(index >= n && current != NULL){
		return head;
	}
	if(current != NULL){
		head -> next = help(next, n, b, index + 1);
	}
	return prev;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	return help(head, n, b, 0);
}
int main(){
	int t;
	cin >> t;
	while(t--){	
		Linkedlist list1, list2;
		int n;
		cin >> n;
		int b[n];
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}
		for(int i = 1; i <= 10; i++){
			list1.push(i);
		}
		list1.head = list1.reverseLinkedlist(list1.head);
		Node* temp = getListAfterReverseOperation(list1.head, n, b);
		list1.head = temp;
		list1.print();
	} 
}

   