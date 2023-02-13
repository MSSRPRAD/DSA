#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Player_t {
    int skill;
    struct Player_t *next;
    struct Player_t *prev;
};

typedef struct Player_t Player;

Player *createPlayer(int val){
    Player *newPlayer = malloc(sizeof(Player));
    newPlayer->skill = val;
    newPlayer->next = NULL;
    newPlayer->prev = NULL;
    return newPlayer;
}

Player *addToTeam(Player *head, int val){
    Player *temp = createPlayer(val);
    Player *current = head;
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

Player *readTeam(){
    Player *head = NULL;
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d", &tmp);
        head = addToTeam(head, tmp);
    }
    return head;
}

void printList(Player *head){
    Player *current = head;
    while(current != NULL){
        printf("%d ", current->skill);
        current = current->next;
    }
    return;
}

int findSumTill(Player *left){
    int sum=0;
    Player *current = left;
    while(current!=NULL){
        sum+=current->skill;
        current=current->prev;
    }
    return sum;
}

int findSumFrom(Player *right){
    int sum=0;
    Player *current = right;
    while(current != NULL){
        sum+=current->skill;
        current = current->next;
    }
    return sum;
}

Player *findN(Player *head, int a){
    int x=1;
    Player *current = head;
    while(x!=a){
        current = current->next;
        x++;
    }
    return current;
}

int size(Player *head){
    int x=0;
    Player *current = head;
    while(current!=NULL){
        x++;
        current=current->next;
    }
    return x;
}

int main(void){
    Player *head = readTeam();
   /// printList(head);
    Player *left = head;
    Player *right = head;
    while(right->next!=NULL){
        right = right->next;
    }
    int lft =0;
    int rght =0;
    int cond=1;
    int sum=0;
    Player *l, *r;
    while(left!=right){
        if(findSumFrom(right)>findSumTill(left)){
            left = left->next;
        } else if(findSumFrom(right)<findSumTill(left)){
            right = right->prev;
        } else {
            lft = findSumTill(left);
            rght = findSumFrom(right);
            l=left;
            r=right;
            left = left->next;
        }
    }

    int n1=1;
    int n2=0;
    Player *current = head;
    while(current!=l){
        current=current->next;
        n1++;
    }
    current=r;
    while(current!=NULL){
        current=current->next;
        n2++;
    }

    printf("\n%d %d\n", n1, n2);

}