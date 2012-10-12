/*
 * You are given the following information, but you may prefer to do some research for yourself.
 *
 *     * 1 Jan 1900 was a Monday.
 *         * Thirty days has September,
 *               April, June and November.
 *                     All the rest have thirty-one,
 *                           Saving February alone,
 *                                 Which has twenty-eight, rain or shine.
 *                                       And on leap years, twenty-nine.
 *                                           * A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
 *
 *                                           How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int isleap(int year){
    /* every 4 years unless divisible by 100 unless divisible by 400 */
    if(year%400 == 0){
        return 1;
    }
    else if(year%100 == 0){
        return 0;
    }
    else if(year %4 == 0){
        return 1;
    }
    return 0;
}

int sundays(int target){
    /* establishing days per month */
    int yearlydpm[12];
    yearlydpm[1]=31;
    yearlydpm[2]=28; /* 29 on leap year */
    yearlydpm[3]=31;
    yearlydpm[4]=30;
    yearlydpm[5]=31;
    yearlydpm[6]=30;
    yearlydpm[7]=31;
    yearlydpm[8]=31;
    yearlydpm[9]=30;
    yearlydpm[10]=31;
    yearlydpm[11]=30;
    yearlydpm[12]=31;

    /* sunday = 0, monday = 1, tuesday = 2, wednesday = 3, thursday = 4, friday = 5, saturday = 6 */

    /* 1900-1-1 = monday */
    int year=1900;
    int month=1;
    int day=1;
    int dayofweek=1;

    int days;
    int answer=0;

    int i,j,k,l;

    for(i=year;i<=target;i++){ /* yearly loop */
        for(j=month;j<=12;j++){ /* monthly loop */
            if(month==2 && isleap(year)==1){ /* leap year days */
                days = 29;
            }
            else{
                days = yearlydpm[j];
            }
            for(k=1;k<=days;k++){
                if(k==1 && dayofweek==0 && i>=1901){
                    answer++;
                    printf("\n%d-%d-%d",i,j,k);
                }
                dayofweek = (dayofweek+1)%7;
            }
        }
    }

    return answer;
}

int main (int argc, char *argv[]){
    if(argc == 2){
        int argi = atoi(argv[1]);
        printf("\n%d\n", sundays(argi));
        return 0;
    }
    else{
        printf("\nUsage: sundays <integer>\n");
        return 1;
    }
}
