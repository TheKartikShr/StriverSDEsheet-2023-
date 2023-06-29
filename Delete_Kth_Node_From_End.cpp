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

int size(Node* head, int cnt){
	Node* temp = head;
	while(temp != NULL){
		temp = temp -> next;
		cnt++;
	}
	return cnt;
}

Node* removeKthNode(Node* head, int K){
    if(head -> next == NULL){
        return NULL;
    }
    if(size(head, 0) == K){
    	return head -> next;
    }
    Node* temp = reverse(head);
    int cnt = 1;
    Node* curr = temp;
    while(temp != NULL && cnt < K){
        temp = temp -> next;
        cnt++;
    }
    *temp = *temp -> next;
    curr = reverse(curr);
    return curr;
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
	Node* temp1 = removeKthNode(head, 3);
	print(temp1);

}