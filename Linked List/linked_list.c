#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *nextNode;
}node;

node* createNode(){
  node *temp = (node*) malloc(sizeof(node));
  temp->nextNode=NULL;
  temp->value=0;
}


void traverseLinkedList(node* head){

    printf("Value of node is:\t%d\n", head->value);

    if(head->nextNode!=NULL){
        traverseLinkedList(head->nextNode);
    } else{
      return;
    }

}

void insertAtEnd(node* head, int val){
  if(head->nextNode!=NULL){
    insertAtEnd(head->nextNode, val);
  }
  if(head->nextNode==NULL){
    node *temp = createNode();
    temp->nextNode=NULL;
    temp->value=val;
    head->nextNode=temp;
  }
  return;
}

node* insertAtBeginning(node *head, int val){
  
  node *temp = createNode();
  temp->nextNode = head;
  temp->value = val;
  return temp;

}

node* returnAtPosition(node *head, int position){
  static int pos=0;
  if(pos==position-1){
    return head;
  } else{
    pos++;
    returnAtPosition(head->nextNode, position);
  }
}

void insertAtPosition(node *head, int position, int val){
  node *temp = returnAtPosition(head,position-1);
  
  node *temp1 = createNode();
  temp1->nextNode=temp->nextNode;
  temp->nextNode=temp1;
  temp1->value=val;
  return;

}

void deleteAtPosition(node *head, int position){
  node *temp = returnAtPosition(head,position-1);
  node *temp2=temp->nextNode->nextNode;
  free(temp->nextNode);
  temp->nextNode=temp2;

}

node* deleteFirst(node *head){
  node *temp = head->nextNode;
  free(head);
  return temp;
}

node* getLast(node *head){
  if(head->nextNode==NULL){
    return head;
  } else {
    getLast(head->nextNode);
  }
}

node* getSecondLast(node *head){
  if(head->nextNode->nextNode==NULL){
    return head;
  } else {
    getSecondLast(head->nextNode);
  }
}

void deleteLast(node *head){
  node *temp = getSecondLast(head);
  free(temp->nextNode);
  temp->nextNode=NULL;
}

int number(node *head){
  static int no=0;
  if(head->nextNode==NULL){
    int temp=no;
    no=0;
    return temp+1;
  } else{
    no++;
    number(head->nextNode);
  }
}

//
// A -> B -> C -> D -> E
// 

node* reverseLinkedList(node *head){
  
  node *prev;
  node *curr;
  node *next;

  prev = head;
  curr = head->nextNode;
  

  while(next!=NULL){

    next = curr->nextNode;
    curr->nextNode=prev;
    prev = curr;
    curr = next;
  }
  head->nextNode=NULL;
  return prev;

}



int main() {

  
  node *head = createNode();
  head->value=10;
  head->nextNode=NULL;
  

  insertAtEnd(head,20);
  insertAtEnd(head,30);
  insertAtEnd(head,40);
  insertAtEnd(head,50);
  insertAtEnd(head,60);
  insertAtEnd(head,70);
  insertAtEnd(head,80);
  insertAtEnd(head,90);


  printf("\n\n");

  traverseLinkedList(head);

  printf("\n\nThe no of elements is:\t%d\n\n",number(head));

  printf("\n\nReturn At Position 3:\t%d", returnAtPosition(head, 3)->value);

  head=reverseLinkedList(head);

  printf("\n\n");

  traverseLinkedList(head);
   
  return 0;
}