/*
 * A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 *
 * A number whose proper divisors are less than the number is called deficient and a number whose proper divisors exceed the number is called abundant.
 *
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
 *
 * Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int abundant(int target){
    int myarray[6971],myarray2[28124];
    int i,j;
    int temp,temp2;
    unsigned int answer = 0;
    int count = 0;

    for(i=0;i<12;i++){
        myarray2[i]=0;
    }

    for(i=12;i<28123;i++){
        temp2 = 1;
        temp = i/2;
        myarray2[i]=0; /* initialize array */
        for(j=2;j<temp;j++){
            if(i%j==0){
                temp = i/j;
                temp2 += j;
                if(j!=temp){
                    temp2 += temp;
                }
            }
        }
        if(temp2>i){
            /*printf("%d : %d - %d\n",i,temp2,count);*/
            myarray[count] = i;
            count++;
        }
    }

    for(i=0;i<count;i++){
        for(j=i;j<count;j++){
            /*printf("%d+%d = %d\n",myarray[i],myarray[j],myarray[i]+myarray[j]);*/
            if(myarray[i]+myarray[j]<=28123){
                myarray2[myarray[i]+myarray[j]]=1;
            }
        }
    }

    for(i=1;i<=28123;i++){
        if(myarray2[i]==0){
            /*printf("%d : %d\n",i,myarray2[i]);*/
            answer += i;
        }
    }
    
    /*for(i=0;i<=28123;i++){
        printf("%d : %d\n",i,myarray2[i]);
    }*/
    /*for(i=0;i<count;i++){
        printf("%d\n",myarray[i]);
    }*/
    /*printf("%d",count);*/
    return answer;
}

int main (int argc, char *argv[]){
    if(argc == 2){
        int argi = atoi(argv[1]);
        printf("\n%d\n", abundant(argi));
        return 0;
    }
    else{
        printf("\nUsage: abundant <integer>\n");
        return 1;
    }
}
