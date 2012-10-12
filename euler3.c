/*
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*compile with "-std=c99"*/

unsigned long long int primefactor(unsigned long long int num){
    unsigned long long int i,temp;
    /*for(i=num/2;i>=3;i--){*/
    /*for(i=num/2;i>=3;i--){*/
    for(i=2;i<num/2;i++){
        if(num%i==0){
            temp = num/i;
            primefactor(num/i);
            break;
        }
    }
    printf("\n%llu",temp);
    return 1;
}

int main (int argc, char *argv[]){
    primefactor(600851475143);
    /*unsigned long long int prod = 8462696833*71;
    printf("%llu",prod);*/
    /*printf("%llu",ULLONG_MAX);*/
    return 1;
}
