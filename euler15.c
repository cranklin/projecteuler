/*
 * Starting in the top left corner of a 2× grid, there are 6 routes (without backtracking) to the bottom right corner.
 *
 * How many routes are there through a 20×0 grid?
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned long long int grid(int size){
    int i,j,currentarray;
    unsigned long long int myarray[2][size+1];
    int arrayold = 0;
    int arraynew = 1;
    int temp;

    /* initialize */
    for(i=0;i<size+1;i++){
        myarray[arrayold][i]=1;
    }
    myarray[arraynew][0]=1;

    /* loop */
    for(j=0;j<size;j++){
        for(i=1;i<size+1;i++){
            myarray[arraynew][i]=myarray[arrayold][i]+myarray[arraynew][i-1];
            /*printf("\n%d,%d:%d",arraynew,i,myarray[arraynew][i]);*/
        }
        temp = arraynew;
        arraynew = arrayold;
        arrayold = temp;
    }
    return myarray[arrayold][size];
}

int main (int argc, char *argv[]){
    if(argc == 2){
        int argi = atoi(argv[1]);
        printf("\n%lld\n", grid(argi));
        return 0;
    }
    else{
        printf("\nUsage: grid <integer>\n");
        return 1;
    }
    return 1;
}
