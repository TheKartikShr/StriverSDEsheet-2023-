#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node* next, *random;
	Node(int data){
		this -> data = data;
		this -> next = NULL;
		this -> random = NULL;
	}
};

void inserAtTail(Node* &head, Node* &tail, int data){
    Node* temp = new Node(data);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }else{
        tail -> next = temp;
        tail = temp;
    }
}
Node *cloneRandomList(Node *head){
    // step1 -> clone the list

    Node* thead = NULL;
    Node* tail = NULL;
    Node* temp = head;
    while(temp != NULL){
        inserAtTail(thead, tail, temp -> data);
        temp = temp -> next;
    }
    
    // step2 -> mapping orignal list -> clone list
    unordered_map<Node*, Node*> mp1;
    Node* orignal = head;
    Node* clone = thead;
    while(orignal != NULL && clone != NULL){
        mp1[orignal] = clone;
        orignal = orignal -> next;
        clone = clone -> next;
    }

    // step3 -> mapping randome pointers
    orignal = head;
    clone = thead;
    while(orignal != NULL){
        clone -> random = mp1[orignal -> random];
        orignal = orignal -> next;
        clone = clone -> next;
    }
    return thead;

}


void print(Node* head){
	while(head != NULL){
		cout << head -> data << " " << head -> random -> data - 1 << " ";
		head = head -> next;
	}
	cout << -1 << endl;
}

int main(){
	Node* head = new Node(1);
	head -> next = new Node(2);
	head -> next -> next = new Node(3);
	head -> next -> next -> next = new Node(4);
	head -> next -> next -> next -> next = new Node(5);
	head -> random = head -> next -> next;
	head -> next -> random = head;
	head -> next -> next -> random = head -> next -> next -> next -> next;
	head -> next -> next -> next -> random = head -> next -> next -> next -> next;
	head -> next -> next -> next -> next -> random = head -> next;

	Node* temp = cloneRandomList(head);
	print(temp);
	return 0;
}