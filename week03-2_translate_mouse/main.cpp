#include <GL/glut.h>
float X=0, Y=0, Z=0;///�ϥ�global�ܼ�
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�M�I��
    glPushMatrix();///�ƥ��x�}
        glTranslatef(X, Y, Z);///��XYZ����
        glutSolidTeapot(0.3);///�e�X��ߪ�����
    glPopMatrix();///�٭�x�}
    glutSwapBuffers();///�洫��ܥX��
}
void mouse(int button, int state, int x, int y){
    X = (x-150)/150.0;///��@�b ���@�b
    Y = -(y-150)/150.0;///��@�b ���@�b y�ܭt
}
int main(int argc, char *argv[]){///�F�`��main()�禡
    glutInit(&argc, argv);///�n�}�lGLUT���\��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///�]�wGLUT����ܼҦ�
    glutCreateWindow("week03");///�ؤ@�ӵ��r

    glutMouseFunc(mouse);
    glutDisplayFunc(display);///�n��ܪ��禡
    glutMainLoop();///�D�n�j��d�̫᭱
}
