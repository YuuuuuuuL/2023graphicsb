
#include <GL/glut.h>
#include <math.h>
void myCircle(float r, float x, float y){///�Τp�e�a�g�{��
    glBegin(GL_POLYGON);
   for(float a=0; a<=2*3.1415926; a+=0.01){
        glVertex2f(r*cos(a)+x, r*sin(a)+y);

   }
    glEnd();
}
    void display(){
        glColor3f(233/255.0, 141/255.0, 128/255.0);
        myCircle(0.5, 0, 0);

        glColor3f(1,1,0);
        myCircle(0.3, 0.5, 0.5);

        glColor3f(1,0,0);
        myCircle(0.3, -0.5, 0.5);

        glColor3f(0,1,0);
        myCircle(0.3, -0.5, -0.5);

        glColor3f(0,0,1);
        myCircle(0.3, 0.5, -0.5);

    glutSwapBuffers();///�洫��ܥX��
}
int main(int argc, char *argv[]){///�F�`��main()�禡
    glutInit(&argc, argv);///�n�}�lGLUT���\��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///�]�wGLUT����ܼҦ�
    glutCreateWindow("week02");///�ؤ@�ӵ��r
    glutDisplayFunc(display);///�n��ܪ��禡
    glutMainLoop();///�D�n�j��d�̫᭱
}
