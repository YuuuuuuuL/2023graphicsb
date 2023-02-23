#include <GL/glut.h>

void display(){
    glColor3f(2,2,0);///色彩
    glutSolidTeapot(0.5);///畫出實心的大茶壺

    glColor3f(0,2,2);///色彩
    glutSolidTeapot(0.3);///畫出實心的小茶壺

    glutSwapBuffers();///交換顯示出來
}
int main(int argc, char *argv[]){///厲害的main()函式
    glutInit(&argc, argv);///要開始GLUT的功能
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///設定GLUT的顯示模式
    glutCreateWindow("week02");///建一個窗字
    glutDisplayFunc(display);///要顯示的函式
    glutMainLoop();///主要迴圈卡最後面
}
