#include <GL/glut.h>

#include "main.h" 

void display(void) {
	render();
	glFlush();
	glClear(GL_COLOR_BUFFER_BIT);
}

void timer() {
	glutPostRedisplay();
	eventLoop();
	glutTimerFunc(1000/FPS,timer,0);
}

void start(int argc, char **const argv) {
	 //Parses cmd args, adjusts argc based on the amount of args left over after parsing
	glutInit(&argc, argv);
	
	glutInitWindowSize(SC_W, SC_H);
        glutCreateWindow("OpenGL ginger framework");
        
        //Coords: Left is 0, Right is SC_W, Bottom is SC_H, Top is 0
        gluOrtho2D(0, SC_W, SC_H, 0);   
        
	eventInit();
        glutDisplayFunc(display);
        glutTimerFunc(0,timer,0);

        glutMainLoop();
}
