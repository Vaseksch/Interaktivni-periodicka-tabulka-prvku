#include <stdio.h>
#include <stdlib.h>

int getch(void);

int main(){
    int inpt = 0;
   while(inpt != -1){
    inpt = getch();
    if(inpt == 27){
        inpt = -1;
    }
    printf("%d\n", inpt);
   }
    return 0;
}