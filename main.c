#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "define.h"
#include "colors.h"
#include "functions.h"



int numCifre(int n) {
    int cifre = 0;
    while (n > 0) {
        n = n / 10;
        cifre++;
    }
    return cifre;
}


int main() {

    srand(time(NULL));

    printCredits();
    sleep(2);

    clear;

    menu();
    return 0;
}




