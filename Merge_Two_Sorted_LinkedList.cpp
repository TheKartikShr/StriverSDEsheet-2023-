#include<bits/stdc++.h>

using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node(int data){
			this -> data = data;
			this -> next = NULL;
		}
};

void insert(Node* &tail, int data){
	Node* temp = new Node(data);
	tail -> next = temp;
	tail = tail -> next;
}

void print(Node* &head){
	Node* temp = head;
	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next;
    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void insert(Node* &head, Node* &tail, int data){
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
Node* sortTwoLists(Node* first, Node* second)
{
    Node* temp1 = first;
    Node* temp2 = second;
    Node* anshead = NULL;
    Node* anstail = NULL;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1 -> data <= temp2 -> data){
            insert(anshead, anstail, temp1 -> data);
            temp1 = temp1 -> next;
        }else{
            insert(anshead, anstail, temp2 -> data);
            temp2 = temp2 -> next;
        }
    }
    while(temp1 != NULL){
        insert(anshead, anstail, temp1 -> data);
        temp1 = temp1 -> next;
    }
    while(temp2 != NULL){
        insert(anshead, anstail, temp2 -> data);
        temp2 = temp2 -> next;
    }
    return anshead;
}
int main(){
	Node* node1 = new Node(1);
	Node* node2 = new Node(4);
	Node* head = node1;
	Node* tail = node1;

	Node* head1 = node2;
	Node* tail1 = node2;

	insert(tail, 2);
	insert(tail, 3);

	insert(tail1, 5);
	insert(tail1, 6);
	Node* temp1 = sortTwoLists(head, head1);
	print(temp1);

}