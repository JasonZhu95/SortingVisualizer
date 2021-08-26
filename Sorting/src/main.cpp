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
// DELETE: Temp Values
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
	glClearColor(0.0, 0.0, 0.0, 0.0);
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
	glColor3f(1, 1, 1);
	std::string s = "Elements = " + std::to_string(numElements);
	displayText(s, 5, 0.95 * SCREEN_HEIGHT);
	s = "Time = " + std::to_string(sTime) + " milliseconds/operation";
	displayText(s, 5, 0.9 * SCREEN_HEIGHT);
}

void displayTotalTime(int diff, std::string algorithm)
{
	glColor3f(1, 1, 1);
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
	srand(time(NULL));
	isSorted.clear();
	arrayElements.clear();
	for (int i = 0; i < numElements; i++)
	{
		arrayElements.push_back(((float)rand() / RAND_MAX) * SCREEN_HEIGHT * 0.8);
		isSorted.push_back(false);
	}
	draw(-1, -1);
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
		case 21: {
			auto start = std::chrono::system_clock::now();
			bubbleSort();
			auto stop = std::chrono::system_clock::now();
			auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
			displayTotalTime(diff.count(), "BubbleSort");
		} break;
		case 22: {
			auto start = std::chrono::system_clock::now();
			mergeSort(0, numElements - 1);
			auto stop = std::chrono::system_clock::now();
			auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
			displayTotalTime(diff.count(), "BubbleSort");
		} break;
		case 23: {
			auto start = std::chrono::system_clock::now();
			quickSort(0, numElements - 1);
			auto stop = std::chrono::system_clock::now();
			auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
			displayTotalTime(diff.count(), "BubbleSort");
		} break;
		//case 24: {
		//	auto start = system_clock::now();
		//	bubbleSort();
		//	auto stop = system_clock::now();
		//	auto diff = duration_cast<milliseconds>(stop - start);
		//	displayTotalTime(diff.count(), "BubbleSort");
		//} break;
		//case 25: {
		//	auto start = system_clock::now();
		//	bubbleSort();
		//	auto stop = system_clock::now();
		//	auto diff = duration_cast<milliseconds>(stop - start);
		//	displayTotalTime(diff.count(), "BubbleSort");
		//} break;
		case 31: sTime = 5; draw(-1, -1); break;
		case 32: sTime = 20; draw(-1, -1); break;
		case 33: sTime = 50; draw(-1, -1); break;
		case 34: sTime = 100; draw(-1, -1); break;
		case 35: sTime = 500; draw(-1, -1); break;
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

	int s3 = glutCreateMenu(menuFunc);
	glutAddMenuEntry("5", 31);
	glutAddMenuEntry("20", 32);
	glutAddMenuEntry("50", 33);
	glutAddMenuEntry("100", 34);
	glutAddMenuEntry("500", 35);

	int s2 = glutCreateMenu(menuFunc);
	glutAddMenuEntry("BubbleSort", 21);
	glutAddMenuEntry("MergeSort", 22);
	glutAddMenuEntry("QuickSort", 23);

	glutCreateMenu(menuFunc);
	glutAddSubMenu("Randomize", s1);
	glutAddSubMenu("Speed(Time/oper)", s3);
	glutAddSubMenu("Sort", s2);
	glutAddMenuEntry("Exit", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}