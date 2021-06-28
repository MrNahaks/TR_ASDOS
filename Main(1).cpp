#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>


void init(void);
void tampil(void);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void ukuran(int, int);

void keyboard(unsigned char, int, int);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;


int is_depth;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(900, 80);
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

void init(void) {
    glClearColor(171 / 255.f, 222 / 255.f, 253 / 255.f, 1);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);
}



void tampil(void) {
    glPushMatrix();
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);

    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    glBegin(GL_QUADS);//tanah
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(300.0, 0.0, 0.0);
    glVertex3f(300.0, 0.0, 120.0);
    glVertex3f(0.0, 0.0, 120.0);
    glEnd();
    glBegin(GL_QUADS);//b1
    glColor3f(255.0/255.0, 255.0/255.0, 240.0/255.0);
    glVertex3f(10.0, 0.0, 0.0);
    glVertex3f(40.0, 0.0, 0.0);
    glVertex3f(40.0, 5.0, 0.0);
    glVertex3f(10.0, 5.0, 0.0);
    glEnd();
    glBegin(GL_QUADS);//b2
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(40.0, 0.0, 0.0);
    glVertex3f(40.0, 0.0, 10.0);
    glVertex3f(40.0, 5.0, 10.0);
    glVertex3f(40.0, 5.0, 0.0);
    glEnd();
    glBegin(GL_QUADS);//b3
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(40.0, 0.0, 10.0);
    glVertex3f(200.0, 0.0, 11.0);
    glVertex3f(200.0, 5.5, 11.0);
    glVertex3f(40.0, 5.0, 10.0);
    glEnd();
    glBegin(GL_QUADS);//b4
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(200.0, 0.0, 11.0);
    glVertex3f(200.0, 0.0, 20.0);
    glVertex3f(200.0, 5.0, 20.0);
    glVertex3f(200.0, 5.5, 11.0);
    glEnd();
    glBegin(GL_QUADS);//b5
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(200.0, 0.0, 20.0);
    glVertex3f(260.0, 0.0, 20.0);
    glVertex3f(260.0, 5.0, 20.0);
    glVertex3f(200.0, 5.0, 20.0);
    glEnd();
    glBegin(GL_QUADS);//b6
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(220.0, 0.0, 0.0);
    glVertex3f(240.0, 0.0, 0.0);
    glVertex3f(240.0, 4.7, 0.0);
    glVertex3f(220.0, 4.7, 0.0);
    glEnd();
    glBegin(GL_QUADS);//l1-k1
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(240.0, 0.0, 0.0);
    glVertex3f(240.0, 0.0, 20.0);
    glVertex3f(240.0, 4.7, 20.0);
    glVertex3f(240.0, 4.7, 0.0);
    glEnd();
    glBegin(GL_QUADS);//b7
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(220.0, 0.0, 20.0);
    glVertex3f(220.0, 0.0, 0.0);
    glVertex3f(220.0, 4.7, 0.0);
    glVertex3f(220.0, 4.71, 20.0);
    glEnd();
    glBegin(GL_QUADS);//b8
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(240.0, 0.0, 20.0);
    glVertex3f(240.0, 0.0, 20.0);
    glVertex3f(240.0, 4.7, 20.0);
    glVertex3f(240.0, 4.71, 20.0);
    glEnd();
    glBegin(GL_QUADS);//b9
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(260.0, 0.0, 20.0);
    glVertex3f(260.0, 0.0, 60.0);
    glVertex3f(260.0, 5.0, 60.0);
    glVertex3f(260.0, 5.0, 20.0);
    glEnd();
    glBegin(GL_QUADS);//b10
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(260.0, 0.0, 60.0);
    glVertex3f(268.5, 0.0, 60.0);
    glVertex3f(268.5, 5.0, 60.0);
    glVertex3f(260.0, 5.0, 60.0);
    glEnd();
    glBegin(GL_QUADS);//b11
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(268.5, 0.0, 60.0);
    glVertex3f(268.5, 0.0, 74.0);
    glVertex3f(268.5, 5.0, 74.0);
    glVertex3f(268.5, 5.0, 60.0);
    glEnd();
    glBegin(GL_QUADS);//b12
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(268.5, 0.0, 74.0);
    glVertex3f(280.0, 0.0, 74.0);
    glVertex3f(280.0, 5.0, 74.0);
    glVertex3f(268.5, 5.0, 74.0);
    glEnd();
    glBegin(GL_QUADS);//b13
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(280.0, 0.0, 74.0);
    glVertex3f(280.0, 0.0, 89.0);
    glVertex3f(280.0, 5.0, 89.0);
    glVertex3f(280.0, 5.0, 74.0);
    glEnd();
    glBegin(GL_QUADS);//b14
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(280.0, 0.0, 89.0);
    glVertex3f(268.5, 0.0, 89.0);
    glVertex3f(268.5, 5.0, 89.0);
    glVertex3f(280.0, 5.0, 89.0);
    glEnd();
    glBegin(GL_QUADS);//b15
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(268.5, 0.0, 89.0);
    glVertex3f(268.5, 0.0, 100.0);
    glVertex3f(268.5, 5.0, 100.0);
    glVertex3f(268.5, 5.0, 89.0);
    glEnd();
    glBegin(GL_QUADS);//b16
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(268.5, 0.0, 100.0);
    glVertex3f(252.0, 0.0, 100.0);
    glVertex3f(252.5, 5.0, 100.0);
    glVertex3f(268.5, 5.0, 100.0);
    glEnd();
    glBegin(GL_QUADS);//b16
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(268.5, 0.0, 100.0);
    glVertex3f(252.0, 0.0, 100.0);
    glVertex3f(252.5, 5.0, 100.0);
    glVertex3f(268.5, 5.0, 100.0);
    glEnd();
    glBegin(GL_QUADS);//b17
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(252.0, 0.0, 100.0);
    glVertex3f(200.0, 0.0, 100.0);
    glVertex3f(200.0, 2.8, 100.0);
    glVertex3f(252.0, 2.8, 100.0);
    glEnd();
    glBegin(GL_QUADS);//b18
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(200.0, 0.0, 80.0);
    glVertex3f(200.0, 0.0, 105.0);
    glVertex3f(200.0, 5.0, 105.0);
    glVertex3f(200.0, 5.0, 80.0);
    glEnd();
    glBegin(GL_QUADS);//b19
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(200.0, 0.0, 105.0);
    glVertex3f(171.5, 0.0, 105.0);
    glVertex3f(171.5, 5.0, 105.0);
    glVertex3f(200.0, 5.0, 105.0);
    glEnd();
    glBegin(GL_QUADS);//b20
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(171.5, 0.0, 105.0);
    glVertex3f(171.5, 0.0, 111.0);
    glVertex3f(171.5, 5.0, 111.0);
    glVertex3f(171.5, 5.0, 105.0);
    glEnd();
    glBegin(GL_QUADS);//b21
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(171.5, 0.0, 111.0);
    glVertex3f(149.0, 0.0, 111.0);
    glVertex3f(149.0, 5.0, 111.0);
    glVertex3f(171.5, 5.0, 111.0);
    glEnd();
    glBegin(GL_QUADS);//b22
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(149.0, 0.0, 111.0);
    glVertex3f(120.0, 0.0, 111.0);
    glVertex3f(120.0, 5.0, 111.0);
    glVertex3f(149.5, 5.0, 111.0);
    glEnd();
    glBegin(GL_QUADS);//b23
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(120.0, 0.0, 111.0);
    glVertex3f(120.0, 0.0, 111.0);
    glVertex3f(120.0, 5.0, 111.0);
    glVertex3f(120.0, 5.0, 111.0);
    glEnd();
    glBegin(GL_QUADS);//b24
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(120.0, 0.0, 111.0);
    glVertex3f(140.0, 0.0, 111.0);
    glVertex3f(140.0, 5.0, 111.0);
    glVertex3f(120.0, 5.0, 111.0);
    glEnd();
    glBegin(GL_QUADS);//b25
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(140.0, 0.0, 111.0);
    glVertex3f(140.0, 0.0, 107.0);
    glVertex3f(140.0, 5.0, 107.0);
    glVertex3f(140.0, 5.0, 111.0);
    glEnd();
    glBegin(GL_QUADS);//b26
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(140.0, 0.0, 107.0);
    glVertex3f(149.0, 0.0, 107.0);
    glVertex3f(149.0, 5.0, 107.0);
    glVertex3f(140.0, 5.0, 107.0);
    glEnd();
    glBegin(GL_QUADS);//a3-e3
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(149.0, 0.0, 107.0);
    glVertex3f(140.0, 0.0, 107.0);
    glVertex3f(140.0, 5.0, 107.0);
    glVertex3f(149.0, 5.0, 107.0);
    glEnd();
    glBegin(GL_QUADS);//e3-d3
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(140.0, 0.0, 107.0);
    glVertex3f(140.0, 0.0, 100.0);
    glVertex3f(140.0, 5.0, 100.0);
    glVertex3f(140.0, 5.0, 107.0);
    glEnd();
    glBegin(GL_QUADS);//d3-c3
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(140.0, 0.0, 100.0);
    glVertex3f(120.0, 0.0, 100.0);
    glVertex3f(120.0, 5.0, 100.0);
    glVertex3f(140.0, 5.0, 100.0);
    glEnd();
    glBegin(GL_QUADS);//b3-c3
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(120.0, 0.0, 111.0);
    glVertex3f(120.0, 0.0, 100.0);
    glVertex3f(120.0, 5.0, 100.0);
    glVertex3f(120.0, 5.0, 111.0);
    glEnd();
    glBegin(GL_QUADS);//q-p
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(200.0, 0.0, 80.0);
    glVertex3f(40.0, 0.0, 80.0);
    glVertex3f(40.0, 5.0, 80.0);
    glVertex3f(200.0, 5.0, 80.0);
    glEnd();
    glBegin(GL_QUADS);//p-o
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(40.0, 0.0, 80.0);
    glVertex3f(40.0, 0.0, 10.0);
    glVertex3f(40.0, 5.0, 10.0);
    glVertex3f(40.0, 5.0, 80.0);
    glEnd();
    glBegin(GL_QUADS);//r-q
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(200.0, 0.0, 11.0);
    glVertex3f(200.0, 0.0, 80.0);
    glVertex3f(200.0, 5.0, 80.0);
    glVertex3f(200.0, 5.0, 11.0);
    glEnd();
    glBegin(GL_QUADS);//m3-n3
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(100.0, 0.0, 111.0);
    glVertex3f(60.0, 0.0, 111.0);
    glVertex3f(60.0, 5.0, 111.0);
    glVertex3f(100.0, 5.0, 111.0);
    glEnd();
    glBegin(GL_QUADS);//n3-o3
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(60.0, 0.0, 111.0);
    glVertex3f(60.0, 0.0, 100.0);
    glVertex3f(60.0, 5.0, 100.0);
    glVertex3f(60.0, 5.0, 111.0);
    glEnd();
    glBegin(GL_QUADS);//o3-f3
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(60.0, 0.0, 100.0);
    glVertex3f(100.0, 0.0, 100.0);
    glVertex3f(100.0, 5.0, 100.0);
    glVertex3f(60.0, 5.0, 100.0);
    glEnd();
    glBegin(GL_QUADS);//f3-m3
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(100.0, 0.0, 100.0);
    glVertex3f(100.0, 0.0, 111.0);
    glVertex3f(100.0, 5.0, 111.0);
    glVertex3f(100.0, 5.0, 100.0);
    glEnd();
    glBegin(GL_QUADS);//p3-q3
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(45.0, 0.0, 113.0);
    glVertex3f(25.0, 0.0, 113.0);
    glVertex3f(25.0, 5.0, 113.0);
    glVertex3f(45.0, 5.0, 113.0);
    glEnd();
    glBegin(GL_QUADS);//a4-p3
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(45.0, 0.0, 94.0);
    glVertex3f(45.0, 0.0, 113.0);
    glVertex3f(45.0, 5.0, 113.0);
    glVertex3f(45.0, 5.0, 94.0);
    glEnd();
    glBegin(GL_QUADS);//z3-a4
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(25.0, 0.0, 94.0);
    glVertex3f(45.0, 0.0, 94.0);
    glVertex3f(45.0, 5.0, 94.0);
    glVertex3f(25.0, 5.0, 94.0);
    glEnd();
    glBegin(GL_QUADS);//q3-z3
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(25.0, 0.0, 113.0);
    glVertex3f(25.0, 0.0, 94.0);
    glVertex3f(25.0, 5.0, 94.0);
    glVertex3f(25.0, 5.0, 113.0);
    glEnd();
    glBegin(GL_QUADS);//f4-g4
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(25.0, 0.0, 105.0);
    glVertex3f(11.0, 0.0, 105.0);
    glVertex3f(11.0, 5.0, 105.0);
    glVertex3f(25.0, 5.0, 105.0);
    glEnd();
    glBegin(GL_QUADS);//f4-o4
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(25.0, 0.0, 105.0);
    glVertex3f(25.0, 0.0, 100.0);
    glVertex3f(25.0, 5.0, 100.0);
    glVertex3f(25.0, 5.0, 105.0);
    glEnd();
    glBegin(GL_QUADS);//o4-n4
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(25.0, 0.0, 100.0);
    glVertex3f(16.0, 0.0, 100.0);
    glVertex3f(16.0, 5.0, 100.0);
    glVertex3f(25.0, 5.0, 100.0);
    glEnd();
    glBegin(GL_QUADS);//g4-h4
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(11.0, 0.0, 105.0);
    glVertex3f(11.0, 0.0, 72.0);
    glVertex3f(11.0, 5.0, 72.0);
    glVertex3f(11.0, 5.0, 105.0);
    glEnd();
    glBegin(GL_QUADS);//h4-i4
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(11.0, 0.0, 72.0);
    glVertex3f(16.0, 0.0, 72.0);
    glVertex3f(16.0, 5.0, 72.0);
    glVertex3f(11.0, 5.0, 72.0);
    glEnd();
    glBegin(GL_QUADS);//i4-n4
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(16.0, 0.0, 72.0);
    glVertex3f(16.0, 0.0, 100.0);
    glVertex3f(16.0, 5.0, 100.0);
    glVertex3f(16.0, 5.0, 72.0);
    glEnd();
    glBegin(GL_QUADS);//h4-r4
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(11.0, 0.0, 72.0);
    glVertex3f(11.0, 0.0, 60.0);
    glVertex3f(11.0, 3.6, 60.0);
    glVertex3f(11.0, 3.6, 72.0);
    glEnd();
    glBegin(GL_QUADS);//e-q4
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(5.0, 0.0, 60.0);
    glVertex3f(40.0, 0.0, 60.0);
    glVertex3f(40.0, 5.0, 60.0);
    glVertex3f(5.0, 5.0, 60.0);
    glEnd();
    glBegin(GL_QUADS);//e-f
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(5.0, 0.0, 60.0);
    glVertex3f(5.0, 0.0, 10.0);
    glVertex3f(5.0, 5.0, 10.0);
    glVertex3f(5.0, 5.0, 60.0);
    glEnd();
    glBegin(GL_QUADS);//g-m
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(10.0, 0.0, 10.0);
    glVertex3f(10.0, 0.0, 0.0);
    glVertex3f(10.0, 5.0, 0.0);
    glVertex3f(10.0, 5.0, 10.0);
    glEnd();
    glBegin(GL_QUADS);//f-g
    glColor3f(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0);
    glVertex3f(5.0, 0.0, 10.0);
    glVertex3f(10.0, 0.0, 10.0);
    glVertex3f(10.0, 5.0, 10.0);
    glVertex3f(5.0, 5.0, 10.0);
    glEnd();
    glPopMatrix();

    glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y) {

    switch (key) {
    case 'w':
    case 'W':

        glTranslatef(0, 0, 3.0);
        break;

    case 'd':
    case 'D':
        glTranslatef(3.0, 0, 0);
        break;

    case 's':
    case 'S':
        glTranslatef(0, 0, -3.0);
        break;

    case 'a':
    case 'A':
        glTranslatef(-3.0, 0, 0);
        break;

    case '7':
        glTranslatef(0.0, 3.0, 0);
        break;

    case '9':
        glTranslatef(0.0, -3.0, 0);
        break;

    case '2':
        glRotatef(2.0, 1.0, 0, 0);
        break;

    case '8':
        glRotatef(-2.0, 1.0, 0, 0);
        break;

    case '6':
        glRotatef(2.0, 0, 1.0, 0);
        break;

    case '4':
        glRotatef(-2.0, 0.0, 1.0, 0);
        break;

    case '1':
        glRotatef(2.0, 0.0, 0, 1.0);
        break;

    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;

    case '5':
        if (is_depth) {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }

    tampil();
}

void idle() {
    if (!mouseDown) {

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

void mouse(int button, int state, int x, int y) {

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else mouseDown = false;

}

void ukuran(int lebar, int tinggi) {
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(600.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);



}
