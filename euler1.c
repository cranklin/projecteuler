/*
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 *
 * Find the sum of all the multiples of 3 or 5 below 1000.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int threes(void){
    int i;
    int sum=0;
    for(i=0;i<1000;i+=3){
        sum+=i;
        printf("\nthrees: %d",i);
        printf("\nsum: %d",sum);
    }
    return sum;
}

int fives(void){
    int i;
    int sum=0;
    for(i=0;i<1000;i+=5){
        sum+=i;
        printf("\nfives: %d",i);
        printf("\nsum: %d",sum);
    }
    return sum;
}

int p1(void){
    int i,sum;
    sum=0;
    for(i=0;i<1000;i++){
        if(i%3==0 || i%5==0){
            sum+=i;
        }
    }
    return sum;
}

int main (int argc, char *argv[]){
    /*printf("\n%d\n", threes()+fives());*/
    printf("\n%d\n",p1());
    return 1;
}
