//
// Created by jag on 2/20/24.
//

#include "functions.h"
#include <stdio.h>
#include "define.h"



void pressEnter() {
    printf("Press enter\n");
    getc(stdin);
    scanf("%*[^\n]"), scanf("%*c");
    clear;

}