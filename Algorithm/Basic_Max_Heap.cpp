#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct element {
	int key;
}element;

typedef struct HeapType {
	element heap[200];
	int size;
}HeapType;

void init(HeapType* h) {
	h->size = 0;
}

void insert(HeapType* h, element item) {

	int i = ++(h->size);

	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i = i / 2;
	}
	h->heap[i] = item;

}

element delete_Heap (HeapType* h) {

	element result = h->heap[1];
	element temp = h->heap[(h->size)--];
	int parent = 1;
	int child = 2;

	while (child <= h->size) {
		if ((h->heap[child].key < h->heap[child + 1].key) && child < h->size) {
			child++;
		}
		if (temp.key >= h->heap[child].key) {
			break;
		}
		h->heap[parent] = h->heap[child];
		parent = child;
		child = child * 2;
	}
	h->heap[parent] = temp;

	return result;
}


int main(void) {

	element e1 = { 5 };
	element e2 = { 10 };
	element e3 = { 30 };

	element result[3];

	HeapType h;
	init(&h);
	insert(&h, e1);
	insert(&h, e2);
	insert(&h, e3);

	for (int i = 0; i < 3; i++) {
		result[i] = delete_Heap(&h);
	}

	for (int i = 0; i < 3; i++) {
		printf("%d ", result[i].key);
	}


	return 0;
}