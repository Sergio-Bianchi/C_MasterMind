//
// Created by jag on 2/20/24.
//

#ifndef C_MASTERMIND_COLORS_H
#define C_MASTERMIND_COLORS_H

// * PRINT COLORS

#define preset_color printf("\033[0m")

#define PBLACK printf("\033[0;30m")
#define PRED printf("\033[0;31m")
#define PGREEN printf("\033[0;32m")
#define PYELLOW printf("\033[0;33m")
#define PBLUE printf("\033[0;34m")
#define PMAGENTA printf("\033[0;35m")
#define PCYAN printf("\033[0;36m")
#define PWHITE printf("\033[0;37m")
#define PPURPLE printf("\033[0;38m")


// * PURE COLORS

#define BLACK "`\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define PURPLE "\033[0;38m"



// * Regular background
#define BLACKBG printf("\e[40m")
#define REDBG printf("\e[41m")
#define GREENBG printf("\e[42m")
#define YELLOWBG printf("\e[43m")
#define BLUEBG printf("\e[44m")
#define MAGENTABG printf("\e[45m")
#define CYANBG printf("\e[46m")
#define WHITEBG printf("\e[47m")



#endif //C_MASTERMIND_COLORS_H
