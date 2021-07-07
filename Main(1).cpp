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
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(400, 80);
    glutCreateWindow("Gradski trgovski centar");

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
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);
}

void bidang(GLfloat w, GLfloat h, GLfloat x, GLfloat y, GLfloat z, GLfloat sudut, GLfloat x1, GLfloat y1, GLfloat z1) {


    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(sudut, x1, y1, z1);
    glBegin(GL_QUADS);
    glVertex3f(w, h, 0);
    glVertex3f(w, -h, 0);
    glVertex3f(-w, -h, 0);
    glVertex3f(-w, h, 0);
    glEnd();
    glPopMatrix();

}



void kotak(GLfloat ukurannya, GLfloat x, GLfloat y, GLfloat z, GLfloat sudut, GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2) {

    glPushMatrix();
    glRotatef(sudut, x1, y1, z1);
    glScalef(x2, y2, z2);
    glTranslatef(x, y, z);
    glutSolidCube(ukurannya);

    glPopMatrix();


}

void persegigedung(GLfloat x, GLfloat y, GLfloat z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    //sampingnya lagi
    kotak(10, -4, 5, -25, 0, 0, 0, 0, 2.5, 0.8, 1.2);
    //atasnya
    kotak(20, -20, 10, -25, 0, 0, 0, 0, 0.8, 4, 1.2);

    glPopMatrix();

}




void tampil(void) {
    glPushMatrix();
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);







    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);


    //latar bawah
    glColor3f(205/255, 203/255, 175/255);
    kotak(100, 6, 0, 0, 0, 0, 0, 0, 2.5, 0.01, 1.5);
    //kotak samping kiri
    glColor3f(82 / 255.f, 12 / 255.f, 1 / 255.f);
    kotak(20, -60, 10, 15, 0, 0, 0, 0, 1, 0.6, 1.5);
    //kotak depannya
    glColor3ub(112, 114, 10);
    kotak(20, -60, 10, 135, 0, 0, 0, 0, 1, 0.3, 0.3);
    //kotak belakangnya
    glColor3ub(112, 114, 10);
    kotak(20, -60, 10, 15, 0, 0, 0, 0, 1, 0.3, 0.3);

    //kotak gede
    glColor3ub(12, 124, 10);
    kotak(50, 3.5, 25, 12, 0, 0, 0, 0, 2.3, 0.7, 1.2);

    //kotak pipa kebelakang
