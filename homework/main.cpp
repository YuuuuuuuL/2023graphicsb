
#include <GL/glut.h>
#include <math.h>
void myCircle(float r, float x, float y){///用小畫家寫程式
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

    glutSwapBuffers();///交換顯示出來
}
int main(int argc, char *argv[]){///厲害的main()函式
    glutInit(&argc, argv);///要開始GLUT的功能
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///設定GLUT的顯示模式
    glutCreateWindow("week02");///建一個窗字
    glutDisplayFunc(display);///要顯示的函式
    glutMainLoop();///主要迴圈卡最後面
}
