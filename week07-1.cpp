#include <opencv/highgui.h>
int main(){
                        ///���ɭn��b�ୱ���ؿ�
    IplImage * img = cvLoadImage("image.jpg");
    cvShowImage("week07", img);
    cvWaitKey(0);///�e�����{�h �ץ��N���~��
}
