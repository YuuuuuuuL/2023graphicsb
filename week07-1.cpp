#include <opencv/highgui.h>
int main(){
                        ///圖檔要放在桌面的目錄
    IplImage * img = cvLoadImage("image.jpg");
    cvShowImage("week07", img);
    cvWaitKey(0);///畫面不閃退 案任意鍵繼續
}
