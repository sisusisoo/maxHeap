#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

int movCount = 0;
typedef struct Element {
	int key;

}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;

}HeapType;

void printHeap(HeapType* h) {
	for (int i = 1; i < h->heap_size + 1; i++) {
		printf("%d ", h->heap[i].key);
	}
	printf("\n");
}

HeapType* create() {
	HeapType* h = (HeapType*)malloc(sizeof(HeapType));
	return h;

}
void init(HeapType* h) {
	h->heap_size = 0;
}
int is_empty(HeapType* h) {
	return (h->heap_size == 0);
}

int is_full(HeapType* h) {
	return(h->heap_size == (MAX_ELEMENT - 1));

}

void insert_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);
	h->heap[i] = item;
	printHeap(h);
	while(i>1 && item.key>h->heap[i/2].key) {
	

		h->heap[i] = h->heap[i / 2];
		h->heap[i/2] = item;
		i = i / 2;
	
		movCount++;
		printHeap(h);
	}

	h->heap[i] = item;

}


//삭제함수 
element delete_heap(HeapType* h) {
	int  parent, child;
	element item, temp;
	item = h->heap[1];//삭제할 가장 큰값 나중에 리턴 하려고 
	temp = h->heap[(h->heap_size)--];//올려줄 말단 값  
	parent = 1;
	child = 2;
	printHeap(h);
	while (child <= h->heap_size) {
		if (child <= h->heap_size &&
			(h->heap[child].key) < h->heap[child + 1].key)//두 자식 중에 큰값을 고르고 그걸 올리려고 
			child++;
		if (temp.key >= (h->heap[child].key)) break;
		h->heap[parent] = h->heap[child];//이러면 자동으로 1번째 값이 삭제되고 다른 값으로 대체됨
		parent = child;//기준이 바뀜 바로 밑에 줄기로 
		child *= 2;//해당 트리에 아래줄기로 이동
		movCount++;
	}
	h->heap[parent] = temp;
	return item;
}

//
element delete_heap_sel(HeapType* h,element item1) {
int  parent, child;
element item, temp;
item = item1;//삭제할 가장 큰값 나중에 리턴 하려고 
temp = h->heap[(h->heap_size)--];//올려줄 말단 값  
parent = 1;
child = 2;

while (child <= h->heap_size) {
	if (child <= h->heap_size &&
		(h->heap[child].key) < h->heap[child + 1].key)//두 자식 중에 큰값을 고르고 그걸 올리려고 
		child++;
	if (temp.key >= (h->heap[child].key)) break;
	h->heap[parent] = h->heap[child];//이러면 자동으로 1번째 값이 삭제되고 다른 값으로 대체됨
	parent = child;//기준이 바뀜 바로 밑에 줄기로 
	child *= 2;//해당 트리에 아래줄기로 이동
	movCount++;
	printHeap(h);
}
h->heap[parent] = temp;
printHeap(h);
return item;
}

int start(char sel,HeapType* h) {
	int input;
	element inputE;

	switch (sel) {
	case 'i':
		movCount = 0;
		printf("추가할 값 입력: ");
		scanf_s("%d", &input);
	
		inputE.key = input;
		insert_heap(h,inputE);

	
		printf("노드 이동 횟수: %d",movCount);
		break;
	case 'd':
		movCount = 0;
		printf("삭제할 값 입력: ");
		scanf_s("%d", &input);
		
		inputE.key = input;
		delete_heap_sel(h,inputE);
		for (int i = 1; i < h->heap_size + 1; i++) {
			printf("%d ", h->heap[i].key);
		}

		printf("노드 이동 횟수: %d", movCount);

		break;
	case 'p':
		break;
	case 'c':
		break;
	
	}
}

void main() {
	char sel="a";
	HeapType* mh;
	mh = create();
	init(mh);
	//struct heapType s1 = { {0,90,89,70,36,75,63,65,21,18,15},11 };
	//mh->heap = {0,90,89,70,36,75,63,65,21,18,15};

	int heap[] = {0,90,89,70,36,75,63,65,21,18,15 };
	element temp;
	printf("1\n");
	for (int i = 0; i <11 ; i++) {
		printf("%d ", heap[i]);
		temp.key = heap[i];
		insert_heap(mh, temp);
	
	}
	printf("\n");
	printf("2\n");


	while (1) {
		printf("메뉴입력: ");
		scanf_s("%c", &sel);
		start(sel, mh);

		printf("\n");
	}
}