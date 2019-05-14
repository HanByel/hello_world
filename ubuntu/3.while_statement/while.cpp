#include <stdio.h>

main(){
    int i=0;
    while(i!=10){
        printf("i = %d \n", i);
        i++;
    }
    i=0;
    printf("\n\n");
    while(1){
        if(i==10)   break;
        printf("i = %d \n", i);
        i++;
    }
}
