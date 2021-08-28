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
extern int numElements;
extern int sTime;
extern int comparisons;
extern void draw(int x, int y);
extern void generate();

void bubbleSort();
void selectionSort();
void insertionSort();
void quickSort(int l, int r);
void mergeSort(int l, int r);

int partition(int l, int r);
void swap(float* a, float* b);
void merge(int l, int m, int r);