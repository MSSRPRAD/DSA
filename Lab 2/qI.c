#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>

struct Student_t {
	char email[1000];
	char branch[1000];
	char id[1000];
};

typedef struct Student_t Student;

bool isSame(char *c1, char *c2){
	if(strlen(c1)!=strlen(c2)){
		//printf("\n%d\t%d", strlen(c1), strlen(c2));
		return false;
	} else{
		for(int i=0;i<strlen(c1);i++){
		//printf("\n%c\t%c", c1[i], c2[i]);
			if(c1[i]!=c2[i]){
				return false;
			}
		}
		return true;
	}
}

void *generateId(Student **s){
	for(int k=0;k<4;k++){
		(*s)->id[k] = (*s)->email[k+1];
	}
	char *cs="CS";
	char *eee="EEE";
	char *ece="ECE";
	
	if(isSame(cs, (*s)->branch)){
		(*s)->id[4]='A';
		(*s)->id[5]='7';
		//printf("%s", (*s)->id);
	} else if(isSame(eee, (*s)->branch)){
		(*s)->id[4]='A';
		(*s)->id[5]='3';
		//printf("%s", (*s)->id);
	} else 	if(isSame(ece, (*s)->branch)){
		(*s)->id[4]='A';
		(*s)->id[5]='A';
		//printf("%s", (*s)->id);
	} else{
		printf("END");	
	}
	
	(*s)->id[6]='P';
	(*s)->id[7]='S';
	for(int k=8;k<12;k++){
		(*s)->id[k] = (*s)->email[k-3];
	}
	(*s)->id[12] = 'H';
}

int main(void){
	char input[1000];
	char input1[1000];
	fgets(input, sizeof input, stdin);
	fgets(input1, sizeof input, stdin);
	Student *s = malloc(sizeof(Student));
	for(int k=0;k<strlen(input);k++){
		if(input[k]!='\n' && input[k]!='\0') s->email[k] = input[k];
	}
	for(int k=0;k<strlen(input1);k++){
		if(input1[k]!='\n' && input1[k]!='\0') s->branch[k] = input1[k];
	}
	generateId(&s);
	
	printf("%s\n", s->id);
	
	return 0;
}
