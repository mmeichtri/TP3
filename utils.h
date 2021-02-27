#ifndef UTILS_H
#define UTILS_H
#include <string>

#ifndef TEXT_COLORS
#define TEXT_COLORS
    #define __TEXT_NC__ "\033[0m"
    #define __TEXT_RED__ "\033[1;31m"
    #define __TEXT_GRN__ "\033[1;32m"
    #define __TEXT_YLW__ "\033[1;33m"
    #define __TEXT_BLU__ "\033[1;34m"
    #define __TEXT_PUR__ "\033[1;35m"
    #define __TEXT_CYN__ "\033[1;36m"
    #define __TEXT_ERROR__ "\033[1;5;31m"
    #define __TEXT_BG_GRN__ "\033[1;42m"
    #define __TEXT_BG_BLU__ "\033[1;44m"
    #define __TEXT_BLU_TWINK__ "\033[1;5;94m"
    #define __TEXT_GRN_TWINK__ "\033[1;5;92m"
    #define __TEXT_BG_REDB__ "\033[33;41m"
#endif	//TEXT_COLORS

#ifndef BACKGORUND_COLORS
#define BACKGORUND_COLORS
	#define __NC__ "\033[0m"
	#define __RED__ "\033[30;41m"
	#define __GRN__ "\033[30;42m"
	#define __YLW__ "\033[1;30;43m"
	#define __BLU__ "\033[30;44m"
	#define __PUR__ "\033[30;45m"
	#define __CYN__ "\033[30;46m"
	#define __GRY__ "\033[30;47m"
	#define __REDB__ "\033[41m"
#endif //BACKGROUND_COLORS


using namespace std;

typedef unsigned int uint;

#endif //UTILS_H