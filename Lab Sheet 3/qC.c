#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Song_t {
	int song;
	struct Song_t *prev;
	struct Song_t *next;
};

typedef struct Song_t Song;

Song *createSong(int a){
	Song *temp = malloc(sizeof(Song));
	temp->next = NULL;
	temp->prev = NULL;
	temp->song = a;
	return temp;
}

Song *addToPlaylist(Song *head, int a){
	Song *temp = createSong(a);
	if(head==NULL){
		return temp;
	} else{
		Song *current = head;
		while(current->next != NULL){
			current = current->next;
		}
		current->next = temp;
		temp->prev = current;
		return head;
	}
}

Song *readPlaylist(int *n, int *n1){
	Song *head = NULL;
	int x, y;
	scanf("%d %d", &x, &y);
	*n=y;
	*n1=x;
	for(int i=0;i<y;i++){
		int temp;
		scanf("%d", &temp);
		head = addToPlaylist(head, temp);
	}
	return head;
}

void printPlaylist(Song *head){
	Song *temp = head;
	while(temp!=NULL){
		printf("%d ", temp->song);
		temp = temp->next;
	}
}

bool Having(Song *head, int val){
	Song *current = head;
	while(current != NULL){
		if(current->song == val){
			return true;
		}
		current = current->next;
	}
	return false;
}

Song *findNHaving(Song *head, int val){
	Song *current = head;
	while(current != NULL){
		if(current->song == val){
			return current;
		}
		current = current->next;
	}
}

Song *findLast(Song *head){
	Song *cur = head;
	while(cur->next!=NULL){
		cur = cur->next;
	}
	return cur;
}

int size(Song *head){
	int n=0;
	Song *cur = head;
	while(cur!=NULL){
		cur=cur->next;
		n++;
	}
	return n;
}

int main(void){
	int n, n1;
	Song *head = readPlaylist(&n, &n1);
	Song *pointer1 = head;
	Song *pointer2 = findLast(head);
	for(int i=1;i<=n && pointer1!=NULL && pointer2!=NULL;i++){
		
		//printf("\n%d %d\n1", pointer1->song, pointer2->song);
		if((pointer1->song+pointer2->song)==n1){
			return 0;
		} else if((pointer1->song+pointer2->song)>n1){
			pointer2 = pointer2->prev;
		} else{
			pointer1 = pointer1->next;
		}
	}
	printf("\n0");
	
	return 0;
}
