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
Node* getMid(Node* temp){
    Node* slow = temp;
    Node* fast = temp;
    while(fast -> next != NULL && fast -> next -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}
Node* reverse(Node* temp){
    Node* prev, *current, *next;
    prev = NULL;
    current = temp;
    while(current != NULL){
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
bool isPalindrome(Node *head) {
    if(head == NULL || head -> next == NULL){
        return true;
    }
    Node* mid = getMid(head);
    Node* temp = head;
    mid -> next = reverse(mid -> next);
    mid = mid -> next;
    while(mid != NULL){
        if(mid -> data != temp -> data){
            return false;
        }
        mid = mid -> next;
        temp = temp -> next;
    }
    return true;
}
int main(){
	int t;
	cin >> t;
	while(t--){	
		Linkedlist list1;
		list1.push(1);
		list1.push(2);
		list1.push(3);
		list1.push(2);
		list1.push(1);
		cout << (isPalindrome(list1.head) == 1 ? "YES" : "NO") << endl;
	} 
}

   