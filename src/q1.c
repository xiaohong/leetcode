#include <stdio.h>
#include <malloc.h>

int * sum(int numbers[], int len, int target){
	int i, j;

	int * ret = (int *)malloc(2*sizeof(int));
	if (ret == NULL){
		printf("%s\n", "error");
		return NULL;
	}

	for (i = 0; i< len-1; i++ ){
		for (j = i+1; j < len; j++){
			if (numbers[i]+numbers[j] == target){
				*ret = i+1;
				*(ret+1) = j+1;
				// only on answer
				return ret;
			}
		}
	}

	for (i = 0; i < len -1; i++){
		int left = target - numbers[i];
		for (j = i+1; j < len; j++){
			if (left == numbers[j]){
					*ret = i+1;
				*(ret+1) = j+1;
				// only on answer
				return ret;
			}
		}
	}

	return NULL;
}

// if two is n, how to ??

int * sumN(int numbers[], int len, int n, int target){
	// no more element
	if (len < n){
		return NULL;
	}
	if (target < 0){
		return NULL;
	}
	// len must less than 0, not equal 0
	if (len < 0){
		return NULL;
	}
	if (n <=0 ){
		return NULL;
	}


	int * r = (int *)malloc(n*sizeof(int));

	// one element youhua
	if (n == 1){
		int i ;
		for (i =0; i<= len; i++){
			if (*(numbers+i)== target){
				*r = i;
				return r;
			}
		}
	}

	int *other = sumN(numbers+1, len-1, n-1, target- *numbers);
	if (other != NULL){
		int k = 1;
		for (; k<=n-1; k++){
			*(r+k) = *(other+k-1)+1;
		}
		free(other);
		*r = 0;
		return r;
	}

	r = sumN(numbers+1, len-1, n, target);

	if ( r == NULL){
		return NULL;
	}

	// index inr
	int k = 0;
	int * t = r;
	while(k++<n){
		(*(t++))++;
	}

	return r;
}

// how to iterator implement


int main(){

		printf("ww\n");
	
	int n[] = {2,7,11,15,8,8,6};
	int target = 22;



	int * r = sumN(n, 4, 2, target);

	if (r == NULL){
		printf("empty" );
		return 0;
	}

	printf("%d, %d, (%d + %d ) = %d \n", *r, *(r+1), n[*r], n[*(r+1)], target);

	free(r);

	r = sum(n,4, target);

		printf("%d, %d, (%d + %d ) = %d \n", *r, *(r+1), n[*r-1], n[*(r+1)-1], target);

	return 0;
}