#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

//Given a string S, find the longest palindromic substring in S.
//You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

bool is_palindromic(char *s, int len){
	if (len == 0){
		return true;
	}
	int i = 0, j = len-1;
	while(i<=j){
		if (*(s+i) != *(s+j)){
			return false;
		}
		i++;
		j--;
	}
	return true;
}

// brute
char * palindromic(char s[]){
	int len = strlen(s);

	int begin, end, max = 0;
	int i,j;
	for (i =0; i < len; i++){
		for(j = i; j < len; j++){
			if(is_palindromic(s+i, j-i+1)){
				if (max < (j-i+1)){
					max = j-i+1;
					begin = i;
					end = j;
				}
			}
		}
	}

	if (max <= 0){
		return NULL;
	}

	char *d = (char *)malloc(sizeof(max+1));
	char *t = d;
	while(begin<=end){
		*t++ = *(s+begin++);
	}
	*t = '\0';
	return d;
}

char * substring(char *s, int begin, int len){
	char *d = (char *)malloc(sizeof(len+1));

	int i = 0;
	char *t = d;
	for( i = 0; i<len;i++){
		*t++ = *(s+begin+i);
	}
	t = '\0';
	return d;
}

// 使用动态规划实现
char * palindromic_1(char s[]){
	int len = strlen(s);

	bool table[1000][1000];
	int i;
	for(i=0; i< len;i++){
		table[i][i] = true;
	}
	int longestBegin = 0;
	int maxLen = 0;
	for (i=0; i <len-1;i++){
		if(s[i]==s[i+1]){
			table[i][i+1] = true;
			longestBegin = i;
			maxLen = 2;
		}
	}

	for(i =3; i <= len; i++ ){
		int k;
		for(k = 0; k< len-i+1; k++){
			// other element
			int j = k+i -1;
			if(s[k]==s[j]&&table[k+1][j-1]){
				table[k][j] = true;
				longestBegin = k;
				maxLen = i;
			}
		}
	}



	return substring(s, longestBegin, maxLen);
}

// 以a,b索引的字符为中心向外扩展查找回字符串
char * expandAroundCenter(char *s, int a, int b){
    int len = strlen(s);
    for(; a >= 0 && b < len; a--,b++){
        if (*(s+a) !=*(s+b)){
            break;
        }
    }
    return substring(s, a+1, (b-1-(a+1)+1));
}

//
char * palindromic_2(char *s){
	int len = strlen(s);
	if (len == 0){
		return NULL;
	}
    int i;
    char *longest = substring(s, 0, 1);
    char *t = NULL;
    for(i = 0; i< len -1; i++){
        // 根据单个元素为中心的回文字符串扩展
        t = expandAroundCenter(s, i, i);
        if (strlen(t) > strlen(longest)){
            longest = t;
        }else{
            free(t);
        }

        // 以两个字符串为中心的回文扩展
        t = expandAroundCenter(s, i, i+1);
        if (strlen(t) > strlen(longest)){
            free(longest);
            longest = t;
        }else{
            free(t);
        }
    }

    return longest;
}

char *preProcess(char *s){
    return s;
}

int min(int a, int b){
    if (a < b){
        return a;
    }
    return b;
}

//TODO 了解原理
char * palindromic_3(char *s){
    char *t = preProcess(s);
    int n = strlen(t);
    int *p = (int *)malloc(n*sizeof(int));
    int C = 0, R = 0;

    for(int i = 1; i < n-1; i++){
        int i_mirror = 2*C - i;

        p[i] = (R > i)? min(R-i, p[i_mirror]):0;
        while (t[i+1+p[i]] == t[i-1-p[i]])
            p[i]++;

        if (i+p[i]> R){
            C = i;
            R = i+p[i];
        }
    }

    int maxLen = 0;
    int centerIndex = 0;
    for(int i = 1; i< n-1;i++){
        if(p[i] > maxLen){
            maxLen = p[i];
            centerIndex = i;
        }
    }

    return substring(s, (centerIndex-1-maxLen)/2, maxLen);
}

int main(){

	char s[] = "abaabaxxxx";
	printf("%s\n", palindromic(s));
	printf("%s\n", palindromic_1(s));
	printf("%s\n", palindromic_2(s));
	printf("%s\n", palindromic_3(s));

	printf("www\n");

	int a[10][10];
	a[0][9] = 1;
	printf("%d\n", a[0][9]);
	return 0;
}
