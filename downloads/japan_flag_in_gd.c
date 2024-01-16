// 使用標準輸入/輸出函數
#include <stdio.h>
// 繪製gd函式庫
#include <gd.h>

// void因不會回傳任何值而用於紀錄所需的各項指令及參數
void draw_japan_flag(gdImagePtr img);

int main() {
    // 設定國旗寬高比為2:3
    int width = 1200;
    int height = (int)(width * 2.0 / 3.0);

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    draw_japan_flag(img);

    FILE *outputFile = fopen("./../images/japan_flag_in_gd.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }
    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);
    return 0;
}

void draw_japan_flag(gdImagePtr img) {
    int width = gdImageSX(img);
    int height = gdImageSY(img);
    int red, white;

    // 設定顏色
    red = gdImageColorAllocate(img, 242, 0, 0);  // 日本紅
    white = gdImageColorAllocate(img, 255, 255, 255); // 白色

    // 在整個畫布上繪製白色矩形
    gdImageFilledRectangle(img, 0, 0, width, height, white);

    // 繪製紅色圓
   int circle_radius = width / 5;
   int circle_x = width / 2;
   int circle_y = height / 2;
    gdImageFilledEllipse(img, circle_x, circle_y, circle_radius, circle_radius, red);
}