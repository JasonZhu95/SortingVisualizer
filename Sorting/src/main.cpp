#include <windows.h>
#include <GL/glut.h>
#include <string>
#include <vector>
#include <chrono>
#include "sort_type.h"

//Global Variables
const unsigned int SCREEN_WIDTH = 1024;
const unsigned int SCREEN_HEIGHT = 768;
std::vector<float> arrayElements;
std::vector<bool> isSorted;
int numElements = 10;
int sTime = 50;

// Function Prototypes
// ----------------------------------------------------------------------------

// Render window
void display();
void init();

// Render to screen
void draw(int x, int y);
void generate();

// Text On Screen
void displayText(std::string textToDraw, int x, int y);
void displayInfo();

void menuFunc(int id);
void createMenu();

// Clear Window
void clear();

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Sorting Algorithm Visualizer");
	init();
	glutDisplayFunc(display);
	createMenu();
	glutMainLoop();

	return 0;
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	generate();
}

void displayText(std::string textToDraw, int x, int y)
{
	glRasterPos2f(x, y);
	for (int i = 0; i < textToDraw.size(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, textToDraw[i]);
}

void displayInfo()
{
	glColor3f(1.0f, 1.0f, 1.0f);
	std::string s = "Elements = " + std::to_string(numElements);
	displayText(s, 5, 0.95 * SCREEN_HEIGHT);
	s = "Time = " + std::to_string(sTime) + " milliseconds/operation";
	displayText(s, 5, 0.9 * SCREEN_HEIGHT);
}

void displayTotalTime(int diff, std::string algorithm)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	std::string s = "Time taken for " + algorithm + " = " + std::to_string(diff) + " milliseconds";
	displayText(s, 5, 0.85 * SCREEN_HEIGHT);
	glFlush();
}

void draw(int x, int y)
{
	glClear(GL_COLOR_BUFFER_BIT);
	float quadSize = (SCREEN_WIDTH - 2 * (numElements + 1.0)) / numElements;
	for (int i = 0; i < numElements; i++)
	{
		if (i == x || i == y)
			glColor3f(1.0f, 0.0f, 0.0f);
		else if (isSorted[i])
			glColor3f(0.0f, 1.0f, 0.0f);
		else
			glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_POLYGON);
		glVertex2f(2 + i * (2 + quadSize), 0);
		glVertex2f(2 + i * (2 + quadSize), arrayElements[i]);
		glVertex2f(2 + i * (2 + quadSize) + quadSize, arrayElements[i]);
		glVertex2f(2 + i * (2 + quadSize) + quadSize, 0);
		glEnd();
	}
	displayInfo();
	glFlush();
}

void generate()
{
	isSorted.clear();
	arrayElements.clear();
	srand(time(0));
	for (int i = 0; i < numElements; i++)
	{
		arrayElements.push_back(((float)rand() / RAND_MAX) * SCREEN_HEIGHT * 0.8);
		isSorted.push_back(false);
	}
	draw(-1, -1);
}

void clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(0);
	glEnd();
	glFlush();
}

void menuFunc(int id)
{
	switch (id)
	{
	case 11: numElements = 10; generate(); break;
	case 12: numElements = 20; generate(); break;
	case 13: numElements = 50; generate(); break;
	case 14: numElements = 100; generate(); break;
	case 15: numElements = 200; generate(); break;
	case 16: numElements = 500; generate(); break;
	case 17: numElements = 1000; generate(); break;

	case 21: sTime = 10; draw(-1, -1); break;
	case 22: sTime = 20; draw(-1, -1); break;
	case 23: sTime = 50; draw(-1, -1); break;
	case 24: sTime = 100; draw(-1, -1); break;
	case 25: sTime = 1000; draw(-1, -1); break;

	case 31: {
		auto start = std::chrono::system_clock::now();
		bubbleSort();
		auto stop = std::chrono::system_clock::now();
		auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		displayTotalTime(diff.count(), "BubbleSort");
	} break;
	case 32: {
		auto start = std::chrono::system_clock::now();
		mergeSort(0, numElements - 1);
		auto stop = std::chrono::system_clock::now();
		auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		displayTotalTime(diff.count(), "MergeSort");
	} break;
	case 33: {
		auto start = std::chrono::system_clock::now();
		quickSort(0, numElements - 1);
		auto stop = std::chrono::system_clock::now();
		auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		displayTotalTime(diff.count(), "QuickSort");
	} break;
	case 34: {
		auto start = std::chrono::system_clock::now();
		selectionSort();
		auto stop = std::chrono::system_clock::now();
		auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		displayTotalTime(diff.count(), "SelectionSort");
	} break;
	case 35: {
		auto start = std::chrono::system_clock::now();
		insertionSort();
		auto stop = std::chrono::system_clock::now();
		auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		displayTotalTime(diff.count(), "InsertionSort");
	} break;
	case 4:exit(0);
	}
}

void createMenu() {
	int s1 = glutCreateMenu(menuFunc);
	glutAddMenuEntry("10 Numbers", 11);
	glutAddMenuEntry("20 Numbers", 12);
	glutAddMenuEntry("50 Numbers", 13);
	glutAddMenuEntry("100 Numbers", 14);
	glutAddMenuEntry("200 Numbers", 15);
	glutAddMenuEntry("500 Numbers", 16);
	glutAddMenuEntry("1000 Numbers", 17);

	int s2 = glutCreateMenu(menuFunc);
	glutAddMenuEntry("10", 21);
	glutAddMenuEntry("20", 22);
	glutAddMenuEntry("50", 23);
	glutAddMenuEntry("100", 24);
	glutAddMenuEntry("500", 25);

	int s3 = glutCreateMenu(menuFunc);
	glutAddMenuEntry("BubbleSort", 31);
	glutAddMenuEntry("MergeSort", 32);
	glutAddMenuEntry("QuickSort", 33);
	glutAddMenuEntry("SelectionSort", 34);
	glutAddMenuEntry("InsertionSort", 35);

	glutCreateMenu(menuFunc);
	glutAddSubMenu("Randomize", s1);
	glutAddSubMenu("Speed", s2);
	glutAddSubMenu("Sort", s3);
	glutAddMenuEntry("Exit", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}