#include <windows.h>
#include <GL/glut.h>
#include <string>
#include <vector>
#include <chrono>

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

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Sorting Algorithm Visualizer");
	init();
	glutDisplayFunc(display);
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
	glColor3f(1.0f, 1.0f, 1.0f);
	// DELETE: Placeholder text
	std::string values = "Bubble Sort - xx comparisons, xx array access, 0.5 ms delay";
	displayText(values, 5, 0.97 * SCREEN_HEIGHT);
	glColor3f(1.0f, 1.0f, 1.0f);
	std::string timeTaken = "Total Time: 500 milliseconds";
	displayText(timeTaken, 5, 0.94 * SCREEN_HEIGHT);
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

