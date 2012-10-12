/*
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 * a^(2) + b^(2) = c^(2)
 *
 * For example, 3^(2) + 4^(2) = 9 + 16 = 25 = 5^(2).
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

/* compile with "-lm" */

int pythagtrip(void){
    int i,j,c;
    for(i=2;i<500;i++){
        for(j=i+1;j<500;j++){
            if(pow(i,2)+pow(j,2) == pow(1000-(i+j),2)){
                c = sqrt(pow(i,2)+pow(j,2));
                printf("\na=%d, b=%d, c=%d\nans=%d\n",i,j,c,i*j*c);
            }
        }
    }
    return 0;
}

int main (int argc, char *argv[]){
    pythagtrip();
    return 0;
}
