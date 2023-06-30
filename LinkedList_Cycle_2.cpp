#include<bits/stdc++.h>

using namespace std;


struct Node{
	int data;
	Node* next = NULL;
	Node(int data){
		this -> data = data;
		this -> next = NULL;
	}
};

void push(Node* &tail, int data){
	Node* temp = new Node(data);
	tail -> next = temp;
	tail = temp;
}


void print(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

Node *firstNode(Node *head){
    map<Node*, pair<bool, Node*>> mp1;
    Node* temp = NULL;
    while(head != NULL){
        bool flag = mp1[head].first;
        if(flag == true){
            temp = mp1[head].second;
            break;
        }
        mp1[head] = {true, head};
        head = head -> next;
    }
    return temp;
}


int main(){
	Node* head = new Node(1);
	Node* tail = head;
	push(tail, 2);
	push(tail, 3);
	push(tail, 4);
	head -> next -> next -> next = head -> next;
	Node* temp = firstNode(head);
	cout << temp -> data << endl;
}