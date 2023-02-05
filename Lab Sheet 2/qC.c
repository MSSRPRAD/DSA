#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct Node_t {
	int data;
	struct Node_t *next;
};

typedef struct Node_t Node;

Node *createNode(int val){
	Node *tmp = malloc(sizeof(Node));
	tmp->data=val;
	tmp->next=NULL;
	return tmp;
}
Node *addToList(Node *head, int val){
	Node *tmp = createNode(val);
	if(head==NULL){
		return tmp;
	} else{
		Node *current = head;
		while(current->next!=NULL){
			current = current->next;
		}
		current->next = createNode(val);
		return head;
	}
}
Node *readList(){
	Node *head = NULL;
	int no;
	scanf("%d", &no);
	for(int k=0;k<no;k++){
		int temp;
		scanf("%d", &temp);
		head = addToList(head, temp);
	}
	return head;
}
int size(Node *head){
	Node *current = head;
	int sz = 0;
	if(current==NULL){
		return 0;
	}
	while(current!=NULL){
		sz++;
		current = current->next;
	}
	return sz;
}
Node *printList(Node *head){
	Node *current = head;
	int no = size(head);
	for(int i=0;i<no;i++){
		printf("%d ", current->data);
		current=current->next;
	}
	return head;
	
}
Node *findN(Node *head, int a){
	int no = size(head);
	if(a<0 || a > no){
		printf("INCOMPATIBLE PARAMETER PASSED");
		return NULL;
	} else{
		Node *current = head;
		for(int i=1;i<a;i++){
			current = current->next;
		}
		return current;
	}
}

int findMedian(Node *head){
	int no = size(head);
	if(no==0){
		return 0;
	} else{
		int median = 0;
		if(no%2==0){
			median+=findN(head, no/2)->data;
			median+=findN(head, (no/2-1))->data;
			median/=2;
		} else{
			median+=findN(head, (no-1)/2)->data;
		}
		return median;
	}
}

Node *mergeLists(Node *head1, Node *head2){
	Node *merged = NULL;
	Node *curr1 = head1;
	Node *curr2 = head2;
	int n = size(head1)+size(head2);
	for(int i=1;i<n+1;i++){
		if(curr1 == NULL && curr2 == NULL){
			break;
		} else if(curr1 == NULL && curr2 != NULL){
			//printf("%d ", curr2->data);
			merged = addToList(merged, curr2->data);
			curr2 = curr2->next;
		} else if(curr2 == NULL && curr1 != NULL){
			//printf("%d ", curr1->data);
			merged = addToList(merged, curr1->data);
			curr1 = curr1->next;
		} else if( curr1->data < curr2->data ){
			//printf("%d ", curr1->data);
			merged = addToList(merged, curr1->data);
			curr1=curr1->next;
		} else if( curr2->data <= curr1->data ){
			//printf("%d ", curr2->data);
			merged = addToList(merged, curr2->data);
			curr2=curr2->next;
		}
	}
	return merged;
	
}

Node *swapAdjacent(Node **head, int a, int b){

	if(a==b){
		return *head;
	}
	//Make a the smaller number;
	if(a>b){
		int tmp = a;
		a=b;
		b=tmp;
	}
	
	Node *n1 = findN(*head, a);
	Node *n2 = findN(*head, b);
	Node *prev=NULL;
	//if a==1
	if(a==1){
		Node *tmp = n2->next;
		n2->next = n1;
		n1->next = tmp;
		return n2;
	}
	//else
	prev = findN(*head, a-1);
	Node *tmp = n2->next;
	//printf("%d %d %d\n", prev->data,n1->data,n2->data);
	prev->next=n2;
	n2->next=n1;
	n1->next=tmp;
	return *head;
	
}

Node *sortList(Node **head){
	Node *newList =NULL;
	int no = size(*head);
	for(int i=0;i<no-1;i++){
		for(int j=0;j<no-i;j++){
			if(findN(*head, j)->data>findN(*head, j+1)->data){
				*head = swapAdjacent(head, j, j+1);
			}
		}
	}
	return *head;
}

int main(void){
	Node *head = readList();
	Node *sorted = sortList(&head);
	printList(sorted);
}
