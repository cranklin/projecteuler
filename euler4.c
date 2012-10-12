/*
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 ×99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int palincheck(int num){
    int size,i;
    if(num >= 100000){
        size=6;
    }
    else /*if(num >= 10000)*/{
        size=5;
    }
    char intstring[size];
    /*itoa(num,intstring,10);*/
    i = sprintf(intstring,"%d",num);
    if(intstring[0]==intstring[size-1]){
        if(intstring[1]==intstring[size-2]){
            if(size==5){
                return 1;
            }
            else if(intstring[2]==intstring[size-3]){
                return 1;
            }
        }
    }
    return 0;
}

int palindrome(void){
    int i,j,prod;
    for(j=999;j>101;j--){
        for(i=999;i>101;i--){
            prod = j*i;
            if(palincheck(prod)){
                printf("\n%d * %d : %d",j,i,prod);
                break;
            }
        }
    }
    return 0;
}

int main (int argc, char *argv[]){
    printf("\n%d\n",palindrome());
    return 1;
}
