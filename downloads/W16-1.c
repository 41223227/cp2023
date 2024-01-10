#include <gd.h>
#include <stdio.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define SCALE 100

void drawResistor(gdImagePtr im, int x1, int y, int width, int height) {
    int startX = x1 ;
    int endX = x1 + width ;

    // 第一段直线向前走一段
    gdImageLine(im, startX, y, startX + width / 4 , y, gdImageColorAllocate(im, 0, 0, 255));

    // 向上45度
    gdImageLine(im, startX + width / 4 , y, startX + width / 4 + height / 2 , y - height / 2, gdImageColorAllocate(im, 0, 0, 255));

    // 向下90度
    gdImageLine(im, startX + width / 4 + height / 2, y - height / 2 , startX + width / 4 + height / 2 + height , y + height / 2, gdImageColorAllocate(im, 0, 0, 255));

    // 向上90度
    gdImageLine(im, startX + width / 4 + height / 2 + height, y + height / 2, startX + width / 4 + height / 2 + 2 * height, y - height / 2, gdImageColorAllocate(im, 0, 0, 255));

    // 向下90度
    gdImageLine(im, startX + width / 4 + height / 2 + 2 * height , y - height / 2, startX + width / 4 + height / 2 + 3 * height , y + height / 2, gdImageColorAllocate(im, 0, 0, 255));

    // 向上90度
    gdImageLine(im, startX + width / 4 + height / 2 + 3 * height, y + height / 2 , startX + width / 4 + height / 2 + 4 * height, y - height / 2, gdImageColorAllocate(im, 0, 0, 255));

    // 向下90度
    gdImageLine(im, startX + width / 4 + height / 2 + 4 * height, y - height / 2, startX + width / 4 + height / 2 + 5 * height, y + height / 2, gdImageColorAllocate(im, 0, 0, 255));

  // 向上45度
    gdImageLine(im, startX + width / 4 + height / 2 + 5 * height, y + height / 2, startX + width / 4 + height / 2 + 5 * height + height / 2, y, gdImageColorAllocate(im, 0, 0, 255));

  gdImageLine(im, startX + width / 4 + height / 2 + 5 * height + height / 2, y, startX + width / 4 + height / 2 + 5 * height + height / 2 +5 , y, gdImageColorAllocate(im, 0, 0, 255));


  {
    int startX = 100;
  gdImageColorAllocate(im, 0, 0, 255);


    // 第一段直线向前走一段
    gdImageLine(im, startX, y, startX + width / 4 , y, gdImageColorAllocate(im, 0, 0, 255));

    // 向上45度
    gdImageLine(im, startX + width / 4 , y, startX + width / 4 + height / 2 , y - height / 2, gdImageColorAllocate(im, 0, 0, 255));

    // 向下90度
    gdImageLine(im, startX + width / 4 + height / 2, y - height / 2 , startX + width / 4 + height / 2 + height , y + height / 2, gdImageColorAllocate(im, 0, 0, 255));

    // 向上90度
    gdImageLine(im, startX + width / 4 + height / 2 + height, y + height / 2, startX + width / 4 + height / 2 + 2 * height, y - height / 2, gdImageColorAllocate(im, 0, 0, 255));

    // 向下90度
    gdImageLine(im, startX + width / 4 + height / 2 + 2 * height , y - height / 2, startX + width / 4 + height / 2 + 3 * height , y + height / 2, gdImageColorAllocate(im, 0, 0, 255));

    // 向上45度
      gdImageLine(im, startX + width / 4 + height / 2 + 3 * height, y + height / 2, startX + width / 4 + height / 2 + 3 * height + height / 2, y, gdImageColorAllocate(im, 0, 0, 255));

    gdImageLine(im, startX + width / 4 + height / 2 + 3 * height + height / 2, y, startX + width / 4 + height / 2 + 3 * height + height / 2 +5 , y, gdImageColorAllocate(im, 0, 0, 255));
 }

  {
    int startX = 585;
  gdImageColorAllocate(im, 0, 0, 255);


    // 第一段直线向前走一段
    gdImageLine(im, startX, y, startX + width / 4 , y, gdImageColorAllocate(im, 0, 0, 255));

    // 向上45度
    gdImageLine(im, startX + width / 4 , y, startX + width / 4 + height / 2 , y - height / 2, gdImageColorAllocate(im, 0, 0, 255));

  // 向下90度
    gdImageLine(im, startX + width / 4 + height / 2, y - height / 2 , startX + width / 4 + height / 2 + height , y + height / 2, gdImageColorAllocate(im, 0, 0, 255));

    // 向上90度
    gdImageLine(im, startX + width / 4 + height / 2 + height, y + height / 2, startX + width / 4 + height / 2 + 2 * height, y - height / 2, gdImageColorAllocate(im, 0, 0, 255));
        // 向下90度
    gdImageLine(im, startX + width / 4 + height / 2 + 2 * height , y - height / 2, startX + width / 4 + height / 2 + 3 * height , y + height / 2, gdImageColorAllocate(im, 0, 0, 255));

    // 向上45度
      gdImageLine(im, startX + width / 4 + height / 2 + 3 * height, y + height / 2, startX + width / 4 + height / 2 + 3 * height + height / 2, y, gdImageColorAllocate(im, 0, 0, 255));

    gdImageLine(im, startX + width / 4 + height / 2 + 3 * height + height / 2, y, startX + width / 4 + height / 2 + 3 * height + height / 2 +5 , y, gdImageColorAllocate(im, 0, 0, 255));

    gdImageLine(im, 100, y +20, 700, y +20, gdImageColorAllocate(im, 0, 255, 0));

}
}

int main() {
    gdImagePtr im;
    FILE *outputFile;

    // 创建图像对象
    im = gdImageCreateTrueColor(WIDTH, HEIGHT);
    if (im == NULL) {
        fprintf(stderr, "Error creating GD image.\n");
        return 1;
    }

    outputFile = fopen("1.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }

    int black, white, red, blue, green;

    black = gdImageColorAllocate(im, 0, 0, 0);
    white = gdImageColorAllocate(im, 255, 255, 255);
    red = gdImageColorAllocate(im, 255, 0, 0);
    blue = gdImageColorAllocate(im, 0, 0, 255);
green = gdImageColorAllocate(im, 0, 255, 0);
    gdImageFilledRectangle(im, 0, 0, WIDTH - 1, HEIGHT - 1, white);

    // 绘制墙面
    gdImageLine(im, SCALE, SCALE, SCALE, HEIGHT - SCALE, black);
    gdImageLine(im, WIDTH - SCALE, SCALE, WIDTH - SCALE, HEIGHT - SCALE, black);

// 绘制彈簧
    drawResistor(im, WIDTH / 3 + SCALE / 2, HEIGHT / 2, SCALE / 2, SCALE / 4);

    // 绘制质量（方形）
    gdImageFilledRectangle(im, WIDTH / 3 - SCALE / 2, HEIGHT / 2 - SCALE / 2, WIDTH / 3 + SCALE / 2, HEIGHT / 2 + SCALE / 2, red);
    gdImageFilledRectangle(im, WIDTH * 2 / 3 - SCALE / 2, HEIGHT / 2 - SCALE / 2, WIDTH * 2 / 3 + SCALE / 2, HEIGHT / 2 + SCALE / 2, red);

  gdImageFilledRectangle(im, 100, HEIGHT +300, 700, HEIGHT /2 +49 , black);



    gdImagePng(im, outputFile);
    fclose(outputFile);
    gdImageDestroy(im);

    return 0;
}