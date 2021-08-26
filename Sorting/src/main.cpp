#include<windows.h>
#include<GL/glut.h>

const unsigned int SCREEN_WIDTH = 600;
const unsigned int SCREEN_HEIGHT = 600;

// Function Prototypes
// ----------------------------------------------------------------------------

// Render window
void display();
void init();

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

	CreateMenu();

	//Enter the GLUT event loop
	glutMainLoop();

	return 0;
}

void display()
{
	//Clear all pixels
	glClear(GL_COLOR_BUFFER_BIT);

	//draw white polygon (rectangle) with corners at
	// (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glEnd();

	// Don't wait start processing buffered OpenGL routines
	glFlush();
}
void init()
{
	//select clearing (background) color
	glClearColor(0.0, 0.0, 0.0, 0.0);

	//initialize viewing values 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}