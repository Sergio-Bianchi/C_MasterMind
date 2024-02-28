//
// Created by jag on 2/20/24.
//

#include "define.h"

#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include "colors.h"


/* ? GLOBAL VARIABLES */

int pins[5];
int difficulty = 6;
int length = 4;
int maxAttempts = 10;
int selectedColors[8] = {1, 2, 3, 4};
int colors[8] = {};

int attempt = 0;
int tries[10][8];


int newGame() {
    newGameMenu();


    return 0;
}


void newGameMenu() {
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
            generateGame();
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
    while (fgets(str, 250, file) != NULL) {
        printf("%s", str);
    };
    back;
    fclose(file);
}


/* SETTINGS */

void testColors() {
    printf("Test colors\n");
    printf("%s Black - o\n", BLACK);
    printf("%s Red - o\n", RED);
    printf("%s Green - o\n", GREEN);
    printf("%s Yellow - o \n", YELLOW);
    printf("%s Blue - o \n", BLUE);
    printf("%s Magenta - o \n", MAGENTA);
    printf("%s Cyan - o \n", CYAN);
    printf("%s White - o \n", WHITE);
    printf("%s Purple - o \n", PURPLE);
    back;
}


void generateGame() {
    int i;
    for (i = 0; i < length; i++) {
        pins[i] = rand() % difficulty;
        printf("%d ", pins[i]);
    }
    back;
    game();
}


void game() {
    int checkPins[10];
    for (int i = 0; i < length; i++) {
        checkPins[i] = pins[i];
    }


    printf("Enter your guess (numbers separated by commas): ");
    if (length == 4) {
        scanf("%d,%d,%d,%d", &tries[attempt][0], &tries[attempt][1], &tries[attempt][2], &tries[attempt][3]);
    } else if (length == 5) {
        scanf("%d,%d,%d,%d,%d", &tries[attempt][0], &tries[attempt][1], &tries[attempt][2], &tries[attempt][3],
              &tries[attempt][4]);
    } else if (length == 6) {
        scanf("%d,%d,%d,%d,%d,%d", &tries[attempt][0], &tries[attempt][1], &tries[attempt][2], &tries[attempt][3],
              &tries[attempt][4], &tries[attempt][5]);
    } else if (length == 7) {
        scanf("%d,%d,%d,%d,%d,%d,%d", &tries[attempt][0], &tries[attempt][1], &tries[attempt][2], &tries[attempt][3],
              &tries[attempt][4], &tries[attempt][5], &tries[attempt][6]);
    } else if (length == 8) {
        scanf("%d,%d,%d,%d,%d,%d,%d,%d", &tries[attempt][0], &tries[attempt][1], &tries[attempt][2], &tries[attempt][3],
              &tries[attempt][4], &tries[attempt][5], &tries[attempt][6], &tries[attempt][7]);
    }


    printf("||");
    for (int i = 0; i < length; i++) {
        printf(" %d |", tries[attempt][i]);
    }
    printf("| ");

    int corrects = 0;
    int presents = 0;

    for (int i = 0; i < length; i++) {
        if (tries[attempt][i] == checkPins[i]) {

            checkPins[i] = -1;
            corrects++;
        }
    }

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; ++j) {
            if (tries[attempt][i] == checkPins[j]) {

                checkPins[j] = -1;
                presents++;
                break;
            }
        }

    }


    for (int i = 0; i < corrects; ++i) {
        printf("2 ");
    }
    for (int i = 0; i < presents; ++i) {
        printf("1 ");
    }
    for (int i = 0; i < length - corrects - presents; ++i) {
        printf("0 ");
    }
    if (corrects == 4) {
        back;
        printf("Hai vinto!");
        back;
        return;
    }
    back;
    game();
}