/*
 * Consider all integer combinations of a^(b) for 2 \u2264 a \u2264 5 and 2 \u2264 b \u2264 5:
 *
 *     2^(2)=4, 2^(3)=8, 2^(4)=16, 2^(5)=32
 *         3^(2)=9, 3^(3)=27, 3^(4)=81, 3^(5)=243
 *             4^(2)=16, 4^(3)=64, 4^(4)=256, 4^(5)=1024
 *                 5^(2)=25, 5^(3)=125, 5^(4)=625, 5^(5)=3125
 *
 *                 If they are then placed in numerical order, with any repeats removed, we get the following sequence of 15 distinct terms:
 *
 *                 4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125
 *
 *                 How many distinct terms are in the sequence generated by a^(b) for 2 \u2264 a \u2264 100 and 2 \u2264 b \u2264 100?
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int diagonal(int target){
    int answer=1;
    int i,j,k,temp;

    for(k=2;k<=target;k++){
        for(i=1;i<=target;i++){
            temp = k;
            for(j=1;j<i;j++){
                temp *= k;
            }
            printf("%10d ",temp);
        }
        printf("\n");
    }
    return answer;
}

int main (int argc, char *argv[]){
    if(argc == 2){
        int argi = atoi(argv[1]);
        printf("\n%d\n", diagonal(argi));
        return 0;
    }
    else{
        printf("\nUsage: diagonal <integer>\n");
        return 1;
    }
}