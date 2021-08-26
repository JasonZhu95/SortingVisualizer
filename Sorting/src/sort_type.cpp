#include "sort_type.h"


void swap(float* a, float* b) {
	float t = *a;
	*a = *b;
	*b = t;
}

void bubbleSort()
{
	bool swapped;
	for (int i = 0; i < numElements; i++)
	{
		swapped = false;
		for (int j = 0; j < numElements - i - 1; j++)
		{
			draw(j, j + 1);
			if (arrayElements[j] > arrayElements[j + 1])
			{
				swap(&arrayElements[j], &arrayElements[j + 1]);
				bool = true;
				Sleep(sTime);
				draw(j, j + 1);
			}
		}
		isSorted[numElements - i - 1] = true;
		draw(-1, -1);
		if (swapped = false)
		{
			break;
		}
	}
}

void selectionSort()
{
	int i, j, min_index;
	for (i = 0; i < numElements; i++)
	{
		min_index = i;
		for (j = 0; j < numElements; j++)
		{
			if (arrayElements[j] < arrayElements[min_index])
			{
				min_index = j;

			}
		}
		swap(&arrayElements[min_index], &arrayElements[i]);
	}
}

void insertionSort()
{
	int i, j, key;
	for (int i = 1; i < numElements; i++)
	{
		key = arrayElements[i];
		j = i - 1;
		while (j >= 0 && arrayElements[i] > key)
		{
			arrayElements[j + 1] = arrayElements[j];
			j = j - 1;
		}
		arrayElements[j + 1] = key;
	}
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