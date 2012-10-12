/*
 * A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
 *
 *     ^(1)/_(2)    =   0.5
 *         ^(1)/_(3)    =   0.(3)
 *             ^(1)/_(4)    =   0.25
 *                 ^(1)/_(5)    =   0.2
 *                     ^(1)/_(6)    =   0.1(6)
 *                         ^(1)/_(7)    =   0.(142857)
 *                             ^(1)/_(8)    =   0.125
 *                                 ^(1)/_(9)    =   0.(1)
 *                                     ^(1)/_(10)   =   0.1
 *
 *                                     Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that ^(1)/_(7) has a 6-digit recurring cycle.
 *
 *                                     Find the value of d < 1000 for which ^(1)/_(d) contains the longest recurring cycle in its decimal fraction part.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int cycle(int target){
    int answer;
    int i,j;
    int numerator;
    int count;
    int modarray[target],cyclesarray[target];
    int temp;
    int found;
    /*num = 10000000000000000;*/
    for(i=2;i<target;i++){
        count = 0;
        numerator = 1;
        found = 0;
        while(found==0 || count>target){
            numerator *= 10;
            numerator = numerator % i;
            for(j=0;j<count;j++){
                if(numerator == 0){
                    cyclesarray[i]=0;
                    found=1;
                    break;
                }
                else if(numerator==modarray[j]){
                    cyclesarray[i]=count-j;
                    found=1;
                    break;
                }
            }
            modarray[count]=numerator;
            count++;
        }
    }

    answer = 2;
    for(i=3;i<target;i++){
        if(cyclesarray[i]>cyclesarray[answer]){
            answer = i;
        }
    }
    printf("%d\n",cyclesarray[answer]);
    return answer;
}

int main (int argc, char *argv[]){
    if(argc == 2){
        int argi = atoi(argv[1]);
        printf("\n%d\n", cycle(argi));
        return 0;
    }
    else{
        printf("\nUsage: cycle <integer>\n");
        return 1;
    }
}
