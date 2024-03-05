//
// Created by jag on 3/4/24.
//


#include "define.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>


void printCredits() {
    char str[250];
    FILE *file;
    file = fopen("../credits.txt", "r");
    if (file == NULL) {
        file = fopen("./credits.txt", "r");

    }
    while (fgets(str, 250, file) != NULL) {
        printf("%s", str);
    };
    back;
    fclose(file);
}


void printHowToPlay() {
    char str[250];
    FILE *file;
    file = fopen("../howToPlay.txt", "r");
    if (file == NULL) {
        file = fopen("./howToPlay.txt", "r");

    }
    while (fgets(str, 250, file) != NULL) {
        printf("%s", str);
    };
    back;
    fclose(file);
}

void printMenu() {
    char str[250];
    FILE *file;
    file = fopen("../menu.txt", "r");
    if (file == NULL) {
        file = fopen("./menu.txt", "r");

    }
    while (fgets(str, 250, file) != NULL) {
        printf("%s", str);
    };
    back;
    fclose(file);
}