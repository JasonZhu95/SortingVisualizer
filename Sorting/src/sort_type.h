#pragma once
#include <string>
#include <windows.h>
#include <vector>
#include <chrono>
//Global Variables
extern const unsigned int SCREEN_WIDTH;
extern const unsigned int SCREEN_HEIGHT;
extern std::vector<float> arrayElements;
extern std::vector<bool> isSorted;
// DELETE: Temp Values
extern int numElements;
extern int sTime;
extern void draw(int x, int y);
extern void generate();

void bubbleSort();
void selectionSort();
void insertionSort();
void quickSort();
void mergeSort();
void countingSort();
void radixSort();
void bucketSort();
void swap(float* a, float* b);