/*
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

/*compile with "-std=c99"*/

unsigned long long int primes(int max){
    int i=1;
    int j,pass,cont;
    unsigned long long int prime[500000],test,ans;
    prime[0]=2;
    prime[1]=3;
    test = 4;
    ans = 5;
    cont=1;
    
    while(prime[i]<max && cont==1){
        pass=0;
        while(!pass && cont==1){
            pass=1;
            test++;
            /*for(j=0;j<i;j++){*/
            j=0;
            while(j<i && prime[j]<test/2){
                if(test%prime[j]==0){
                    pass=0;
                    /*printf("\n%llu, %llu, %d\n",ans,test,i);*/
                    if(test>=max){
                        cont=0;
                    }
                    break;
                }
                j++;
            }
        }
        if(pass==1){
            prime[++i]=test;
            ans+=prime[i];
            /*printf("\n%llu\n",test);*/
        }
    }
    
    return ans;
}

int main (int argc, char *argv[]){
    printf("%llu\n",primes(2000000));
    return 0;
}
