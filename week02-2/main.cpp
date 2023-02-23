#include <GL/glut.h>

void display(){///用小畫家寫程式
    glBegin(GL_POLYGON);
        glVertex2f((455-100)/100.0, -(64-100)/100.0);
        glVertex2f((291-100)/100.0, -(268-100)/100.0);
        glVertex2f((139-100)/100.0, -(198-100)/100.0);
        glVertex2f((223-100)/100.0, -(351-100)/100.0);
        glVertex2f((268-100)/100.0, -(582-100)/100.0);
        glVertex2f((341-100)/100.0, -(530-100)/100.0);
        glVertex2f((437-100)/100.0, -(597-100)/100.0);
        glVertex2f((510-100)/100.0, -(367-100)/100.0);
        glVertex2f((622-100)/100.0, -(207-100)/100.0);
        glVertex2f((466-100)/100.0, -(281-100)/100.0);
        ///先減一半 再除一半 y變負號
        ///0...200 => -100...+100 => -1.0 +1.0
    glEnd();

    glutSwapBuffers();///交換顯示出來
}
int main(int argc, char *argv[]){///厲害的main()函式
    glutInit(&argc, argv);///要開始GLUT的功能
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///設定GLUT的顯示模式
    glutCreateWindow("week02");///建一個窗字
    glutDisplayFunc(display);///要顯示的函式
    glutMainLoop();///主要迴圈卡最後面
}

