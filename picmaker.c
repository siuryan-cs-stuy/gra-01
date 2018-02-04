#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>

#define WIDTH 500
#define HEIGHT 500
#define MAX_RGB 255.0
#define MIN_RGB 0.0

int main() {
    int fd = open("pic.ppm", O_WRONLY | O_TRUNC | O_CREAT, 0644);
    char init[50];
    sprintf(init, "P3\n%d %d\n%d\n", WIDTH, HEIGHT, (int)MAX_RGB);
    write(fd, init, strlen(init));

    int i, j;
    double r = MIN_RGB + 1;
    double g = MAX_RGB;
    double b = MIN_RGB + 1;

    char buffer[10000];
    strcpy(buffer, "");

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            char rgb[10];

            sprintf(rgb, "%d %d %d  ", (int)r % 255, (int)g % 255, (int)b % 255);
            strcat(buffer, rgb);

            r *= 1.02;
            b *= 1.00007;
        }

        strcat(buffer, "\n");
        write(fd, buffer, strlen(buffer));

        r = MIN_RGB + 1;
        g /= 1.005;
        strcpy(buffer, "");
    }

    close(fd);
}
