#include <stdio.h>
#include <gd.h>
#include <math.h>

void draw_roc_flag(gdImagePtr img);
void draw_white_sun(gdImagePtr img, int x, int y, int size, int color);
void find_intersection(int x1, int y1, int x2, int y2, int cx, int cy, int cr);

int main() {
    // Your existing code here

    int width = 1200;
    int height = (int)(width * 2.0 / 3.0);
    int center_x = (int)(width / 4);
    int center_y = (int)(height / 4);
    int sun_radius = (int)(width / 8);
    int white_circle_dia = sun_radius;
    int blue_circle_dia = white_circle_dia + white_circle_dia * 2 / 15;

    find_intersection(375, 70, 264, 179, center_x, center_y, blue_circle_dia / 2);
    find_intersection(264, 179, 224, 329, center_x, center_y, blue_circle_dia / 2);
    find_intersection(224, 329, 224, 329, center_x, center_y, blue_circle_dia / 2);
    find_intersection(224, 329, 375, 70, center_x, center_y, blue_circle_dia / 2);

    // Your existing code here

    return 0;
}

void draw_roc_flag(gdImagePtr img) {
    // Your existing code here
}

void draw_white_sun(gdImagePtr img, int center_x, int center_y, int sun_radius, int color) {
    // Your existing code here
}

void find_intersection(int x1, int y1, int x2, int y2, int cx, int cy, int cr) {
    float m, c, A, B, C, det, t;

    m = (float)(y2 - y1) / (x2 - x1);

    c = y1 - m * x1;

    A = 1 + m * m;
    B = -2 * cx + 2 * m * (c - cy);
    C = cx * cx + (c - cy) * (c - cy) - cr * cr;

    det = B * B - 4 * A * C;

    if (det >= 0) {
        t = (-B + sqrt(det)) / (2 * A);
        int x = x1 + t * (x2 - x1);
        int y = y1 + t * (y2 - y1);
        printf("Intersection point: (%d, %d)\n", x, y);
    }

    t = (-B - sqrt(det)) / (2 * A);
    int x = x1 + t * (x2 - x1);
    int y = y1 + t * (y2 - y1);
    printf("Intersection point: (%d, %d)\n", x, y);
}