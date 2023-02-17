#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Student_t {
    int id;
    struct Student_t *next;
    struct Student_t *prev;
};

typedef struct Student_t Student;

Student *createStudent(int val){
    Student *newStudent = malloc(sizeof(Student));
    newStudent->id = val;
    newStudent->next = NULL;
    newStudent->prev = NULL;
    return newStudent;
}

Student *addToList(Student *head, int val){
    Student *temp = createStudent(val);
    Student *current = head;
    if(current==NULL){
        return temp;
    } else {
        while(current->next != NULL){
            current=current->next;
        }
        current->next = temp;
        temp->prev = current;
    }
    return head;
}

Student *readList(int *k){
    Student *head = NULL;
    int n;
    scanf("%d %d", &n, k);
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d", &tmp);
        head = addToList(head, tmp);
    }
    return head;
}

void printList(Student *head){
    Student *current = head;
    while(current != NULL){
        printf("%d ", current->id);
        current = current->next;
    }
    return;
}

int findSumTill(Student *left){
    int sum=0;
    Student *current = left;
    while(current!=NULL){
        sum+=current->id;
        current=current->prev;
    }
    return sum;
}

int findSumFrom(Student *right){
    int sum=0;
    Student *current = right;
    while(current != NULL){
        sum+=current->id;
        current = current->next;
    }
    return sum;
}

Student *findN(Student *head, int a){
    int x=1;
    Student *current = head;
    while(x!=a){
        current = current->next;
        x++;
    }
    return current;
}

int size(Student *head){
    int x=0;
    Student *current = head;
    while(current!=NULL){
        x++;
        current=current->next;
    }
    return x;
}

int main(void){
    int k;
    Student *head = readList(&k);
    printList(head);
    Student *last = head;
    while(last->next!=NULL){
        last = last->next;
    }
    last->next = head;
    head->prev = last;
    for(int i=0;i<k;i++){
        head=head->prev;
        last=last->prev;
    }
    head->prev = NULL;
    last->next = NULL;
    printf("\n\n");
    printList(head);
}