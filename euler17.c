/*
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 *
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
 *
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int letterarray[1001];

int and=3;

int ones(int num){
    int temp = 0;
    num=num%1000;
    num=num%100;
    if(num>9 && num<20){
        temp+=letterarray[num];
    }
    else{
        num=num%10;
        temp+=letterarray[num];
    }
    return temp;
}

int tens(int num){
    int temp = 0;
    num=num%1000;
    num=num%100;
    if(num>=20){
        temp+=letterarray[(num/10)*10];
    }
    return temp;
}

int hundreds(int num){
    int temp=0;
    num=num%1000;
    if(num>=100){
        temp+=letterarray[num/100]+letterarray[100];
        if(num%100 != 0){
            temp+=and;
        }
    }
    return temp;
}

int thousands(int num){
    int temp=0;
    if(num>=1000){
        temp+=letterarray[num/1000]+letterarray[1000];
    }
    return temp;
}

int numletters(int target){
    letterarray[0]=0;
    letterarray[1]=3;
    letterarray[2]=3;
    letterarray[3]=5;
    letterarray[4]=4;
    letterarray[5]=4;
    letterarray[6]=3;
    letterarray[7]=5;
    letterarray[8]=5;
    letterarray[9]=4;

    letterarray[10]=3;
    letterarray[11]=6;
    letterarray[12]=6;
    letterarray[13]=8;
    letterarray[14]=8;
    letterarray[15]=7;
    letterarray[16]=7;
    letterarray[17]=9;
    letterarray[18]=8;
    letterarray[19]=8;

    letterarray[20]=6;
    letterarray[30]=6;
    letterarray[40]=5;
    letterarray[50]=5;
    letterarray[60]=5;
    letterarray[70]=7;
    letterarray[80]=6;
    letterarray[90]=6;

    letterarray[100]=7;

    letterarray[1000]=8;
    /*
     * 1-9: 3,3,5,4,4,3,5,5,4  100:*9(+3)   1000:*82(+3)
     * 10-19: 3,6,6,8,8,7,7,9,8,8  100:*1   1000:*10
     * 20,30,40,50,60,70,80,90: 6,6,5,5,5,7,6,6  100:*10    1000:*100
     * n00: 7  100:*1   1000:*100*9
     * and: 3   100:*0  1000:*99*9
     * n000: 8  100:*0  1000:*1
     */
    /*int a=((3+3+5+4+4+3+5+5+4)*82)+3;
    int b=(3+6+6+8+8+7+7+9+8+8)*10;
    int c=(6+6+5+5+5+7+6+6)*100;
    int d=(7)*100*9;
    int e=(3)*99*9;
    int f=(8)*1;
    return a+b+c+d+e+f;*/

    int answer=0;
    int i;
    for(i=1;i<=target;i++){
        answer+=thousands(i);
        answer+=hundreds(i);
        answer+=tens(i);
        answer+=ones(i);
    }
    return answer;
}

int main (int argc, char *argv[]){
    if(argc == 2){
        int argi = atoi(argv[1]);
        printf("\n%d\n", numletters(argi));
        return 0;
    }
    else{
        printf("\nUsage: numletters <integer>\n");
        return 1;
    }
}
