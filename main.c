#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "define.h"
#include "colors.h"
#include "functions.h"



int main() {

    srand(time(NULL));

    printCredits();
    sleep(1);

    clear;

    menu();
    return 0;
}




