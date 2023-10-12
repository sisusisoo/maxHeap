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


//삭제함수 --------------------일단 안씀 
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

//입력값 삭제함수 
element delete_heap_sel(HeapType* h,element item1) {
int  parent, child;
element item, temp,change;
item = item1;//삭제할 가장 큰값 나중에 리턴 하려고 


temp = h->heap[(h->heap_size)--];//올려줄 말단 값  

int d=0;

//일단 해당 값의 배열 인덱스 찾기
for (int i = 1; i < h->heap_size + 1; i++) {
	if (h->heap[i].key == item1.key) {
		d = i;
		break;
	}
}
printf("삭제할 값 인덱스:%d\n",d);


//해당 배열에 마지막값(배열끝값) 넣기 

//h->heap[d] = temp;// 이게 parent 값이 되면 여기서부터 내려감  젤중요***
parent = d;
child = d*2;
movCount++;//삭제된 값대신 맨 끝값이 들어가는 거 부터 노드 이동 시작 

h->heap[parent] = temp;
//levelPrint에서 음의 숫자가 되어야 안나오게 했어서 배열의 끝은 heapSize만으로는 부족하다
h->heap[(h->heap_size)+1].key = -1;

while (child <= h->heap_size) {
	printHeap(h);
	if (child <= h->heap_size &&
		(h->heap[child].key) < h->heap[child + 1].key)//두 자식 중에 큰값을 고르고 그걸 올리려고 
		child++;
	if (temp.key >= (h->heap[child].key)) break;
	change = h->heap[parent];
	h->heap[parent] = h->heap[child];//이러면 자동으로 parent값과 교체  
	h->heap[child] = change;
	parent = child;//기준이 바뀜 바로 밑에 줄기로 
	child *= 2;//해당 트리에 아래줄기로 이동
	movCount++;
	

}

h->heap[parent] = temp; //첨부터 넣고 시작해서 필요없음 
printHeap(h);
return item;
}

void levelPrint(HeapType *h) {
	int parent = 1;


	//레벨 갯수 
	int level = (int)log2(h->heap_size)+1;
	printf("level: %d\n", level);

	for (int i = 1; i <= level; i++) {
		printf("[%d]", i);//레벨 출력
		//printf("%d\n", parent);
		for (int j = parent; j < parent * 2;j++) {
			if (h->heap[j].key>0) {// 아직 안무것도 안들어간값은 음의 값이라서 배열에 뭔가 들어간 값은 양의 값이라고 세팅 
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

		printf("\n노드 이동 횟수: %d", movCount);

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

	//값을 하나씩 h->heap[]에 넣는다 
	//mh->heap_size++;
	for (int i = 1; i <11 ; i++) {
	
		mh->heap[i].key = heap[i];
		mh->heap_size++;
	//	printf("%d : %d\n", mh->heap[i].key, heap[i]);
		
	}

	printHeap(mh);


	while (1) {
		printf("메뉴입력: ");
		scanf_s("%c", &sel);
		start(sel, mh);

		printf("\n");
	}
}