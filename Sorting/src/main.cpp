#include<windows.h>
#include <string>
#include<GL/glut.h>

const unsigned int SCREEN_WIDTH = 1024;
const unsigned int SCREEN_HEIGHT = 768;

// Function Prototypes
// ----------------------------------------------------------------------------

// Render window
void display();
void init();

// Render to screen
void draw();
void generate();

// Text On Screen
void displayText(std::string textToDraw, int x, int y);
void displayInfo();

int main(int argc, char** argv)
{
	//Initialise GLUT with command-line parameters. 
	glutInit(&argc, argv);

	//Set Display Mode
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	//Set the window size
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	//Set the window position
	glutInitWindowPosition(100, 100);

	//Create the window
	glutCreateWindow("Sorting Algorithm Visualizer");

	//Call init (initialize GLUT)
	init();

	//Call "display" function
	glutDisplayFunc(display);

	//Enter the GLUT event loop
	glutMainLoop();

	return 0;
}

void init()
{
	//select clearing (background) color
	glClearColor(0.0, 0.0, 0.0, 0.0);

	//initialize viewing values 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClearColor(0, 0, 0, 1);
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

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	displayInfo();
	glFlush();
}

void generate()
{
	draw();
}