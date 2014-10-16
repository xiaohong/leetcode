#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>


// 
bool isRepeat(char *s, int len, char n){
	if (len == 0){
		return false;
	}
	int i;
	for (i = 0; i < len; i++){
		if (*(s+i) == n){
			return true;
		}
	}
	return false;
}

char * substring(char s[]){
	int max = 0;
	int cur = 0;
	int begin;
	int end;

	int len = strlen(s);
	char *d = (char *)malloc((len+1)*sizeof(char));

	int i ;
	for (i =0; i < len; i++){

		int j = i;
		for (; j < len; j++){
			if (isRepeat(s+i, j-i, *(s+j)) == false){
				if (max < (j-i+1)){

					max = j-i+1;
					begin = i;
					end = j;
				}
			}else{
				break;
			}
		}
	}

	char * t = d;
	while(begin <= end){
		*t = *(s+begin);
		t++;
		begin++;
	}
	*t = '\0';
	return d ;
}

int main(){
	char s[] = "abcabcdbb";

	printf("%s\n", substring(s));

	return 1;
}