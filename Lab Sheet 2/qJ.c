#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

struct Country_t {
	char name[20];
	int gold;
	int bronze;
	int silver;
};
typedef struct Country_t Country;

bool isGreater(Country *c1, Country *c2){
	if(c1->gold>c2->gold){
		return true;
	} else if(c1->gold<c2->gold){
		return false;
	} else{
		if(c1->silver>c2->silver){
			return true;
		} else if(c1->silver<c2->silver){
			return false;
		} else{
			if(c1->bronze>c2->bronze){
				return true;
			} else if(c1->bronze<c2->bronze){
				return false;
			}
		}
	}
}

int main(void){
	int n;
	scanf("%d", &n);
	Country *(*list[n]);
	Country s[n];
	Country s1[n];
	for(int i=0;i<n;i++){
		scanf("%s", s[i].name);
		scanf("%d %d %d", &s[i].gold, &s[i].silver, &s[i].bronze);
	}
	
	
	int arr[n];
	for(int i=0;i<n;i++){
		arr[i]=i;
	}
	
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(isGreater(&s[arr[j]],&s[arr[j+1]])){
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1]=tmp;
			}
		}
	}
	//Change the order of s[n]
	for(int i=0;i<n;i++){
		strcpy(s1[i].name,s[arr[i]].name);
		s1[i].gold = s[arr[i]].gold;
		s1[i].silver = s[arr[i]].silver;
		s1[i].bronze = s[arr[i]].bronze;
		
	}
	for(int i=0;i<n;i++){
		strcpy(s[i].name,s1[i].name);
		s[i].gold=s1[i].gold;
		s[i].silver=s1[i].silver;
		s[i].bronze=s1[i].bronze;
		
	}
	
	for(int i=n-1;i>-1;i--){
		printf("%s\n", s[i].name);
	}
	
	printf("\n%d", isGreater(&s[1],&s[0]));
	
return 0;}
