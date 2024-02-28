//
// Created by jag on 2/20/24.
//

#include "define.h"

#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

void guessInput() {
    char rawGuess[length];

    /* Pulisci input in eccesso */
    if (!strchr(rawGuess, '\n'))     //newline does not exist
        while (fgetc(stdin) != '\n'); //discard until newline

    printf("Enter your guess (numbers separated by commas): ");
    fgets(rawGuess, length + 1, stdin);

    unsigned long len = strlen(rawGuess);
    if (rawGuess[len - 1] == '\n') len--;
    if (len != length) {
        printf("Invalid input");
        guessInput();
    }
    for (int i = 0; i < length; ++i) {
        tries[attempt][i] = rawGuess[i] - '0';
    }


}


void game() {
    /* * Dichiarazione array locali*/
    int checkPins[10];
    int checkInput[10];

    /* * Copia locale array gioco*/
    for (int i = 0; i < length; i++) {
        checkPins[i] = pins[i];
    }

    /* * Input del tentativo*/
    guessInput();

    /* * Copia del tentativo in array per controllare numeri controllati*/
    for (int i = 0; i < length; ++i) {
        checkInput[i] = tries[attempt][i];
    }


    back;
    printf("Array checkInput: ");
    for (int k = 0; k < length; ++k) {
        printf("%d ", checkInput[k]);
    }
    back;

    back;
    printf("Array tries: ");
    for (int k = 0; k < length; ++k) {
        printf("%d ", tries[attempt][k]);
    }
    back;


    /* * Stampa tentativo*/

    printf("||");
    for (int i = 0; i < length; i++) {
        printf(" %d |", checkInput[i]);
    }
    printf("| ");

    /* * Controlla tentativo*/
    int corrects = 0;
    int presents = 0;

    /* * Controlla giuste in posizione giusta */
    for (int i = 0; i < length; i++) {
        if (checkInput[i] == checkPins[i]) {

            checkInput[i] = -1;
            checkPins[i] = -1;

            back;
            printf("Array checkInput right: ");
            for (int j = 0; j < length; ++j) {
                printf("%d ", checkInput[j]);
            }
            back;

            corrects++;
        }
    }

    back;
    printf("Array checkPins: ");
    for (int k = 0; k < length; ++k) {
        printf("%d ", checkPins[k]);
    }
    back;

    /* * Controlla giuste in posizione sbagliata */
/*    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; ++j) {
            if (checkInput[i] == checkPins[j]) {
                checkInput[i] = -1;
                checkPins[j] = -1;

                back;
                printf("Array checkInput: ");
                for (int k = 0; k < length; ++k) {
                    printf("%d ", checkInput[k]);
                }
                back;

                presents++;
                break;
            }
        }

    }*/


    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            if(checkInput[i]==checkPins[j]){
                checkPins[j] = -2;
                printf(" -Z- ");
            }
        }

    }

    for (int i = 0; i < corrects; ++i) {
        printf("%s o ", RED);
        reset_color;
    }
    for (int i = 0; i < presents; ++i) {
        printf("%s o ", WHITE);
        reset_color;
    }

    if (corrects == 4) {
        back;
        printf("Hai vinto!");
        back;
        return;
    }
    printf("Array tries: ");
    for (int k = 0; k < length; ++k) {
        printf("%d ", tries[attempt][k]);
    }
    back;
    attempt++;
    back;
    game();
}