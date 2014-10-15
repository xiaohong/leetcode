#include <stdio.h>

// 查找两个有序数组的中间元素
// 查找两个有序数组的第k个元素
// 查找多个有序数组的第k个元素

int min(int a, int b){
	if (a < b){
		return a;
	}

	return b;
}

int max(int a, int b){
	if (a > b){
		return a;
	}

	return b;
}

double median(int a[], int n, int b[], int m){
	if (n > m){
		return median(b,m, a,n);
	}

	int k = (n+m-1)/2;
	int l = 0;
	int r = min(k, n);
	// 二分查找算法
	// 在size的小数组中进行二分查找，并把中间元素和另外一个数组中的第**k-中间元素位置的**
	// 进行比较，如果小于的话，把左位置设置为中间元素的下一个位置，然后再进行二分查找直到定位到最后一个
	// 元素，然后a数组中有一个元素，然后和b中的k-index(a)
	while(l < r){
		int midA = (l+r)/2;
		int midB = k - midA;

		if (midB > k || a[midA] < b[midB]){
			l = midA+1;
		}else{
			r = midA;
		}
		printf("%d %d %d %d %d\n", k, l, r, midA, midB);
	}

	int A = max(l >0?a[l-1]:-1, k-l>=0?b[k-l]:-1);
	if (((n+m)&1) == 1){
		return (double)A;
	}
	int MAX = 1000;
	int B = min(l<n?a[l]:MAX,  k-l+1<m? b[k-l+1]:MAX);

	return (A+B)/2.0;

}

int main(){

	int a[] = {1,2};
	int b[] = {4,5,6,7,10,111,123};

	printf("%f\n", median(a,2,b,7));

	return 1;

}
