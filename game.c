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
    fflush(stdin);
    int i;
    for (i = 0; i < length; i++) {
        pins[i] = rand() % difficulty;
        printf("%d ", pins[i]);
    }
    back;
    game();
}

void guessInput() {
    char rawGuess[255];



    unsigned long len;


    /* Controlla lunghezza input */
    do{
        printf("Enter your guess: ");
        fgets(rawGuess, 255, stdin);

        len = strlen(rawGuess);
        if (rawGuess[len - 1] == '\n') len--;
        if (len != length) {
            printf("Invalid input \n");
            fflush(stdin);

        }

    } while (len != length) ;

    /* Controlla se input è numerico */
    for (int i = 0; i < length; ++i) {
        if (rawGuess[i] < '0' || rawGuess[i] > '9') {
            printf("Invalid input \n");
            guessInput();
            return;
        } else{
            tries[attempt][i] = rawGuess[i] - '0';
        }
    }


}

int printHistory() {
    int presents;
    int corrects;



    for (int i = 0; i < attempt; i++) {
        presents = tries[i][18];
        corrects = tries[i][19];
        printf("%d ||", i + 1);
        for (int j = 0; j < length; j++) {
            printf(" %d |", tries[i][j]);
        }
        printf("| ");

        for (int j = 0; j < corrects; ++j) {
            printf("%s o ", RED);
            reset_color;
        }
        for (int j = 0; j < presents; ++j) {
            printf("%s o ", WHITE);
            reset_color;
        }
        back;
    }



    if (corrects == 4) {
        back;
        printf("Hai vinto!");
        back;
        return 1;
    }



    return 0;
}



void game() {
    clear;
    if(printHistory() == 1){
        back;
        return;
    }
    if (attempt == maxAttempts) {
        printf("Hai perso!");
        back;
        return;
    }

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

/*
    for (int i = 0; i < corrects; ++i) {
        printf("%s o ", RED);
        reset_color;
    }
    for (int i = 0; i < presents; ++i) {
        printf("%s o ", WHITE);
        reset_color;
    }
*/


    back;
    attempt++;
    back;
    game();
    return;
}