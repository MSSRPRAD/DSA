#include<stdio.h>
#include<stdlib.h>

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

Song *readPlaylist(){
	Song *head = NULL;
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
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

int main(void){
	Song *head = readPlaylist();
	Song *current = head;
	int x=999,y=999;
	printf("\n");
	while(x!=5){
		scanf("%d", &x);
		switch(x){
			case 1:
				scanf("%d", &y);
				addToPlaylist(head, y);
				break;
			case 2:
				printf("%d\n", current->song);
				break;
			case 3:
				if(current->next!=NULL){
					current = current->next;
				}
				break;				
			case 4:
				if(current->prev!=NULL){
					current = current->prev;
				}
				break;
			case 5:
				break;
		}
	}
	
}
