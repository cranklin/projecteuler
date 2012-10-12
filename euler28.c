/*
 * Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
 *
 * 21 22 23 24 25
 * 20  7  8  9 10
 * 19  6  1  2 11
 * 18  5  4  3 12
 * 17 16 15 14 13
 *
 * It can be verified that the sum of both diagonals is 101.
 *
 * What is the sum of both diagonals in a 1001 by 1001 spiral formed in the same way?
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int diagonal(int target){
    int answer=1;
    int i,j;
    int num=1;
    for(i=2;i<target;i+=2){
        for(j=0;j<4;j++){
            num+=i;
            answer+=num;
            /*printf("%d\n",num);*/
        }
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
