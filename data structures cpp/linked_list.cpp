/*This includes the following functions:
-insert at front
-insert at back
-print list in normal order
-print list in reverse order
-delete a node
-search list for a perticular node
-to reverse a linked list
-to make linked list circular
-to detect circle in list and return pointer to start of circle-floyd algorithm
-to merge to sorted list 
-to split list into two halves
-to sort list using merge sort
*/

#include<iostream>
using std::cout;

struct Node{
	int data;
	Node* next;
};

// To initialize 1'st Node 
void nodeInit(struct Node* head, int data){
	head->data = data;
	head->next = NULL;
}

// Insert new node at end of linked list.
void insertNodeBack(struct Node* head, int data){
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	Node *temp = head;
	while(temp->next) temp = temp->next;
	temp->next = newNode;
}

//Insert new node at front of list.
struct Node* insertNodeFront(struct Node *head, int data){
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = head;
	return newNode;
}

//To print elements of linked list.
void printList(struct Node* head){
	while(head) {
	cout << head->data << " " ;
	head = head->next;
	}
	cout << "\n" ;
}

//Print list reversed.
void printReverse(struct Node *head){
	if(!head) return;
	printReverse(head->next);
	cout << head->data <<" ";
}
//Search if a perticular node is in the list or not.
bool searchList(struct Node *head, int data){
	while(head){
		if(head->data == data) return true;
		head = head->next;
	}
	return false;
}

//Delete a node from list.
void deleteNode(struct Node **head, int data){
	Node *curr = *head;
	Node *temp = NULL;
	if(curr->data == data){
		*head = curr->next;
		delete curr;
		return;
	}
	while(curr->data != data){
		temp = curr;
		curr = curr->next;
		if(!curr){
			cout << "Node not in the list. \n" ;
			return;
		}
	}
	temp->next = curr->next;
	delete curr;
}

//Reverse link list.
void reverse(struct Node **head){
	Node *curr ,*prev ,*next;
	curr = *head;
	prev = NULL;
	while(curr){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		
	}
	*head = prev;
}

//Make the list circuler
void makeCirculer(struct Node *head){
	Node *curr = head;
	while(curr->next) curr = curr->next;
	curr->next = head;
}

//To detect circle in list
struct Node* detectCircle(Node *head){
	Node *slow, *fast;
	slow = head;
	fast = head;
	if(!slow || !slow->next)	return NULL;
	while(fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) return slow;
	}
	return NULL;
}

//Merge two sorted list's . 
struct Node* mergeSorted(struct Node *headA, struct Node *headB){
	Node *curr = NULL;
	if(!headA) return headB;
	if(!headB) return headA;
	if(headA->data <= headB->data){
		curr = headA;
		curr->next = mergeSorted(headA->next, headB);
	}
	if(headA->data > headB->data){
		curr = headB;
		curr->next = mergeSorted(headA, headB->next);
	}
	return curr;
}

//UTILITY FUNCTION FOR SORTING LINKED LIST.
void split(struct Node *head, struct Node **headA, struct Node **headB){
	Node *slow, *fast;
	slow = head;
	fast = head;
	if(!head || !head->next){
		*headA = head;
		*headB = NULL;
	}
	else{
		slow = head;
		fast = head->next;
		while(fast){
			fast = fast->next;
			if(fast){
				slow = slow->next;
				fast = fast->next;
			}
		}
		*headA = head;
		*headB = slow->next;
		slow->next = NULL;
	}
}

// To Sort link list -merge sort.
void mergeSort(struct Node **headRef){
	Node *head = *headRef;
	Node *a, *b;
	if(!head || !head->next) return;
	split(head, &a, &b);
	mergeSort(&a);
	mergeSort(&b);
	*headRef = mergeSorted(a, b);
}
int main(){
	Node *headA = new Node;
	nodeInit(headA, 1);
	insertNodeBack(headA, 500);
	insertNodeBack(headA, 110);
	insertNodeBack(headA, 2);
	insertNodeBack(headA, 50);
	headA = insertNodeFront(headA, 0);
	printList(headA);
	mergeSort(&headA);
	printList(headA);
	return 0;
}
