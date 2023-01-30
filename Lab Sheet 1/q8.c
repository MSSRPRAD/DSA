#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

char input[1000];
char copy1[1000];
char copy2[1000];
bool condition=false;

void copy(char *str1, char *str2){
    for(int k=0;k<1000;k++){
        if(str2[k]!='\n')str1[k]=str2[k];
    }
    return;
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

void reverseString(char* string){


    for(int i=0;i<strlen(string)/2;i++){
        //Reverse string[i] and string[len-i-1]
        int temp=string[i];
        string[i]=string[strlen(string)-i-1];
        string[strlen(string)-i-1]=temp;
    }
    
    return;

}

int main(void){
    fgets(input, sizeof input, stdin);
    copy(copy1, input);
    copy(input, copy1);
    copy(copy2, input);


    char *token2 = strtok(copy2, " ");
    while(token2){
        char temp[1000];
        copy(temp, token2);
        reverseString(temp);
        printf("%s ", temp);

        token2 = strtok(NULL, " ");
    }
    printf("\n");
    
    char* token = strtok(input, " ");
    char* token1 = strtok(copy1, " ");

    while (token) {
        char temp[1000];
        copy(temp, token);
        reverseString(temp);
        if(checkSame(temp, token) && strlen(temp)!=1){
            printf("%s ", token, temp);
        }
        token = strtok(NULL, " ");
    }
    
    

    return 0;
}