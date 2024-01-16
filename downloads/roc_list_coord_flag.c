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
    // 國旗長寬比為 3:2
    int height = (int)(width*2.0 / 3.0);

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    draw_roc_flag(img);

    FILE *outputFile = fopen("roc_list_coord_flag.png", "wb");
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
    int center_x = (int)(width / 4);
    int center_y = (int)(height / 4);
    int sun_radius = (int)(width / 8);
    int white_circle_dia = sun_radius;
    int blue_circle_dia = white_circle_dia + white_circle_dia * 2 / 15;
    red = gdImageColorAllocate(img, 255, 0, 0);// 紅色
    white = gdImageColorAllocate(img, 255, 255, 255);// 白色
    blue = gdImageColorAllocate(img, 0, 0, 149);// 藍色
    gdImageFilledRectangle(img, 0, 0, width, height, red);
    gdImageFilledRectangle(img, 0, 0, (int)(width / 2.0), (int)(height / 2.0), blue);
    draw_white_sun(img, center_x, center_y, sun_radius, white);
    gdImageFilledEllipse(img, center_x, center_y, blue_circle_dia, blue_circle_dia, blue);
    gdImageFilledEllipse(img, center_x, center_y, white_circle_dia, white_circle_dia, white);

  // 第二組 ABED 四個點的座標
  int ax2, ay2, bx2, by2, ex2, ey2, dx2, dy2;
  gdPoint points2[4];

  ax2 = 375;
  ay2 = 70;
  bx2 = 264;
  by2 = 179;
  ex2 = 224;
  ey2 = 329;
  dx2 = 224;
  dy2 = 329;

  // 連接第二組 ABED 四個點的座標
  gdImageLine(img, ax2, ay2, bx2, by2, white);
  gdImageLine(img, bx2, by2, ex2, ey2, white);
  gdImageLine(img, ex2, ey2, dx2, dy2, white);
  gdImageLine(img, dx2, dy2, ax2, ay2, white);

}

  void draw_white_sun(gdImagePtr img, int center_x, int center_y, int sun_radius, int color) {
      float deg = M_PI/180;
      float sr = sun_radius/tan(75*deg);
      int ax, ay, bx, by, dx, dy, ex, ey;
      gdPoint points[4];

      ax = center_x;
      ay = center_y - sun_radius;
      bx = center_x - sun_radius*tan(15*deg);
      by = center_y;
      ex = center_x;
      ey = center_y + sun_radius;
      dx = center_x + sun_radius*tan(15*deg);
      dy = center_y;

      // 連接第二組 ABED 四個點的座標
      gdImageLine(img, ax, ay, bx, by, color);
      gdImageLine(img, bx, by, ex, ey, color);
      gdImageLine(img, ex, ey, dx, dy, color);
      gdImageLine(img, dx, dy, ax, ay, color);
  }
  