//
// Created by jag on 2/20/24.
//

#include "functions.h"
#include <stdio.h>
#include "define.h"



void pressEnter() {
    int enter;
    printf("Press enter\n");
    enter = getc(stdin);
    scanf("%*[^\n]"), scanf("%*c");
    clear;

}