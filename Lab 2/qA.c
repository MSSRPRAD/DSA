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
		printf("%d\t", current->data);
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
		for(int i=0;i<a;i++){
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

int main(void){
	Node *head = readList();
	printf("\n%d", findMedian(head));
}
