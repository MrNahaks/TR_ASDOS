#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>


void init(void);
void tampil(void);
void mouse(int button , int state,int x,int y);
void mouseMotion(int x , int y);
void ukuran(int,int);

void keyboard(unsigned char,int,int);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;


int is_depth;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(900,80);
	glutCreateWindow("Ardito Laksono Suryoputro-672019057");

	glutDisplayFunc(tampil);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(ukuran);
	init();




	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}

void init(void){
glClearColor(171/255.f,222/255.f,253/255.f,1);
glMatrixMode(GL_PROJECTION);
glEnable(GL_LIGHTING);
glEnable(GL_COLOR_MATERIAL);
glEnable(GL_LIGHT0);
glEnable(GL_DEPTH_TEST);
is_depth=1;
glMatrixMode(GL_MODELVIEW);
glPointSize(9.0);
glLineWidth(6.0f);
}



void tampil(void){
    glPushMatrix();
   if(is_depth)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
else
    glClear(GL_COLOR_BUFFER_BIT);



    glPopMatrix();

    glutSwapBuffers();

}

void keyboard(unsigned char key,int x,int y){

switch(key){
case 'w':
case 'W':

glTranslatef(0,0,3.0);
break;

case 'd':
case 'D':
    glTranslatef(3.0,0,0);
    break;

case 's':
case 'S':
    glTranslatef(0,0,-3.0);
    break;

case 'a':
case 'A':
    glTranslatef(-3.0,0,0);
    break;

case '7':
    glTranslatef(0.0,3.0,0);
    break;

case '9':
    glTranslatef(0.0,-3.0,0);
    break;

case '2':
    glRotatef(2.0,1.0,0,0);
    break;

case '8':
    glRotatef(-2.0,1.0,0,0);
    break;

case '6':
    glRotatef(2.0,0,1.0,0);
    break;

case '4':
    glRotatef(-2.0,0.0,1.0,0);
    break;

case '1':
    glRotatef(2.0,0.0,0,1.0);
    break;

case '3':
    glRotatef(-2.0,0.0,0.0,1.0);
    break;

case '5':
    if(is_depth){
        is_depth = 0;
        glDisable(GL_DEPTH_TEST);
    }
    else{
        is_depth = 1;
        glEnable(GL_DEPTH_TEST);
    }
}

tampil();
}

void idle(){
if(!mouseDown){

    xrot += 0.3f;
    yrot += 0.4f;
}
glutPostRedisplay();
}

void mouseMotion(int x, int y) {
	if (mouseDown) {
		yrot = x - xdiff;
		xrot = y + ydiff;

		glutPostRedisplay();
	}
}

void mouse(int button , int state , int x , int y){

if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
    mouseDown = true;
    xdiff = x - yrot;
    ydiff = -y +xrot;
}else mouseDown = false;

}

void ukuran(int lebar , int tinggi){
if(tinggi == 0 ) tinggi = 1;

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(80.0,lebar / tinggi, 5.0,500.0);
glTranslatef(0.0, -5.0, -150.0);
glMatrixMode(GL_MODELVIEW);



}











