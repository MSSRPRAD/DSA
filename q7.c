#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int freqArr[26];
int freqArrWindow[26];
int start, end;

bool checkSame(int *matrix1, int *matrix2){
    for(int x=0;x<26;x++){
        if(matrix1[x]<matrix2[x]) return false;
    }
    return true;
}


//97 to 122
void findLetters(char *matrix){
    int len = strlen(matrix);
    for(int k=0;k<len;k++){
        if(matrix[k]>='a' && matrix[k]<='z'){
            freqArr[matrix[k]-97]++;
        }
    }
}

//97 to 122
void findLettersTemp(char *matrix){
    int len = strlen(matrix);
    for(int k=0;k<len;k++){
        if(matrix[k]>='a' && matrix[k]<='z'){
            freqArrWindow[matrix[k]-97]++;
        }
    }
}

void clearFreqArray(int *matrix){
    for(int x=0;x<26;x++){
        matrix[x]=0;
    }
}

void printFreqArray(int *matrix, int max){
    for(int k=0;k<max; k++){
        printf("%d ", matrix[k]);
    }
    printf("\n");
}

bool check(int *m1, int *m2){
    for(int k=0;k<26;k++){
        if((m1[k]>0 && m2[k]==0)|| (m2[k]>0 && m1[k]==0)){
            return false;
        }
        return true;
    }
}

bool condition=false;
bool cond2=false;
void findWindow(char *matrix){
    int window=1000;
    int len = strlen(matrix);
    for(int x=0;x<len-1;x++){
        for(int y=x+1;y<len+1;y++){
            char temp[1000];
            for(int g=0;g<1000;g++){
                temp[g]='\0';
            }
            for(int g=x;g<y;g++){
                clearFreqArray(freqArrWindow);
                temp[g-x]=matrix[g];
                //printf("\n%d\t%s",g, temp);
                findLettersTemp(temp);
                condition =checkSame(freqArrWindow, freqArr);
                if(condition && window>(y-x))   {
                    window=y-x;
                    start = x;end=y; cond2=true;
                }
                //printf("\n%d\n", condition);
                //printFreqArray(freqArr, 26);
                //printf("\n");
                //printFreqArray(freqArrWindow, 26);
                //printf("\n");
            }
            
        }
    }
}

int main(void){

    for(int k=0;k<26;k++){
        freqArr[k]=0;
    }

    char input[1000];
    fgets(input, sizeof input, stdin);

    char input2[1000];
    fgets(input2, sizeof input2, stdin);

    //printf("%s\n%s", input, input2); 

    //printFreqArray(freqArr, 26);

    //printf("\n");

    findLetters(input2);

    //printFreqArray(freqArr, 26);
    //printFreqArray(freqArrWindow, 26);

    findWindow(input);

    if(cond2) {
        printf("\n%d %d\n", start, end-1);
        for(int c=start;c<end;c++){
            printf("%c", input[c]);
        }
    } else{
        printf("\nNOT POSSIBLE\n");
    }

    return 0;
}