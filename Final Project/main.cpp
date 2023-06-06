#include <stdio.h>
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"

GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * eyes = NULL;
GLMmodel * mouth = NULL;
GLMmodel * lufoot = NULL, * ldfoot = NULL;
GLMmodel * rufoot = NULL, * rdfoot = NULL;
GLMmodel * lhair = NULL, * rhair = NULL;
GLMmodel * lhand = NULL, * rhand = NULL;
GLMmodel * ltail = NULL, * rtail = NULL, * tail = NULL;

float teapotX = 0, teapotY = 0, oldX = 0, oldY = 0;
float angle[20] = {}, angle2[20] = {};///float angle = 0, angle2 = 0;
float NewAngle[20] = {}, NewAngle2[20] = {};
float OldAngle[20] = {}, OldAngle2[20] = {};
int ID = 0;

FILE * fout = NULL;
FILE * fin = NULL;

void timer(int t) {
    printf("現在timer(%d)\n", t);
    glutTimerFunc(20, timer, t+1); ///馬上設定下一個鬧鐘

    float alpha = (t%50) / 50.0; ///0.0 ~ 1.0

    if(t%50==0){
        if(fin == NULL) fin = fopen("motion.txt", "r");
        for(int i=0; i<20; i++){
            OldAngle[i] = NewAngle[i];
            OldAngle2[i] = NewAngle2[i];
            fscanf(fin, "%f", &NewAngle[i] );
            fscanf(fin, "%f", &NewAngle2[i] );
        }
    }
    for(int i=0; i<20; i++){
        angle[i] = NewAngle[i] * alpha + OldAngle[i] * (1-alpha);
        angle2[i] = NewAngle2[i] * alpha + OldAngle2[i] * (1-alpha);
    }

    glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y) {
    if(key=='0') ID = 0;
    if(key=='1') ID = 1;
    if(key=='2') ID = 2;
    if(key=='3') ID = 3;
    if(key=='4') ID = 4;
    if(key=='5') ID = 5;
    if(key=='6') ID = 6;
    if(key=='7') ID = 7;
    if(key=='8') ID = 8;
    if(key=='9') ID = 9;
    if(key=='q') ID = 10;
    if(key=='w') ID = 11;
    if(key=='e') ID = 12;
    if(key=='s'){ ///Save
        if(fout == NULL) fout = fopen("motion.txt", "w");
        for(int i=0; i<20; i++){
            fprintf(fout, "%.2f ", angle[i] );
            fprintf(fout, "%.2f ", angle2[i] );
        }
        fprintf(fout, "\n");
        printf("寫了一行\n");
    }
    if(key=='r'){ ///Read
        if(fin == NULL) fin = fopen("motion.txt", "r");
        for(int i=0; i<20; i++){
            fscanf(fin, "%f", &angle[i] );
            fscanf(fin, "%f", &angle2[i] );
        }
        glutPostRedisplay();
    }
    if(key=='p'){ ///Play
        glutTimerFunc(0, timer, 0);
    }
}


int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename);
    cvCvtColor(img,img, CV_BGR2RGB);
    glEnable(GL_TEXTURE_2D);
    GLuint id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}
