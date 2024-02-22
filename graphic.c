//
// Created by jag on 2/20/24.
//

#include <stdio.h>
#include <unistd.h>
#include "graphic.h"
#include "define.h"
#include "colors.h"
#include "utils.h"
#include "game.h"

void printCredits() {
    char str[250];
    FILE *file;
    file = fopen("../credits.txt", "r");
    if (file == NULL) {
        file = fopen("./credits.txt", "r");

    }
    while (fgets(str, 255, file) != NULL) {
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
    while (fgets(str, 255, file) != NULL) {
        printf("%s", str);
    };
    back;
    fclose(file);
}

void menu(){
    printMenu();
    int menuOption = 0;
    printf("Enter an option: ");
    scanf("%d", &menuOption);
    switch (menuOption) {
        case 0:
            clear;
            printf("Thank you for playing!");
            back;
            return;
        case 1:
            clear;
            newGame();
            break;
        case 2:
            clear;
            newGame();
            break;
        case 3:
            clear;
            newGame();
            break;
        case 4:
            clear;
            newGame();
            break;
        case 5:
            clear;
            testColors();
            break;
        case 6:
            clear;
            printf("Option 2\n");
            break;
        default:
            clear;
            printf("Invalid option\n");
            break;

    }

    pressEnter();
    clear;
    menu();
}