#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "define.h"
#include "colors.h"
#include "functions.h"

int main() {
    printCredits();
    sleep(2);

    clear;

    menu();
    return 0;
}




