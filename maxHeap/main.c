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


//�����Լ� 
element delete_heap(HeapType* h) {
	int  parent, child;
	element item, temp;
	item = h->heap[1];//������ ���� ū�� ���߿� ���� �Ϸ��� 
	temp = h->heap[(h->heap_size)--];//�÷��� ���� ��  
	parent = 1;
	child = 2;
	printHeap(h);
	while (child <= h->heap_size) {
		if (child <= h->heap_size &&
			(h->heap[child].key) < h->heap[child + 1].key)//�� �ڽ� �߿� ū���� ���� �װ� �ø����� 
			child++;
		if (temp.key >= (h->heap[child].key)) break;
		h->heap[parent] = h->heap[child];//�̷��� �ڵ����� 1��° ���� �����ǰ� �ٸ� ������ ��ü��
		parent = child;//������ �ٲ� �ٷ� �ؿ� �ٱ�� 
		child *= 2;//�ش� Ʈ���� �Ʒ��ٱ�� �̵�
		movCount++;
	}
	h->heap[parent] = temp;
	return item;
}

//
element delete_heap_sel(HeapType* h,element item1) {
int  parent, child;
element item, temp;
item = item1;//������ ���� ū�� ���߿� ���� �Ϸ��� 
temp = h->heap[(h->heap_size)--];//�÷��� ���� ��  
parent = 1;
child = 2;

while (child <= h->heap_size) {
	if (child <= h->heap_size &&
		(h->heap[child].key) < h->heap[child + 1].key)//�� �ڽ� �߿� ū���� ���� �װ� �ø����� 
		child++;
	if (temp.key >= (h->heap[child].key)) break;
	h->heap[parent] = h->heap[child];//�̷��� �ڵ����� 1��° ���� �����ǰ� �ٸ� ������ ��ü��
	parent = child;//������ �ٲ� �ٷ� �ؿ� �ٱ�� 
	child *= 2;//�ش� Ʈ���� �Ʒ��ٱ�� �̵�
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
		printf("�߰��� �� �Է�: ");
		scanf_s("%d", &input);
	
		inputE.key = input;
		insert_heap(h,inputE);

	
		printf("��� �̵� Ƚ��: %d",movCount);
		break;
	case 'd':
		movCount = 0;
		printf("������ �� �Է�: ");
		scanf_s("%d", &input);
		
		inputE.key = input;
		delete_heap_sel(h,inputE);
		for (int i = 1; i < h->heap_size + 1; i++) {
			printf("%d ", h->heap[i].key);
		}

		printf("��� �̵� Ƚ��: %d", movCount);

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
		printf("�޴��Է�: ");
		scanf_s("%c", &sel);
		start(sel, mh);

		printf("\n");
	}
}