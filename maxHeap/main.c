#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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


//�����Լ� --------------------�ϴ� �Ⱦ� 
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

//�Է°� �����Լ� 
element delete_heap_sel(HeapType* h,element item1) {
int  parent, child;
element item, temp,change;
item = item1;//������ ���� ū�� ���߿� ���� �Ϸ��� 


temp = h->heap[(h->heap_size)--];//�÷��� ���� ��  

int d=0;

//�ϴ� �ش� ���� �迭 �ε��� ã��
for (int i = 1; i < h->heap_size + 1; i++) {
	if (h->heap[i].key == item1.key) {
		d = i;
		break;
	}
}
printf("������ �� �ε���:%d\n",d);


//�ش� �迭�� ��������(�迭����) �ֱ� 

//h->heap[d] = temp;// �̰� parent ���� �Ǹ� ���⼭���� ������  ���߿�***
parent = d;
child = d*2;
movCount++;//������ ����� �� ������ ���� �� ���� ��� �̵� ���� 

h->heap[parent] = temp;
//levelPrint���� ���� ���ڰ� �Ǿ�� �ȳ����� �߾ �迭�� ���� heapSize�����δ� �����ϴ�
h->heap[(h->heap_size)+1].key = -1;

while (child <= h->heap_size) {
	printHeap(h);
	if (child <= h->heap_size &&
		(h->heap[child].key) < h->heap[child + 1].key)//�� �ڽ� �߿� ū���� ���� �װ� �ø����� 
		child++;
	if (temp.key >= (h->heap[child].key)) break;
	change = h->heap[parent];
	h->heap[parent] = h->heap[child];//�̷��� �ڵ����� parent���� ��ü  
	h->heap[child] = change;
	parent = child;//������ �ٲ� �ٷ� �ؿ� �ٱ�� 
	child *= 2;//�ش� Ʈ���� �Ʒ��ٱ�� �̵�
	movCount++;
	

}

h->heap[parent] = temp; //÷���� �ְ� �����ؼ� �ʿ���� 
printHeap(h);
return item;
}

void levelPrint(HeapType *h) {
	int parent = 1;


	//���� ���� 
	int level = (int)log2(h->heap_size)+1;
	printf("level: %d\n", level);

	for (int i = 1; i <= level; i++) {
		printf("[%d]", i);//���� ���
		//printf("%d\n", parent);
		for (int j = parent; j < parent * 2;j++) {
			if (h->heap[j].key>0) {// ���� �ȹ��͵� �ȵ����� ���� ���̶� �迭�� ���� �� ���� ���� ���̶�� ���� 
				printf("%d ",h->heap[j]);

			}
		}
		printf("\n");
		parent *= 2;
	}
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

		printf("\n��� �̵� Ƚ��: %d", movCount);

		break;
	case 'p':
		levelPrint(h);
		break;
	case 'c':
		break;
	
	}
}

void main() {
	char sel="a";
	HeapType* mh ;
	mh = create();
	init(mh);
	//struct heapType s1 = { {0,90,89,70,36,75,63,65,21,18,15},11 };
	//mh->heap = {0,90,89,70,36,75,63,65,21,18,15};

	int heap[] = {0,90,89,70,36,75,63,65,21,18,15 };

	element temp;



	//mh->heap[1].key = heap[1];

	//���� �ϳ��� h->heap[]�� �ִ´� 
	//mh->heap_size++;
	for (int i = 1; i <11 ; i++) {
	
		mh->heap[i].key = heap[i];
		mh->heap_size++;
	//	printf("%d : %d\n", mh->heap[i].key, heap[i]);
		
	}

	printHeap(mh);


	while (1) {
		printf("�޴��Է�: ");
		scanf_s("%c", &sel);
		start(sel, mh);

		printf("\n");
	}
}