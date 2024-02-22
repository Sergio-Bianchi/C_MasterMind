//
// Created by jag on 2/20/24.
//

#include "define.h"

#include "game.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include "graphic.h"
#include "colors.h"

int newGame(){
    newGameMenu();



    return 0;
}


void newGameMenu(){
    printNewGameMenu();
    int menuOption = 0;
    printf("Enter an option: ");
    scanf("%d", &menuOption);
    switch (menuOption) {
        case 0:
            clear;
            return;
        case 1:
            clear;
            newGame();
            break;
        case 2:
            clear;
            printf("Option 2\n");
            break;
        default:
            clear;
            printf("Invalid option\n");
            break;

    }

    pressEnter();

    newGameMenu();

}

void printNewGameMenu() {
    char str[250];
    FILE *file;
    file = fopen("../menuNewGame.txt", "r");
    if (file == NULL) {
        file = fopen("./menuNewGame.txt", "r");

    }
    while (fgets(str, 255, file) != NULL) {
        printf("%s", str);
    };
    back;
    fclose(file);
}



/* SETTINGS */

void testColors(){
    printf("Test colors\n");
    black;
    printf("Black - o\n");
    red;
    printf("Red - o\n");
    green;
    printf("Green - o\n");
    yellow;
    printf("Yellow - o \n");
    blue;
    printf("Blue - o \n");
    magenta;
    printf("Magenta - o \n");
    cyan;
    printf("Cyan - o \n");
    white;
    printf("White - o \n");
    purple;
    printf("Purple - o \n");
    back;
}
