/*
 * The sum of the squares of the first ten natural numbers is,
 * 1^(2) + 2^(2) + ... + 10^(2) = 385
 *
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)^(2) = 55^(2) = 3025
 *
 * Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 \u2212 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

/*compile with "-std=c99"*/

unsigned long long int squares(void){
    int i;
    unsigned long long int sumsq,sqsum,ans;
    sumsq = 0;
    sqsum = 0;
    for(i=1;i<=100;i++){
        printf("\n%d",i);
        sqsum+=i;
        sumsq+=pow(i,2);
    }
    sqsum=pow(sqsum,2);
    ans = sqsum - sumsq;

    printf("\n%llu",sqsum);
    printf("\n%llu",sumsq);
    printf("\n%llu",ans);
    return 0;
}

int main (int argc, char *argv[]){
    squares();
    return 0;
}
