#include <GL/glut.h>
#include <stdio.h>
float X=0, Y=0, Z=0;///�ϥ�global�ܼ�
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�M�I��

}
void mouse(int button, int state, int x, int y){
    X = (x-150)/150.0;///��@�b ���@�b
    Y = -(y-150)/150.0;///��@�b ���@�b y�ܭt
    if(state==GLUT_DOWN) printf("   glVertex2f(%.2f, %.2f);\n", X, Y);
}
int main(int argc, char *argv[]){///�F�`��main()�禡
    glutInit(&argc, argv);///�n�}�lGLUT���\��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///�]�wGLUT����ܼҦ�
    glutCreateWindow("week03");///�ؤ@�ӵ��r

    glutMouseFunc(mouse);
    glutDisplayFunc(display);///�n��ܪ��禡
    glutMainLoop();///�D�n�j��d�̫᭱
}
