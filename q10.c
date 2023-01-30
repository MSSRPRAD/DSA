#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


bool isAnagram=false;

char input[1000];
char anagram[1000];
int ind[1000];

void printIndex(){
    for(int k=0;k<strlen(anagram)-1;k++){
        printf("%d\t", ind[k]+1);
    }
}

void swapIndex(int g, int h){
    if(isAnagram){
        return;
    }
    int temp = ind[g];
    ind[g]=ind[h];
    ind[h]=temp;    
}

bool checkSame(char *a1, char *a2){
    bool condition = true;
    for(int k=0;k<strlen(a1);k++){
        if(a1[k]!=a2[k]){
            condition = false;
        }
    }
    return condition;
}

void swap(char *x, char *y){
    char temp = *x;
    *x=*y;
    *y=temp;
}

static int p=0;

void permute(char* a, int l, int r)
{
    int i;
    if (l == r && !isAnagram){
        p++;
        //printf("\nCurrent Permutation (%d):\t%s\n",p, a);
        //printf("Is Equal:\t%d\n", checkSame(a, anagram));
        if(checkSame(a,anagram)) isAnagram=true;
        //printIndex();
    }
    else {
        for (i = l; i <= r; i++) {
            swap((a + l), (a + i));
            swapIndex(l,i);
            permute(a, l + 1, r);
            swap((a + l), (a + i)); // backtrack
            swapIndex(l,i);
        }
    }
}

int main(void){

    fgets(input, sizeof input, stdin);
    fgets(anagram, sizeof anagram, stdin);

    for(int k=0;k<1000;k++){
        ind[k]=k;
    }

    // printf("\n%s\n%s\n", input, anagram);
    
    // printf("\n\n%d\n%d\n\n", sizeof(input), sizeof(anagram));
    // printf("\n\n%d\n%d\n\n", strlen(input), strlen(anagram));

    permute(input, 0, strlen(input)-1);

    if(isAnagram){
        printf("POSSIBLE\n");
        printIndex();
    } else{
        printf("NOT POSSIBLE");
    }


    return 0;
}