void motion(int x, int y) {
    teapotX += (x - oldX) / 150.0 * 10; ///teapotX = (x-150)/150.0;
    teapotY += (oldY - y) / 150.0 * 10; ///teapotY = (150-y)/150.0;
    angle[ID] += x - oldX;
    angle2[ID] += oldY - y;
    oldX = x;
    oldY = y;
    glutPostRedisplay();
    printf("  glTranslatef( %.2f, %.2f, 0 ); \n", teapotX, teapotY );
}
int id1, id2;
void display() {///glTranslatef(teapotX, teapotY, 0);

        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glBindTexture(GL_TEXTURE_2D, id2);

        glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex2f(-1, +1);
        glTexCoord2f(1, 0); glVertex2f(+1, +1);
        glTexCoord2f(1, 1); glVertex2f(+1, -1);
        glTexCoord2f(0, 1); glVertex2f(-1, -1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, id1);
        glPushMatrix();///身體
            glScalef(1, 1, 1);
            glPushMatrix();
            glColor3f(1,1,1);
            glScalef(0.04, 0.04, 0.04);
            glTranslatef(0.00, 0.00, -10);
            glRotatef(angle[0], 0, 1, 0); ///身體的轉動
            glmDraw(body, GLM_MATERIAL|GLM_TEXTURE);

        glPushMatrix();///中尾
                glColor3f(1,1,1);
                glTranslatef( -0.33, 0.53, 0 );
                glRotatef(angle[10], 0, 0, 1);
                glRotatef(angle2[10], 0, 0, 1);
                glTranslatef( 0.33, -0.53, 0 );
                ///glTranslatef(teapotX, teapotY, 0);
                glmDraw(tail, GLM_MATERIAL|GLM_TEXTURE);

                glPushMatrix();///左尾
                        glTranslatef( 0.07, 0.33, 0 );
                        glRotatef(angle[11], 0, 0, 1);
                        glRotatef(angle2[11], 0, 0, 1);
                         glTranslatef( -0.07, -0.33, 0 );
                        ///glTranslatef(teapotX, teapotY, 0);
                        glmDraw(ltail, GLM_MATERIAL|GLM_TEXTURE);
                glPopMatrix();
                glPushMatrix();///右尾
                        glTranslatef( -1.07, 0.87, 0 );
                        glRotatef(angle[12], 0, 0, 1);
                        glRotatef(angle2[12], 0, 0, 1);
                        glTranslatef( 1.07, -0.87, 0 );
                        ///glTranslatef(teapotX, teapotY, 0);
                        glmDraw(rtail, GLM_MATERIAL|GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();

        glPushMatrix();///左手
                glColor3f(1, 1, 0);
                glTranslatef( 1.07, 4.13, 0 );
                glRotatef(angle[1], 0, 1, 0);
                glRotatef(angle2[1], 1, 0, 0);
                glTranslatef( -1.07, -4.13, 0 );
                glmDraw(lhand, GLM_MATERIAL|GLM_TEXTURE);
        glPopMatrix();


        glPushMatrix();///右手
                glColor3f(1, 1, 0);
                glTranslatef( -1.67, 4.40, 0 );
                glRotatef(angle[2], 0, 1, 0);
                glRotatef(angle2[2], 1, 0, 0);
                glTranslatef( 1.67, -4.40, 0 );
                ///glTranslatef(teapotX, teapotY, 0);
                glmDraw(rhand, GLM_MATERIAL|GLM_TEXTURE);
        glPopMatrix();


        glPushMatrix();///左上腳
                glTranslatef( 1.13, 0.33, 0 );
                glRotatef(angle[3], 0, 1, 0);
                glRotatef(angle2[3], 1, 0, 0);
                glTranslatef( -1.13, -0.33, 0 );
                ///glTranslatef(teapotX, teapotY, 0);
                glmDraw(lufoot, GLM_MATERIAL|GLM_TEXTURE);

                glPushMatrix();///左下腳
                    glTranslatef( 1.13, -2.93, 0 );
                    glRotatef(angle[4], 0, 1, 0);
                    glRotatef(angle2[4], 1, 0, 0);
                    glTranslatef( -1.13, 2.93, 0 );
                    ///glTranslatef(teapotX, teapotY, 0);
                    glmDraw(ldfoot, GLM_MATERIAL|GLM_TEXTURE);
                glPopMatrix();
        glPopMatrix();

        glPushMatrix();///右上腳
                glTranslatef( -1.67, 0.33, 0 );
                glRotatef(angle[5], 0, 1, 0);
                glRotatef(angle2[5], 1, 0, 0);
                glTranslatef( 1.67, -0.33, 0 );
                ///glTranslatef(teapotX, teapotY, 0);
                glmDraw(rufoot, GLM_MATERIAL|GLM_TEXTURE);

                glPushMatrix();///右下腳
                    glTranslatef( -1.83, -2.93, 0 );
                    glRotatef(angle[6], 0, 1, 0);
                    glRotatef(angle2[6], 1, 0, 0);
                    glTranslatef( 1.83, 2.93, 0 );
                    ///glTranslatef(teapotX, teapotY, 0);
                    glmDraw(rdfoot, GLM_MATERIAL|GLM_TEXTURE);
                glPopMatrix();
        glPopMatrix();


        glPushMatrix();///頭
                glColor3f(1, 1, 1);
                glTranslatef(-0.00, +22.53, 0 );
                glRotatef(angle[7], 0, 1, 0);
                glTranslatef( 0.00, -22.53, 0 );
                ///glTranslatef(teapotX, teapotY, 0);
                glmDraw(head, GLM_MATERIAL|GLM_TEXTURE);

            glPushMatrix();///眼睛
                glColor3f(0, 0, 0);
                glmDraw(eyes, GLM_MATERIAL|GLM_TEXTURE);
            glPopMatrix();

            glPushMatrix();///嘴巴
                glColor3f(1, 1, 0);
                glmDraw(mouth, GLM_MATERIAL|GLM_TEXTURE);
            glPopMatrix();

            glPushMatrix();///右髮
                glColor3f(1, 0, 0);
                glTranslatef( -0.33, 12.27, 0 );
                glRotatef(angle[8], 0, 1, 0);
                glRotatef(angle2[8], 1, 0, 0);
                glTranslatef( 0.33, -12.27, 0 );
                ///glTranslatef(teapotX, teapotY, 0);
                glmDraw(rhair, GLM_MATERIAL|GLM_TEXTURE);

                glPushMatrix();///左髮
                        glTranslatef( -0.33, 12.33, 0 );
                        glRotatef(angle[9], 0, 1, 0);
                        glRotatef(angle2[9], 1, 0, 0);
                         glTranslatef( 0.33, -12.33, 0 );
                        ///glTranslatef(teapotX, teapotY, 0);
                        glmDraw(lhair, GLM_MATERIAL|GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
        glColor3f(1, 1, 1);
    glPopMatrix();
    glPopMatrix();


    glutSwapBuffers();

}



int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week16");
        PlaySound("C:\\Users\\88696\\Desktop\\2023graphicsb\\Final Project\\Boombayah.wav", NULL, SND_ASYNC);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);



        head = glmReadOBJ("model/head.obj");
        body = glmReadOBJ("model/body.obj");
        eyes = glmReadOBJ("model/eyes.obj");
        mouth = glmReadOBJ("model/mouth.obj");
        lufoot = glmReadOBJ("model/lufoot.obj");
        ldfoot = glmReadOBJ("model/ldfoot.obj");
        rufoot = glmReadOBJ("model/rufoot.obj");
        rdfoot = glmReadOBJ("model/rdfoot.obj");
        lhair = glmReadOBJ("model/lhair.obj");
        rhair = glmReadOBJ("model/rhair.obj");
        lhand = glmReadOBJ("model/lhand.obj");
        rhand = glmReadOBJ("model/rhand.obj");
        ltail = glmReadOBJ("model/ltail.obj");
        tail = glmReadOBJ("model/tail.obj");
        rtail = glmReadOBJ("model/rtail.obj");

    id1 = myTexture("model/Diffuse.jpg");
    id2 = myTexture("model/pi.jpg");
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();

}



