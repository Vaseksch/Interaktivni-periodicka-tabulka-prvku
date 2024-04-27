#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


void fce(char * format, ...){

    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}


int main(){
    char name[] = "karel";
    fce("%.3f\n", 1.245);
    fce("%s\n", name);
    fce("%d\n", 3);

    return 0;
}