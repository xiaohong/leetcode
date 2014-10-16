#include <stdio.h>
#include <malloc.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
} ListNode;

ListNode * newList(int n[], int len){
	ListNode * head = NULL;
	int i ;
	for (i = 0 ; i< len; i++){
		ListNode * t  = (ListNode *)malloc(sizeof(ListNode));
		if (t == NULL){
			return NULL;
		}
		t->val = n[len-i-1];
		t-> next = head;
		head = t;
	}
	return head;
}

ListNode * reverse(ListNode * head){
	ListNode *t = NULL;

	while(head != NULL){
		ListNode *n = head->next;
		head->next = t;
		t = head;
		head = n;
	}

	return t;
}

ListNode * add(ListNode *a, ListNode *b){

	ListNode *t = NULL;
	a = reverse(a);
	b = reverse(b);
	bool isOver = false;
	while (a != NULL || b != NULL){
		int s = 0;
		if ( a!= NULL){
			s = s+ a->val;
			a = a->next;
		}
		if (b != NULL){
			s = s + b->val;
			b = b->next;
		}
		if (isOver){
			s = s+1;
			isOver = false;
		}
		if (s >= 10){
			isOver = true;
		}
		ListNode * n = (ListNode *)malloc(sizeof(ListNode));
		n -> val = s %10;
		n ->next = t;
		t = n;
	}

	return t;
}

void printList(ListNode *head){
	while (head != NULL){
		printf("%d, ", head->val);
		head = head->next;
	}
	printf("\n");
}

int main(){
	int a[] = {1,2,3,4,5};
	int b[] = {1,2,2,2,2,2,2,1,5};

	ListNode *n = newList(a, 5);


	printList(n);
	printList(newList(b,9));
	n = add(newList(a,5), newList(b,9));
	printList(n);

	printf("ww\n");
	return 0;
}
