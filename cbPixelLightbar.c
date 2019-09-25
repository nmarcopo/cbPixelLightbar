/**
 *
 * cbPixelLightbar.c
 * Written by Nicholas Marcopoli (git.io/nmarcopo)
 * Licensed under MIT License
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>

#define KEY_PRESS 1

int main(){
    int fd;
    // event3 corresponds to the keyboard
    if ((fd = open("/dev/input/event3", O_RDONLY)) < 0) {
        perror("Couldn't open input device\n");
        return 1;
    }

    char lightCommand[BUFSIZ];
    struct input_event ie;
    while (1) {
        if(read(fd, &ie, sizeof(ie)) < 0){
            fprintf(stderr, "Error reading input\n");
            return 1;
        }

        if (ie.value == KEY_PRESS) {
            // build lightbar command that randomly assigns a color to the lightbar.
            // color lasts ~1 second
            snprintf(lightCommand, BUFSIZ, "sudo ectool lightbar 4 %X %X %X\n",
                random() % 255, random() % 255, random() % 255);
            if(system(lightCommand)){
                fprintf(stderr, "Error changing lightbar color.\n");
                return 1;
            }
        }
    }
}
