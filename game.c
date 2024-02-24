//
// Created by jag on 2/20/24.
//

#include "define.h"

#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
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
    printf("%s Black - o\n", BLACK);
    printf( "%s Red - o\n" , RED);
    printf( "%s Green - o\n", GREEN);
    printf("%s Yellow - o \n", YELLOW);
    printf("%s Blue - o \n" , BLUE);
    printf("%s Magenta - o \n", MAGENTA);
    printf("%s Cyan - o \n", CYAN);
    printf("%s White - o \n", WHITE);
    printf("%s Purple - o \n", PURPLE);
    back;
}
