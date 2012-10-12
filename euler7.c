/*
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6^(th) prime is 13.
 *
 * What is the 10001^(st) prime number?
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

/*compile with "-std=c99"*/

unsigned long long int primes(int size){
    int i=2;
    int j,pass;
    unsigned long long int prime[size],test;
    prime[0]=2;
    prime[1]=3;
    test = 5;
    
    while(i<=size){
        pass=0;
        while(!pass){
            pass=1;
            for(j=0;j<i;j++){
                if(test%prime[j]==0){
                    pass=0;
                    test++;
                    break;
                }
            }
        }
        prime[i]=test;
        i++;
    }

    return prime[size-1];
}

int main (int argc, char *argv[]){
    printf("%llu\n",primes(10001));
    return 0;
}
