/*
 * Euler published the remarkable quadratic formula:
 *
 * n² + n + 41
 *
 * It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 40^(2) + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.
 *
 * Using computers, the incredible formula  n² \u2212 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, \u221279 and 1601, is \u2212126479.
 *
 * Considering quadratics of the form:
 *
 *     n² + an + b, where |a| < 1000 and |b| < 1000
 *
 *         where |n| is the modulus/absolute value of n
 *             e.g. |11| = 11 and |\u22124| = 4
 *
 *             Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int primecheck(long long int num){
    long long int temp;
    long long int i;
    temp = num/2;
    for(i=2;i<temp;i++){
        if(num%i==0){
            return 0;
        }
        else{
            temp = num / i;
        }
    }
    return 1;
}

int quadratic(int target){
    int answer;
    int primes[500];
    int i,j,k,m;
    int a,b;
    int count = 2;
    int prime;
    long long int temp;
    int primecount;
    int maxprimes = 0;
    int maxa,maxb;

    primes[0]=1;
    primes[1]=2;

    for(i=3;i<target;i+=2){
        if(primecheck(i)){
            primes[count++] = i;
        }
    }

    for(m=0;m<1;m++){
        for(i=(-1*target);i<target;i++){
            for(j=(-1*target);j<target;j++){
                k=0;
                prime = 1;
                primecount = 0;
                if(m==0){
                    /*a=primes[i];*/
                    /*b=primes[j];*/
                    a=i;
                    b=j;
                }
                else if(m==1){
                    /*a=primes[i];*/
                    /*b=primes[j]*-1;*/
                    a=i;
                    b=j*-1;
                }
                else if(m==2){
                    /*a=primes[i]*-1;*/
                    /*b=primes[j];*/
                    a=i*-1;
                    b=j;
                }
                else{
                    /*a=primes[i]*-1;*/
                    /*b=primes[j]*-1;*/
                    a=i*-1;
                    b=j*-1;
                }
                while(primecount<200){
                    temp = (k*k) + (k*a) + b;
                    if(temp<0 || primecheck(temp)==0){
                        break;
                    }
                    primecount++;
                    k++;
                }
                /*printf("%d : %d,%d\n",primecount,a,b);*/
                if(primecount>maxprimes){
                    maxprimes = primecount;
                    maxa = a;
                    maxb = b;
                }
            }
        }
    }

    /*for(i=0;i<count;i++){
        printf("%d\n",primes[i]);
    }*/
    printf("%d,%d : %d\n",maxa,maxb,maxprimes);
    answer = maxa*maxb;
    return answer;
}

int main (int argc, char *argv[]){
    if(argc == 2){
        int argi = atoi(argv[1]);
        printf("\n%d\n", quadratic(argi));
        return 0;
    }
    else{
        printf("\nUsage: quadratic <integer>\n");
        return 1;
    }
}
