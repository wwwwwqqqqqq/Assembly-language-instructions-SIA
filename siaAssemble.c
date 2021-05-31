//
//  siaAssemble.c
//  Assignment2
//
//  Created by Weiwei Qin on 2020/4/23.
//  Copyright © 2020 Qin Weiwei. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ltrim(char *s) {
    while (*s == ' ' || *s == '\t') s++;
    return s;
}

char getRegister(char *text) {
    if (*text == 'r' || *text=='R') text++;
    return atoi(text);
}

int assembleLine(char *text, unsigned char* bytes) {
    text = ltrim(text);
    char *keyWord = strtok(text," ");

    /*
    “3R” instructions
    */
    if (strcmp("add",keyWord) == 0) {
        bytes[0] = 0x10;
        bytes[0] |= getRegister(strtok(NULL," "));
        bytes[1] = getRegister(strtok(NULL," ")) << 4 | getRegister(strtok(NULL," "));
        return 2;
    }
    if (strcmp("and",keyWord) == 0){
        bytes[0] = 0x20;
        bytes[0] |= getRegister(strtok(NULL," "));
        bytes[1] = getRegister(strtok(NULL," ")) << 4 | getRegister(strtok(NULL," "));
        return 2;
    }
    if (strcmp("divide",keyWord) == 0) {
        bytes[0] = 0x30;
        bytes[0] |= getRegister(strtok(NULL," "));
        bytes[1] = getRegister(strtok(NULL," ")) << 4 | getRegister(strtok(NULL," "));
        return 2;
    }
    if (strcmp("halt",keyWord) == 0) {
        bytes[0] = 0x00;
        bytes[0] |= getRegister(strtok(NULL," "));
        bytes[1] = getRegister(strtok(NULL," ")) << 4 | getRegister(strtok(NULL," "));
        return 2;
    }
    if (strcmp("multiply",keyWord) == 0) {
        bytes[0] = 0x40;
        bytes[0] |= getRegister(strtok(NULL," "));
        bytes[1] = getRegister(strtok(NULL," ")) << 4 | getRegister(strtok(NULL," "));
        return 2;
    }
    if (strcmp("or",keyWord) == 0) {
        bytes[0] = 0x60;
        bytes[0] |= getRegister(strtok(NULL," "));
        bytes[1] = getRegister(strtok(NULL," ")) << 4 | getRegister(strtok(NULL," "));
        return 2;
    }
    if (strcmp("subtract",keyWord) == 0) {
        bytes[0] = 0x50;
        bytes[0] |= getRegister(strtok(NULL," "));
        bytes[1] = getRegister(strtok(NULL," ")) << 4 | getRegister(strtok(NULL," "));
        return 2;
    }

    /*
    Branch instructions
    */
    if (strcmp("branchIfLess",keyWord) == 0) {
        int x;
        bytes[0] = 0x70;
        bytes[1] = getRegister(strtok(NULL," ")) << 4 | getRegister(strtok(NULL," "));
        x = atoi(strtok(NULL," "));
        bytes[2] = x << 8;
        bytes[3] = x;
        /*
        int x,y;
        bytes[0] = 0x71;
        bytes[0] |= getRegister(strtok(NULL," "));
        bytes[1] = getRegister(strtok(NULL," ")) << 4;
        x = atoi(strtok(NULL," "));
        y = x >> 16;
        y &= 0x0F;
        bytes[1] |= y;
        bytes[2] = (x >> 8) & 0xFF;
        bytes[3] = x & 0xFF;
        */
        return 4;
    }
    if (strcmp("branchIfLessOrEqual",keyWord) == 0) {
        int x;
        bytes[0] = 0x71;
        bytes[1] = getRegister(strtok(NULL," ")) << 4 | getRegister(strtok(NULL," "));
        x = atoi(strtok(NULL," "));
        bytes[2] = x << 8;
        bytes[3] = x;
        /*
        int x,y;
        bytes[0] = 0x71;
        bytes[0] |= getRegister(strtok(NULL," "));
        bytes[1] = getRegister(strtok(NULL," ")) << 4;
        x = atoi(strtok(NULL," "));
        y = x >> 16;
        y &= 0x0F;
        bytes[1] |= y;
        bytes[2] = (x >> 8) & 0xFF;
        bytes[3] = x & 0xFF;
        */
        return 4;
    }
    if (strcmp("branchIfEqual",keyWord) == 0) {
        int x;
        bytes[0] = 0x72;
        bytes[1] = getRegister(strtok(NULL," ")) << 4 | getRegister(strtok(NULL," "));
        x = atoi(strtok(NULL," "));
        bytes[2] = x << 8;
        bytes[3] = x;
        /*
        int x,y;
        bytes[0] = 0x71;
        bytes[0] |= getRegister(strtok(NULL," "));
        bytes[1] = getRegister(strtok(NULL," ")) << 4;
        x = atoi(strtok(NULL," "));
        y = x >> 16;
        y &= 0x0F;
        bytes[1] |= y;
        bytes[2] = (x >> 8) & 0xFF;
        bytes[3] = x & 0xFF;
        */
        return 4;
    }
    if (strcmp("branchIfNotEqual",keyWord) == 0) {
        int x;
        bytes[0] = 0x73;
        bytes[1] = getRegister(strtok(NULL," ")) << 4 | getRegister(strtok(NULL," "));
        x = atoi(strtok(NULL," "));
        bytes[2] = x << 8;
        bytes[3] = x;
        /*
        int x,y;
        bytes[0] = 0x71;
        bytes[0] |= getRegister(strtok(NULL," "));
        bytes[1] = getRegister(strtok(NULL," ")) << 4;
        x = atoi(strtok(NULL," "));
        y = x >> 16;
        y &= 0x0F;
        bytes[1] |= y;
        bytes[2] = (x >> 8) & 0xFF;
        bytes[3] = x & 0xFF;
        */
        return 4;
    }
    if (strcmp("branchIfGreater",keyWord) == 0) {
        int x;
        bytes[0] = 0x74;
        bytes[1] = getRegister(strtok(NULL," ")) << 4 | getRegister(strtok(NULL," "));
        x = atoi(strtok(NULL," "));
        bytes[2] = x << 8;
        bytes[3] = x;
        /*
        int x,y;
        bytes[0] = 0x71;
        bytes[0] |= getRegister(strtok(NULL," "));
        bytes[1] = getRegister(strtok(NULL," ")) << 4;
        x = atoi(strtok(NULL," "));
        y = x >> 16;
        y &= 0x0F;
        bytes[1] |= y;
        bytes[2] = (x >> 8) & 0xFF;
        bytes[3] = x & 0xFF;
        */
        return 4;
    }
    if (strcmp("branchIfGreaterOrEqual",keyWord) == 0) {
        int x;
        bytes[0] = 0x75;
        bytes[1] = getRegister(strtok(NULL," ")) << 4 | getRegister(strtok(NULL," "));
        x = atoi(strtok(NULL," "));
        bytes[2] = x << 8;
        bytes[3] = x;
        /*
        int x,y;
        bytes[0] = 0x71;
        bytes[0] |= getRegister(strtok(NULL," "));
        bytes[1] = getRegister(strtok(NULL," ")) << 4;
        x = atoi(strtok(NULL," "));
        y = x >> 16;
        y &= 0x0F;
        bytes[1] |= y;
        bytes[2] = (x >> 8) & 0xFF;
        bytes[3] = x & 0xFF;
        */
        return 4;
    }
    if (strcmp("call",keyWord) == 0) {
        int x,y;
        bytes[0] = 0x76;
        x = atoi(strtok(NULL," ")) / 2;
        /*
        y = x >> 24;
        bytes[0] |= y;
        y = x >> 16;
        bytes[1] = y;
        y = x >> 8;
        bytes[2] = y;
        bytes[3] = x;
        */
        y = x >> 16;
        bytes[1] = y;
        y = x >> 8;
        bytes[2] = y;
        bytes[3] = x;
        return 4;
    }
    if (strcmp("jump",keyWord) == 0) {
        int x,y;
        bytes[0] = 0x77;
        x = atoi(strtok(NULL," ")) / 2;
        /*
        y = x >> 24;
        bytes[0] |= y;
        y = x >> 16;
        bytes[1] = y;
        y = x >> 8;
        bytes[2] = y;
        bytes[3] = x;
        */
        y = x >> 16;
        bytes[1] = y;
        y = x >> 8;
        bytes[2] = y;
        bytes[3] = x;
        return 4;
    }

    /*
    Load/Store instructions
    */
    if (strcmp("load",keyWord) == 0) {
        bytes[0] = 0x80;
        bytes[0] |= getRegister(strtok(NULL," "));
        bytes[1] = getRegister(strtok(NULL," ")) << 4 | atoi(strtok(NULL," "));
        return 2;
    }
    if (strcmp("store",keyWord) == 0) {
        bytes[0] = 0x90;
        bytes[0] |= getRegister(strtok(NULL," "));
        bytes[1] = getRegister(strtok(NULL," ")) << 4 | atoi(strtok(NULL," "));
        return 2;
    }

    /*
    Stack Instructions
    */
    if (strcmp("pop",keyWord) == 0) {
        bytes[0] = 0xA0;
        bytes[0] |= getRegister(strtok(NULL," "));
        bytes[1] = 0x20;
        return 2;
    }
    if (strcmp("push",keyWord) == 0) {
        bytes[0] = 0xA0;
        bytes[0] |= getRegister(strtok(NULL," "));
        bytes[1] = 0x10;
        return 2;
    }
    if (strcmp("return",keyWord) == 0) {
        bytes[0] = 0xA0;
        bytes[0] |= getRegister(strtok(NULL, " "));
        bytes[1] = 0x00;
        return 2;
    }

    /*
    Move
    */
    if (strcmp("move",keyWord) == 0) {
        bytes[0] = 0xB0;
        bytes[0] |= getRegister(strtok(NULL, " "));
        bytes[1] = 0x00;
        return 2;
    }
    if (strcmp("interrupt",keyWord) == 0) {
        int x;
        bytes[0] = 0xC0;
        x = atoi(strtok(NULL," "));
        bytes[0] |= x >> 8;
        bytes[1] = x;
        return 2;
    }
    else
        return 0;
}

int main(int argc, char **argv) {
    FILE *src = fopen(argv[1],"r");
    FILE *dst = fopen(argv[2],"w");
    while (!feof(src)) {
        unsigned char bytes[4];
        char line[1000];
        if (NULL != fgets(line, 1000, src)) {
            printf ("read: %s\n",line);
            int byteCount = assembleLine(line,bytes);
            fwrite(bytes,byteCount,1,dst);
        }
    }
    fclose(src);
    fclose(dst);
    return 0;
}
