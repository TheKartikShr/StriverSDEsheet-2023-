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

void push1(Node* &head, Node* &tail, int data){
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

Node* reverse(Node* head){
     Node* prev = NULL;
     Node* curr = head;
     Node* nxt;
     while(curr != NULL){
          nxt = curr -> next;
          curr -> next = prev;
          prev = curr;
          curr = nxt;
     }
     return prev;
}

int size(Node* head){
     int cnt = 0;
     Node* temp = head;
     while(temp != NULL){
          temp = temp -> next;
          cnt++;
     }
     return cnt;
}

Node *rotate(Node *head, int k) {
     int sz = size(head);
     if(k == 0){
          return head;
     }
     Node* temp1 = head;
     temp1 = reverse(temp1);
     Node* temp2 = temp1;  
     int mx = k % sz;
     Node* anshead = NULL;
     Node* anstail = NULL;
     Node* anshead1 = NULL;
     Node* anstail1 = NULL;
     while(temp1 != NULL && mx-- > 0){
          push1(anshead, anstail, temp1 -> data);
          temp1 = temp1 -> next;
     }
     anshead = reverse(anshead);
     temp1 = reverse(temp1);
     while(anshead != NULL){
          push1(anshead1, anstail1, anshead -> data);
          anshead = anshead -> next;
     }
     while(temp1 != NULL){
          push1(anshead1, anstail1, temp1 -> data);
          temp1 = temp1 -> next;
     }
     return anshead1;
}


int main(){
	Node* head = new Node(1);
	Node* tail = head;
	push(tail, 2);
	push(tail, 3);
	push(tail, 4);
	push(tail, 5);
	push(tail, 6);
	push(tail, 7);
	Node* temp = rotate(head, 6);
	print(temp);
}