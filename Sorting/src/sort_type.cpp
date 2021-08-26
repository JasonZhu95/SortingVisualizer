#include "sort_type.h"

void bubbleSort()
{
	for (int i = 0; i < numElements; i++) {
		for (int j = 0; j < numElements - i - 1; j++) {
			draw(j, j + 1);
			if (arrayElements[j] > arrayElements[j + 1])
				swap(&arrayElements[j], &arrayElements[j + 1]);
			Sleep(sTime);
			draw(j, j + 1);
		}
		isSorted[numElements - i - 1] = true;
		draw(-1, -1);
	}
}
void selectionSort()
{

}

void insertionSort()
{

}

void quickSort()
{

}

void mergeSort()
{

}

void countingSort()
{

}

void radixSort()
{

}

void bucketSort()
{

}

void swap(float* a, float* b) {
	float t = *a;
	*a = *b;
	*b = t;
}