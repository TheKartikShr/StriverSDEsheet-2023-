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

bool detectCycle(Node *head)
{
	if(head == NULL){
        return false;
    }
    map<Node*, bool> mp1;
    Node* temp = head;
    while(temp != NULL){
        if(mp1[temp] == true){
            return true;
        }
        mp1[temp] = true;
        temp = temp -> next;
    }
    return false;
}

int main(){
	Node* node = new Node(10);

	Node* head = node;
	Node* tail = node;

	insert(tail, 11);
	insert(tail, 12);
	insert(tail, 13);
	head -> next -> next -> next = head;	
	cout << detectCycle(head) << endl;
}