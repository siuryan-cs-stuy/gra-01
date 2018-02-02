#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>

#define WIDTH 500
#define HEIGHT 500
#define MAX_RGB 256.0
#define MIN_RGB 0.0

int main() {
    int fd = open("pic.ppm", O_WRONLY | O_TRUNC | O_CREAT, 0644);
    write(fd, "P3\n500 500\n255\n", 20);

    int i, j;
    double r = MIN_RGB;
    double g = MIN_RGB;
    double b = MAX_RGB / 2;

    char buffer[10000];
    strcpy(buffer, "");

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            char rgb[10];

            sprintf(rgb, "%d %d %d  ", (int)r, (int)g, (int)b);
            strcat(buffer, rgb);

            r += MAX_RGB / WIDTH;
        }

        strcat(buffer, "\n");
        write(fd, buffer, strlen(buffer));

        r = MIN_RGB;
        g += MAX_RGB / HEIGHT;
        strcpy(buffer, "");
    }

    close(fd);
}