/*
 * The sequence of triangle numbers is generated by adding the natural numbers. So the 7^(th) triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:
 *
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *
 * Let us list the factors of the first seven triangle numbers:
 *
 *      1: 1
 *           3: 1,3
 *                6: 1,2,3,6
 *                    10: 1,2,5,10
 *                        15: 1,3,5,15
 *                            21: 1,3,7,21
 *                                28: 1,2,4,7,14,28
 *
 *                                We can see that 28 is the first triangle number to have over five divisors.
 *
 *                                What is the value of the first triangle number to have over five hundred divisors?
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int triangle(int target){
    int divcount,increment,current,i,status,j,trialmax;

    status=1;
    current=1;
    increment=1;
    divcount=2;
    while(status!=0){
        if(status>0){
            for(j=0;j<status;j++){
                increment++;
                current+=increment;
            }
        }
        else{
            current-=increment;
            increment--;
        }

        divcount = 2;
        trialmax=current;
        for(i=2;i<trialmax;i++){
            if(current%i==0){
                trialmax=current/i;
                divcount+=2;
            }
        }
        /*printf("\ncurrent:%d, divcount:%d, increment:%d, status:%d\n",current,divcount,increment,status);*/

        if(divcount>target && status==1){
            status=0;
        }
        else if(divcount>target && status==10){
            status=-1;
        }
        else if(status==-1 && divcount<=target){
            status=1;
        }
    }
    return current;
}

int main (int argc, char *argv[]){
    if(argc == 2){
        int argi = atoi(argv[1]);
        printf("\n%d\n", triangle(argi));
        return 0;
    }
    else{
        printf("\nUsage: triangle <integer>\n");
        return 1;
    }
}
