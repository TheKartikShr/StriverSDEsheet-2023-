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

Node *addTwoNumbers(Node *num1, Node *num2){
    Node *res = new Node(-1);
    Node *curr = res;
    int carry = 0;
    int sum = 0;
    while(num1 && num2){
        sum = num1->data + num2->data + carry;
        Node *node = new Node(sum%10);
        carry = sum/10;
        curr->next = node;
        curr = curr->next;
        num1 = num1->next;
        num2 = num2->next;
    }
    while(num1){
        sum = num1->data + carry;
        Node *node = new Node(sum%10);
        carry = sum/10;
        curr->next = node;
        curr = curr->next;
        num1 = num1->next;
    }
    while(num2){
        sum = num2->data + carry;
        Node *node = new Node(sum%10);
        carry = sum/10;
        curr->next = node;
        curr = curr->next;
        num2 = num2->next;
    }
    if(carry != 0){
        Node *node = new Node(carry);
        curr->next = node;
        curr = curr->next;
    }
    return res->next;
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

	Node* temp1 = addTwoNumbers(head, head1);
	print(temp1);

}