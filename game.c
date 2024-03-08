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
int length = 5;
int maxAttempts = 10;
int selectedColors[8] = {1, 2, 3, 4};
int colors[8] = {};

int attempt = 0;
int tries[20][20];


int newGame() {
    newGameMenu();


    return 0;
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
            printHowToPlay();
            break;
        default:
            clear;
            printCredits();
            break;

    }

    pressEnter();
    clear;
    menu();
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
            insertGame();
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

    fflush(stdin);
    pressEnter();
    newGame();


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

    attempt = 0;


    int i;
    for (i = 0; i < length; i++) {
        pins[i] = rand() % difficulty;
        printf("%d ", pins[i]);
    }
    back;
    game();
}



void insertGame() {
    char rawInput[250];
    unsigned long len;

    int i;

    attempt = 0;
    do{
        printf("Enter the sequence: ");
        fgets(rawInput, 250, stdin);

        len = strlen(rawInput);
        if (rawInput[len - 1] == '\n') len--;
        if (len != length) {
            printf("Invalid input \n");
            fflush(stdin);

        }

    } while (len != length);

    /* Controlla se input è numerico */
    for (i = 0; i < length; ++i) {
        if (rawInput[i] < '0' || rawInput[i] > '9') {
            printf("Invalid input \n");
            guessInput();
            return;
        } else{
            pins[i] = rawInput[i] - '0';
        }
    }
    back;
    game();
}



void guessInput() {
    char rawGuess[250];

    unsigned long len;


    /* Controlla lunghezza input */
    do{
        printf("Enter your guess: ");
        fgets(rawGuess, 250, stdin);

        len = strlen(rawGuess);
        if (rawGuess[len - 1] == '\n') len--;
        if (len != length) {
            printf("Invalid input \n");
            fflush(stdin);

        }

    } while (len != length);

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
        printf("%2d ||", i + 1);
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



    if (corrects == length) {
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
        back;

        printf("You loose!");
        back;
        printf("Solution: ");
        back;
        printf("||");
        for(int i = 0; i < length; i++){
            printf(" %d |", pins[i]);
        }
        printf("|");

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





    back;
    attempt++;
    back;
    game();
    return;
}