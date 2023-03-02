#include <GL/glut.h>
#include <stdio.h>
float X=0, Y=0, Z=0;///使用global變數
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清背景

}
void mouse(int button, int state, int x, int y){
    X = (x-150)/150.0;///減一半 除一半
    Y = -(y-150)/150.0;///減一半 除一半 y變負
    if(state==GLUT_DOWN) printf("   glVertex2f(%.2f, %.2f);\n", X, Y);
}
int main(int argc, char *argv[]){///厲害的main()函式
    glutInit(&argc, argv);///要開始GLUT的功能
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///設定GLUT的顯示模式
    glutCreateWindow("week03");///建一個窗字

    glutMouseFunc(mouse);
    glutDisplayFunc(display);///要顯示的函式
    glutMainLoop();///主要迴圈卡最後面
}
