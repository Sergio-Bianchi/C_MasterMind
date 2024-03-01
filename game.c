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
int tries[10][20];


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

void printHistory() {
    int presents;
    int corrects;

    presents = tries[attempt][18];
    corrects = tries[attempt][19];

    for (int i = 0; i < attempt; i++) {
        printf("||");
        for (int j = 0; j < length; j++) {
            printf(" %d |", tries[i][j]);
        }
        printf("| \n");

        for (int j = 0; j < corrects; ++j) {
            printf("%s o ", RED);
            reset_color;
        }
        for (int j = 0; j < presents; ++j) {
            printf("%s o ", WHITE);
            reset_color;
        }
    }





}



void game() {
    clear;
    printHistory();
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
            checkPins[i] = -3;

            corrects++;
        }
    }

    /* * Controlla giuste in posizione sbagliata */
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; ++j) {
            if (checkInput[i] == checkPins[j]) {
                checkInput[i] = -2;
                checkPins[j] = -4;


                presents++;
                break;
            }
        }

    }

    /* * Aggiungi i valori di corretti e presenti in fondo all'array*/

    tries[attempt][18] = presents;
    tries[attempt][19] = corrects;

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
    back;
    attempt++;
    back;
    game();
}