kotak(10, -120, 5, -3, 0, 0, 0, 0, 0.5, 0.4, 4);
    //muter ke kanan
    glColor3ub(111, 123, 44);
    kotak(20, -48, 10, -150, 0, 0, 0, 0, 1, 0.3, 0.2);
    //kotak sampingnya
    glColor3ub(11, 123, 14);
    kotak(10, -20, 5, -17, 0, 0, 0, 0, 1.8, 0.8, 1.8);
    //sampingnya lagi
    kotak(10, -4, 5, -25, 0, 0, 0, 0, 2.5, 0.8, 1.2);
    //atasnya kaya gedung
    glColor3ub(255, 255, 0);
    kotak(20, -20, 10, -25, 0, 0, 0, 0, 1, 4, 1.2);
    //sampingnya
    persegigedung(30, 0, 0);

    //pipa lagi belakang
    glColor3ub(111, 123, 44);
    kotak(20, 40, 10, -150, 0, 0, 0, 0, 0.8, 0.3, 0.2);

    //bangunan samping
    kotak(10, 18, 5, -11, 0, 0, 0, 0, 3, 0.79, 2.7);
    glColor3ub(255, 255, 0);
    kotak(20, 55, 10, -25, 0, 0, 0, 0, 0.8, 4, 1.2);


    //kotak dinding
    glColor3ub(112, 123, 211);
    kotak(10, 13.5, 20, 22, 0, 0, 0, 0, 3.6, 0.6, 2.4);

    //kotak tengah yang didinding
    kotak(10, 4, 20, 19, 0, 0, 0, 0, 3.6, 0.6, 2.4);

    //kotak sebelahnya
    kotak(10, -5.5, 20, 22, 0, 0, 0, 0, 4.8, 0.6, 2.4);

    //kotak yang di depan
    glColor3ub(15, 115, 73);
    kotak(19, 53.5, 25, 230, 0, 0, 0, 0, 1, 1, 0.2);

    //kotak yang disampingnya
    kotak(19, 23.7, 25, 230, 0, 0, 0, 0, 1.1, 1, 0.2);
    kotak(19, 0.5, 25, 230, 0, 0, 0, 0, 1, 1, 0.2);

    //kotak yang tegak disamping
    glColor3ub(77, 79, 78);
    kotak(20, -90, 25, 240, 0, 0, 0, 0, 0.28, 1, 0.2);
    kotak(20, -120, 25, 240, 0, 0, 0, 0, 0.28, 1, 0.2);
    kotak(20, -150, 25, 240, 0, 0, 0, 0, 0.28, 1, 0.2);

    //kotak atap yang besar
    kotak(40, -35, 110, 10, 0, 0, 0, 0, 1, 0.35, 1.8);

    //atap tiga
    kotak(40, 0, 110, 10, 0, 0, 0, 0, 0.6, 0.35, 1.7);
    kotak(40, 44, 110, 10, 0, 0, 0, 0, 0.6, 0.35, 1.7);
    kotak(40, 90, 110, 10, 0, 0, 0, 0, 0.6, 0.35, 1.7);


    //kotak tangga biru
    glColor3ub(0, 204, 255);
    kotak(5, 3.6, 28, 55, 0, 0, 0, 0, 5, 0.5, 1.1);
    kotak(5, 5, 28, 24.5, 0, 0, 0, 0, 0.8, 0.5, 2.6);
    kotak(5, 2.3, 29, 61, -25, 0, 0, 1, 5.5, 0.5, 1.1);

    //ungu samping kiri
    glColor3ub(112, 123, 211);
    kotak(13, -38, 24, 7, 0, 0, 0, 0, 1.6, 0.5, 4);


    //pagar kuning
    glColor3ub(255, 255, 0);
    kotak(4, -12, 12, 5.9, 0, 0, 0, 0, 5, 1.5, 0.5);
    kotak(4, -235, 12, 2.15, 0, 0, 0, 0, 0.3, 1.5, 13);
    kotak(4, -12, 12, 106, 0, 0, 0, 0, 5, 1.5, 0.5);
    kotak(4, -169, 12, 21.2, 0, 0, 0, 0, 0.3, 1.5, 2.8);
    kotak(4, -2.2, 12, 128, 0, 0, 0, 0, 12, 1.5, 0.5);
    kotak(4, -10, 12, 36, 0, 0, 0, 0, 0.3, 1.5, 1.7);
    kotak(4, 1.6, 12, 115, 0, 0, 0, 0, 8.6, 1.5, 0.5);

    kotak(4, 5.4, 12, 128, 0, 0, 0, 0, 9, 1.4, 0.5);

  //jendela
    glColor3ub(255, 255, 255);
    
    //Kuning 3 Belakang
    kotak(4, -16, 11, -175, 0, 0, 0, 0, 1.5, 6, 0.1);
    kotak(4, -10.5, 11, -175, 0, 0, 0, 0, 1.5, 6, 0.1);

    kotak(4, -16, 11, -420, 0, 0, 0, 0, 1.5, 6, 0.1);
    kotak(4, -10.5, 11, -420, 0, 0, 0, 0, 1.5, 6, 0.1);

    kotak(4, -16, 5, -420, 0, 0, 0, 0, 1.5, 6, 0.1);
    kotak(4, -10.5, 5, -420, 0, 0, 0, 0, 1.5, 6, 0.1);

    kotak(4, 7, 11, -175, 0, 0, 0, 0, 1.5, 6, 0.1);
    kotak(4, 12, 11, -175, 0, 0, 0, 0, 1.5, 6, 0.1);

    kotak(4, 7, 11, -420, 0, 0, 0, 0, 1.5, 6, 0.1);
    kotak(4, 12, 11, -420, 0, 0, 0, 0, 1.5, 6, 0.1);

    kotak(4, 7, 5, -420, 0, 0, 0, 0, 1.5, 6, 0.1);
    kotak(4, 12, 5, -420, 0, 0, 0, 0, 1.5, 6, 0.1);

    kotak(4, 27, 11, -175, 0, 0, 0, 0, 1.5, 6, 0.1);
    kotak(4, 32, 11, -175, 0, 0, 0, 0, 1.5, 6, 0.1);

    kotak(4, 27, 11, -420, 0, 0, 0, 0, 1.5, 6, 0.1);
    kotak(4, 32, 11, -420, 0, 0, 0, 0, 1.5, 6, 0.1);

    kotak(4, 27, 5, -420, 0, 0, 0, 0, 1.5, 6, 0.1);
    kotak(4, 32, 5, -420, 0, 0, 0, 0, 1.5, 6, 0.1);
    
    //Kuning 2 Atas

    kotak(4, 20, 11, -60, 0, 0, 0, 0, 1.5, 6, 0.1);
    kotak(4, 15.5, 11, -60, 0, 0, 0, 0, 1.5, 6, 0.1);

    kotak(4, 20, 11, 90, 0, 0, 0, 0, 1.5, 6, 0.1);
    kotak(4, 15.5, 11, 90, 0, 0, 0, 0, 1.5, 6, 0.1);

    kotak(4, 3, 11, -60, 0, 0, 0, 0, 1.5, 6, 0.1);
    kotak(4, -1.5, 11, -60, 0, 0, 0, 0, 1.5, 6, 0.1);

    kotak(4, 3, 11, 90, 0, 0, 0, 0, 1.5, 6, 0.1);
    kotak(4, -1.5, 11, 90, 0, 0, 0, 0, 1.5, 6, 0.1);

    //Coklat
    kotak(4, 51, 10, 335, 0, 0, 0, 0, 1.5, 6, 0.1);
    kotak(4, 57, 10, 335, 0, 0, 0, 0, 1.5, 6, 0.1);

    kotak(4, 51, 10, 565, 0, 0, 0, 0, 1.5, 6, 0.1);
    kotak(4, 57, 10, 565, 0, 0, 0, 0, 1.5, 6, 0.1);

    kotak(4, 51, 5, 565, 0, 0, 0, 0, 1.5, 6, 0.1);
    kotak(4, 57, 5, 565, 0, 0, 0, 0, 1.5, 6, 0.1);

    kotak(4, -33.5, 10, 908, 90, 0, 1, 0, 1.5, 6, 0.1);
    kotak(4, -26.5, 10, 908, 90, 0, 1, 0, 1.5, 6, 0.1);
    
    kotak(4, -33.5, 5, 908, 90, 0, 1, 0, 1.5, 6, 0.1);
    kotak(4, -26.5, 5, 908, 90, 0, 1, 0, 1.5, 6, 0.1);

    kotak(4, -33.5, 10, 708.5, 90, 0, 1, 0, 1.5, 6, 0.1);
    kotak(4, -26.5, 10, 708.5, 90, 0, 1, 0, 1.5, 6, 0.1);

    kotak(4, -33.5, 5, 708.5, 90, 0, 1, 0, 1.5, 6, 0.1);
    kotak(4, -26.5, 5, 708.5, 90, 0, 1, 0, 1.5, 6, 0.1);

    //Merah
    kotak(4, 58.5, 8.25, -420, 0, 0, 0, 0, 1.5, 5, 0.1);
    kotak(4, 66, 8.25, -420, 0, 0, 0, 0, 1.5, 5, 0.1);

    kotak(4, 58.5, 3.25, -420, 0, 0, 0, 0, 1.5, 5, 0.1);
    kotak(4, 66, 3.25, -420, 0, 0, 0, 0, 1.5, 5, 0.1);

    kotak(4, 58.5, 8.25, 30, 0, 0, 0, 0, 1.5, 5, 0.1);
    kotak(4, 66, 8.25, 30, 0, 0, 0, 0, 1.5, 5, 0.1);

    kotak(4, 66, 3.25, 30, 0, 0, 0, 0, 1.5, 5, 0.1);

    kotak(4, 25.5, 3.25, 1045, 90, 0, 1, 0, 1.5, 5, 0.1);
    kotak(4, 20, 3.25, 1045, 90, 0, 1, 0, 1.5, 5, 0.1);

    kotak(4, 25.5, 8.25, 1045, 90, 0, 1, 0, 1.5, 5, 0.1);
    kotak(4, 20, 8.25, 1045, 90, 0, 1, 0, 1.5, 5, 0.1);

    kotak(4, 7, 3.25, 1045, 90, 0, 1, 0, 1.5, 5, 0.1);
    kotak(4, 1.5, 3.25, 1045, 90, 0, 1, 0, 1.5, 5, 0.1);

    kotak(4, 7, 8.25, 1045, 90, 0, 1, 0, 1.5, 5, 0.1);
    kotak(4, 1.5, 8.25, 1045, 90, 0, 1, 0, 1.5, 5, 0.1);

    //Hijau
    kotak(4, 18.5, 3.25, 1140, 90, 0, 1, 0, 1.25, 5, 0.1);
    kotak(4, 13.5, 3.25, 1140, 90, 0, 1, 0, 1.25, 5, 0.1);

    kotak(4, 18.5, 7.5, 1140, 90, 0, 1, 0, 1.25, 5, 0.1);
    kotak(4, 13.5, 7.5, 1140, 90, 0, 1, 0, 1.25, 5, 0.1);

    //Ungu
    kotak(4, -11.5, 17.5, 950, 90, 0, 1, 0, 2.5, 1.25, 0.1);
    kotak(4, -5.5, 17.5, 950, 90, 0, 1, 0, 2.5, 1.25, 0.1);
    
    kotak(4, -11.5, 10.5, 950, 90, 0, 1, 0, 2.5, 1.25, 0.1);
    kotak(4, -5.5, 10.5, 950, 90, 0, 1, 0, 2.5, 1.25, 0.1);

    //Biru Muda
    kotak(4, 13.25, 5.5, 485, 0, 0, 0, 0, 4.05, 4, 0.1);

    kotak(4, 6.5, 5.5, 485, 0, 0, 0, 0, 4.05, 4, 0.1);

    kotak(4, 0.15, 5.5, 485, 0, 0, 0, 0, 4.05, 4, 0.1);

    //bangun coklat
    glColor3ub(89, 45, 0);
    kotak(15, 62, 7.5, 30, 0, 0, 0, 0, 1.3, 5, 1.5);

    //bangun ungu
    glColor3ub(112, 123, 211);
    kotak(15, 40, 7.5, 8, 0, 0, 0, 0, 2, 2, 2.5);

    //bangun merah
    glColor3ub(255, 0, 0);
    kotak(15, 62, 7.5, -6.5, 0, 0, 0, 0, 1.5, 3.5, 3);

    //bangun pink
    glColor3ub(255, 0, 255);
    kotak(15, 35, 5, -6.5, 0, 0, 0, 0, 2, 2, 3);


    //bangun hijau
    glColor3ub(0, 255, 0);
    kotak(15, 135, 7.5, -25, 0, 0, 0, 0, 0.8, 3.3, 0.8);

    //bangun atas kuning
    glColor3ub(255, 255, 0);
    kotak(10, 19, 17, 1, 0, 0, 0, 0, 1.4, 3.7, 1.5);

    kotak(10, 1, 17, 1, 0, 0, 0, 0, 1.4, 3.7, 1.5);

    //Kotak Atap Panjang
    glColor3ub(77, 79, 78);
    kotak(8.5, -5.5, 45, 15, 0, 0, 0, 0, 3, 1, 1);
    kotak(8.5, 8, 45, 15, 0, 0, 0, 0, 3, 1, 1);
    kotak(8.5, 18, 62.5, 15, 0, 0, 0, 0, 3, 0.75, 1);

    //Kotak Atap Potongan
    glColor3ub(77, 79, 78);
    kotak(10, 15.5, 185, 16.5, 0, 0, 0, 0, 0.75, 0.25, 1.75);
    kotak(10, 52.5, 185, 16.5, 0, 0, 0, 0, 0.75, 0.25, 1.75);

    //Kotak Atap Balok
    glColor3ub(0, 0, 0);
    kotak(10, -2.5, 45, 40, 0, 0, 0, 0, 1, 1, 1);
    kotak(10, 20, 45, 42.5, 0, 0, 0, 0, 1, 1, 1);
    kotak(10, 32.5, 45, 42.5, 0, 0, 0, 0, 1, 1, 1);
    kotak(10, 57.5, 45, 40, 0, 0, 0, 0, 1, 1, 1);
    kotak(10, 57.5, 45, 0, 0, 0, 0, 0, 1, 1, 1);

    //Atap Bangun Ungu
    glColor3ub(77, 79, 78);
    kotak(10, 45.5, 125, 35.5, 0, 0, 0, 0, 1.75, 0.25, 0.75);
    kotak(10, 45.5, 125, 21.5, 0, 0, 0, 0, 1.75, 0.25, 0.75);

    //Interior
    //Kulkas
    glColor3ub(0, 0, 255);
    kotak(5, 20, 2.5, -18.5, 0, 0, 0, 0, 1.75, 5.25, 0.75);
    //Kaca Kulkas
    glColor3ub(255, 255, 255);
    kotak(10, 54, 6.5, -50.5, 0, 0, 0, 0, 0.65, 1.15, 0.25);
    kotak(10, 54, 27, -50.5, 0, 0, 0, 0, 0.65, 0.75, 0.25);

    //AC
    glColor3ub(255, 255, 255);
    kotak(10, 10, 33, -56.5, 0, 0, 0, 0, 1.65, 0.75, 0.25);
    


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
    gluPerspective(80.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);



}










