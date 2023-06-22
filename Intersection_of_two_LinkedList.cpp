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
int main(){
	int t;
	cin >> t;
	while(t--){	
		Linkedlist list1, list2;
		list1.push(1);
		list1.push(2);
		list1.push(3);
		list1.push(4);
		list1.push(5);
		list1.push(6);
		list2.push(9);
		list2.push(10);
		list2.push(13);
		list2.push(15);

		list1.head = list1.reverseLinkedlist(list1.head);
		list2.head = list2.reverseLinkedlist(list2.head);
		intersect(list1.head, list2.head, 5);
		Node* temp1 = findIntersection(list1.head, list2.head);
		cout << temp1 -> data << endl;
	} 
}

   
