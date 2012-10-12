/*
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest number that is evenly divisible by all of the numbers from 1 to 20?
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int p5(void){
    int i,j,found;
    j=2000;
    found=0;
    while(found==0){
        j+=20;
        found=1;
        for(i=19;i>2;i--){
            if(j%i){
                found=0;
                break;
            }
        }
    }
    return j;
}

int main (int argc, char *argv[]){
    printf("\n%d\n",p5());
    return 1;
}
