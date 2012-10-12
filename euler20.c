/*
 * n! means n ×(n \u2212 1) ×... ×3 ×2 ×1
 *
 * Find the sum of the digits in the number 100!
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int sumofdigits(int target){
    /*unsigned long long int sum = 0;
    unsigned long long int prod = 2;*/
    int bignum[1000];
    bignum[0] = 1;
    int digits = 1;
    int carry = 0;
    int temp;
    int expanded = 0;
    int answer = 0;
    int i,j;
    for(i=2;i<=target;i++){
        /*prod *= 2;*/
        for(j=0;j<digits;j++){
            temp = bignum[j];
            temp *= i;
            if(j>0){
                temp += carry;
            }
            carry = 0;
            if(temp>9){
                carry = temp / 10;
                temp = temp % 10;
                if(j==digits-1){
                    if(carry>9){
                        expanded = 2;
                    }
                    else{
                        expanded = 1;
                    }
                }
            }
            bignum[j] = temp;
            /*printf("%d:%d ",temp,carry);*/
        }
        if(expanded>0){
            /*printf("cha");*/
            if(expanded==2){
                digits+=2;
                bignum[digits-2] = carry%10;
                bignum[digits-1] = carry/10;
            }
            else{
                digits++;
                bignum[digits-1] = carry;
            }
            expanded = 0;
        }
    }
    for(i=digits-1;i>=0;i--){
        answer+=bignum[i];
        printf("%d",bignum[i]);
    }
    return answer;
}

int main (int argc, char *argv[]){
    if(argc == 2){
        int argi = atoi(argv[1]);
        printf("\n%d\n", sumofdigits(argi));
        return 0;
    }
    else{
        printf("\nUsage: sumofdigits <integer>\n");
        return 1;
    }
}
