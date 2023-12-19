#include <stdio.h>
#include <gd.h>
#include <math.h>

void draw_china_flag(gdImagePtr img);
void draw_five_stars(gdImagePtr img, int x, int y, int size, int color);
void draw_one_star(gdImagePtr img, int x, int y, int size, int color);

int main() {
    // 設定國旗寬高比為3:2
    int width = 1200;
    int height = (int)(width * 2.0 / 3.0);

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    draw_china_flag(img);

    FILE *outputFile = fopen("./../images/china_flag_in_gd.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }
    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);
    return 0;
}

void draw_china_flag(gdImagePtr img) {
    int width = gdImageSX(img);
    int height = gdImageSY(img);
    int red, yellow;

    // 設定顏色
    red = gdImageColorAllocate(img, 206, 17, 38);  // 中國紅
    yellow = gdImageColorAllocate(img, 255, 223, 0); // 中國黃

    // 繪製紅色底色
    gdImageFilledRectangle(img, 0, 0, width, height, red);

    // 計算五星的位置
    int x1 = width / 30;
    int y1 = height / 5;
    int x2 = x1 + width / 5;
    int y2 = y1;
    int x3 = x1 + width / 15;
    int y3 = y1 + height / 10;
    int x4 = x1 + width / 10;
    int y4 = y1 + height / 5;
    int x5 = x1;
    int y5 = y1 + height / 5;

    // 繪製五星
    draw_five_stars(img, x1, y1, width / 30, yellow);
    draw_five_stars(img, x2, y2, width / 30, yellow);
    draw_five_stars(img, x3, y3, width / 30, yellow);
    draw_five_stars(img, x4, y4, width / 30, yellow);
    draw_five_stars(img, x5, y5, width / 30, yellow);
}

void draw_five_stars(gdImagePtr img, int x, int y, int size, int color) {
    int star_size = size * 1.2;
    draw_one_star(img, x, y, star_size, color);

    int offset_x = size * 3;
    int offset_y = size * 3;
    draw_one_star(img, x + offset_x, y + offset_y, star_size, color);
}

void draw_one_star(gdImagePtr img, int x, int y, int size, int color) {
    gdPoint points[10];

    // 計算十個頂點的座標
    for (int i = 0; i < 10; i++) {
        int angle = i % 2 == 0 ? 18 * i : 18 * i + 36;
        points[i].x = x + size * cos(angle * M_PI / 180);
        points[i].y = y + size * sin(angle * M_PI / 180);
    }

    // 繪製五角星
    gdImageFilledPolygon(img, points, 10, color);
}