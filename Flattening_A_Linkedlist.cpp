#include<bits/stdc++.h>

using namespace std;

class Node{
	public:
		int data;
		Node* right, *down;
};


Node* head = NULL;

Node* push(Node* head, int data){
	Node* temp = new Node();
	temp -> data = data;
	temp -> right = NULL;
	temp -> down = head;
	head = temp;
	return head;
}

Node* merge(Node* d, Node* r){
	if(d == NULL){
		return r;
	}
	if(r == NULL){
		return d;
	}
	Node* res;
	if(d -> data < r -> data){
		res = d;
		res -> down = merge(d -> down, r);
	}else{
		res = r;
		res -> down = merge(d, r -> down);
	}
	res -> right = NULL;
	return res;
}

Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head -> right == NULL){
		return head;
	}
	Node* curr = flattenLinkedList(head -> right);
	head -> right = NULL;
	Node* temp = merge(head, curr);
	return temp;
}


void print(){
	Node* temp = head;
	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> down;
	}
	cout << endl;
}

int main(){
	head = push(head, 3);
	head = push(head, 2);
	head = push(head, 1);

	head -> right = push(head -> right, 6);
	head -> right = push(head -> right, 5);
	head -> right = push(head -> right, 4);


	head -> right -> right = push(head -> right -> right, 8);
	head -> right -> right = push(head -> right -> right, 7);

	head -> right -> right -> right = push(head -> right -> right -> right, 12);
	head -> right -> right -> right = push(head -> right -> right -> right, 9);

	head -> right -> right -> right -> right = push(head -> right -> right -> right -> right, 20);

	head = flattenLinkedList(head);
	print();
}