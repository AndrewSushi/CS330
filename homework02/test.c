#include <stdio.h>
#include <stdlib.h>

int find_numbers(char **argv){
    // FILE *f1 = fopen(argv[1], "r");
    // char buffer[256];
    // int lines = 0;

    // while(fgets(buffer, sizeof(buffer), f1)){
    //     lines++;
    // }
    // fclose(f1);
    // return lines;

    FILE *f1 = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "r");

    if(f1 == NULL || f2 == NULL){
        exit(EXIT_FAILURE);
    }

    char buffer1[256];
    char buffer2[256];
    int lines1 = 0;
    int lines2 = 0;

    while(fgets(buffer1, sizeof(buffer1), f1)){
        lines1++;
    }
    while(fgets(buffer2, sizeof(buffer2), f2)){
        lines2++;
    }
    fclose(f1);
    fclose(f2);
    if(lines1 == lines2){
        return lines1;
    }else{
        return -1;
    }

}

int main(int argc, char **argv){
    int x = find_numbers(argv);
    printf("%d\n", x);
}