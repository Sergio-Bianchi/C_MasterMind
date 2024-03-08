//
// Created by jag on 3/4/24.
//


#include "define.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* ! WiP */
void printGeneral(const char * fileName){
    char str[250];
    FILE *file;
    char * filePath = "../TXT/";
    strcat(filePath, fileName);
    file = fopen(filePath, "r");
    if (file == NULL) {
        file = fopen("./TXT/credits.txt", "r");

    }
    while (fgets(str, 250, file) != NULL) {
        printf("%s", str);
    };
    back;
    fclose(file);


}


void printCredits() {
    char str[250];
    FILE *file;
    file = fopen("../TXT/credits.txt", "r");
    if (file == NULL) {
        file = fopen("./TXT/credits.txt", "r");

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
    file = fopen("../TXT/howToPlay.txt", "r");
    if (file == NULL) {
        file = fopen("./TXT/howToPlay.txt", "r");

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
    file = fopen("../TXT/menu.txt", "r");
    if (file == NULL) {
        file = fopen("./TXT/menu.txt", "r");

    }
    while (fgets(str, 250, file) != NULL) {
        printf("%s", str);
    };
    back;
    fclose(file);
}



void printNewGameMenu() {
    char str[250];
    FILE *file;
    file = fopen("../TXT/menuNewGame.txt", "r");
    if (file == NULL) {
        file = fopen("./TXT/menuNewGame.txt", "r");

    }
    while (fgets(str, 250, file) != NULL) {
        printf("%s", str);
    };
    back;
    fclose(file);
}