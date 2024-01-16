// 使用標準輸入/輸出函數
#include <stdio.h>
// 繪製gd函式庫
#include <gd.h>
// 繪製數學函數庫
#include <math.h>

// void因不會回傳任何值而用於紀錄所需的各項指令及參數
void draw_roc_flag(gdImagePtr img);
void draw_white_sun(gdImagePtr img, int x, int y, int size, int color);

int main() {
    // width 3: height 2
    int width = 1200;
    int height = (int)(width*2.0 / 3.0);

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    draw_roc_flag(img);

    FILE *outputFile = fopen("./../images/roc_flag1.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }
    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);
    return 0;
}

void draw_roc_flag(gdImagePtr img) {
    int width = gdImageSX(img);
    int height = gdImageSY(img);
    int red, white, blue;
    int center_x = (int)(width/4);
    int center_y = (int)(height/4);
    int sun_radius = (int)(width/8);
    // Colors for the flag
    red = gdImageColorAllocate(img, 242, 0, 0); // Red color
    white = gdImageColorAllocate(img, 255, 255, 255); // White stripes
    blue = gdImageColorAllocate(img, 0, 41, 204); // Blue
    // red rectangle area
    gdImageFilledRectangle(img, 0, 0, width, height, red);
    // blue rectangle area
    gdImageFilledRectangle(img, 0, 0, (int)(width/2.0), (int)(height/2.0), blue);
    // 目前僅畫出青天白日的輪廓直線, 請嘗試計算所需的點座標完成國旗繪圖
    draw_white_sun(img, center_x, center_y, sun_radius, white);
}

void draw_white_sun(gdImagePtr img, int center_x, int center_y, int sun_radius, int color) {
    float angle = 0;
    int fromX, fromY;
    int toX, toY;
    for (int i=0; i<24; i++){
        angle += 5*M_PI*2/12;
        //printf("%.3f", angle);
        toX = center_x + cos(angle)*sun_radius;
        toY = center_y + sin(angle)*sun_radius;
        // 只有 i 為 0 時移動到 toX, toY, 其餘都進行直線繪圖
        if (i!=0){
            gdImageLine(img, fromX, fromY, toX, toY, color);
        }
        fromX = toX;
        fromY = toY;
   }
}