/*
 * A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
 *
 * 012   021   102   120   201   210
 *
 * What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int digits[10]={0,0,0,0,0,0,0,0,0,0};

int permutate(int num){
    int i;
    int count=0;
    for(i=0;i<10;i++){
        if(digits[i]==0){
            count++;
        }
        if(num == count-1){
            digits[i]=1;
            return i;
        }
    }
}

int lexicograph(int target){
    int answer,temp;
    target--;

    printf("\n");

    temp = target/362880;
    printf("%d",permutate(temp%10));
    temp = target/40320;
    printf("%d",permutate(temp%9));
    temp = target/5040;
    printf("%d",permutate(temp%8));
    temp = target/720;
    printf("%d",permutate(temp%7));
    temp = target/120;
    printf("%d",permutate(temp%6));
    temp = target/24;
    printf("%d",permutate(temp%5));
    temp = target/6;
    printf("%d",permutate(temp%4));
    temp = target/2;
    printf("%d",permutate(temp%3));
    temp = target/1;
    printf("%d",permutate(temp%2));
    printf("%d",permutate(0));
    printf("\n");

    return answer;
}

int main (int argc, char *argv[]){
    if(argc == 2){
        int argi = atoi(argv[1]);
        printf("\n%d\n", lexicograph(argi));
        return 0;
    }
    else{
        printf("\nUsage: lexicograph <integer>\n");
        return 1;
    }
}
