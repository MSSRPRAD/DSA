#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Number_t {
    int magnitude;
    struct Number_t *next;
    struct Number_t *prev;
};

typedef struct Number_t Number;

Number *createNumber(int val){
    Number *newNumber = malloc(sizeof(Number));
    newNumber->magnitude = val;
    newNumber->next = NULL;
    newNumber->prev = NULL;
    return newNumber;
}

Number *addToList(Number *head, int val){
    Number *temp = createNumber(val);
    Number *current = head;
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

Number *readList(){
    Number *head = NULL;
    int k;
    scanf("%d", &k);
    for(int i=1;i<=k;i++){
        int tmp;
        scanf("%d", &tmp);
        head = addToList(head, tmp);
    }
    return head;
}

void printList(Number *head){
    Number *current = head;
    while(current != NULL){
        printf("%d ", current->magnitude);
        current = current->next;
    }
    return;
}

int findSumTill(Number *left){
    int sum=0;
    Number *current = left;
    while(current!=NULL){
        sum+=current->magnitude;
        current=current->prev;
    }
    return sum;
}

int findSumFrom(Number *right){
    int sum=0;
    Number *current = right;
    while(current != NULL){
        sum+=current->magnitude;
        current = current->next;
    }
    return sum;
}

Number *findN(Number *head, int a){
    int x=1;
    Number *current = head;
    while(x!=a){
        current = current->next;
        x++;
    }
    return current;
}

int size(Number *head){
    int x=0;
    Number *current = head;
    while(current!=NULL){
        x++;
        current=current->next;
    }
    return x;
}

Number *middleNumber(Number *left, Number *right){
    if(left == NULL){
        return NULL;
    }
    Number *slow = left, *fast = right;
    while(fast!=NULL && fast->next != NULL){
        slow=slow->next;
        fast=fast->next;
        fast=fast->next;
    }
    return slow;
}

Number *findSqrt(Number *head, int square){
    //right, left are at head, last positions
    Number *left = head;
    Number *right = head;
    while(right->next != NULL){
        right = right->next;
    }
    //Now the loop for finding the sqrt
    while(left != right){
        Number *mid = middleNumber(left,right);
        if(mid->magnitude*mid->magnitude == square){
            return mid;
        } else if(mid->magnitude*mid->magnitude<square){
            left = left->next;
        }  else{
            right = mid;
        }
    }
    return left->prev;
}

Number *findLastUnique(Number *left, Number *right){
    Number *lst = right;
    int val = left->magnitude;
    //Now the loop for finding the sqrt
    while(left != right && right != NULL){
        Number *mid = middleNumber(left,right);
        if(mid->magnitude != val){
            return mid;
        } else if(mid->magnitude > val){
            right = mid->prev;
        } else {
            left = mid->next;
        }
    }
    
    return right;
}

int findUnique(Number *head){
    int count=0;
    Number *last = head;
    while(last->next != NULL){
        last = last->next;
    }
    Number *left = head;
    while(true){
        //printf("\n%d", left->magnitude);
        count++;
        //printf("\t%d", count);
        left = findLastUnique(left, last);
        //printf("\tsee:%d\t %d", left->magnitude, (left->prev)->magnitude);
        if(left->next == NULL && (left->magnitude != (left->prev)->magnitude)){
            return count+1;
        }
        if(left == last){
            break;
        }
    }
    return count;
}

int main(void){
    Number *head = readList();
    //printList(head);
    Number *last1 = head;
    while(last1->next != NULL){
        last1 = last1->next;
    }
    printf("\n%d", findUnique(head));
}