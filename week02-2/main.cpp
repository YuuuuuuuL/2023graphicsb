#include <GL/glut.h>

void display(){///�Τp�e�a�g�{��
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
        ///����@�b �A���@�b y�ܭt��
        ///0...200 => -100...+100 => -1.0 +1.0
    glEnd();

    glutSwapBuffers();///�洫��ܥX��
}
int main(int argc, char *argv[]){///�F�`��main()�禡
    glutInit(&argc, argv);///�n�}�lGLUT���\��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///�]�wGLUT����ܼҦ�
    glutCreateWindow("week02");///�ؤ@�ӵ��r
    glutDisplayFunc(display);///�n��ܪ��禡
    glutMainLoop();///�D�n�j��d�̫᭱
}

