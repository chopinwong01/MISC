/*
 *  doomsday.c
 *  A program to test a function dayOfWeek which determines which
 *  day of the week a particular date falls on.
 *  (only for dates after the start of the Gregorian calendar).
 *
 *  Program stub created by Richard Buckland on 17/03/14
 *  This program by Gary Chen
 *  Freely licensed under Creative Commons CC-BY-3.0
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define THURSDAY 0
#define FRIDAY   1
#define SATURDAY 2
#define SUNDAY   3
#define MONDAY   4
#define TUESDAY  5
#define WEDNESDAY 6

#define TRUE 1
#define FALSE 0
#define DAYS_PER_WEEK 7

int dayOfWeek (int doomsday, int leapYear, int month, int day);

int main (int argc, char *argv[]) {
		printf("day=%d",dayOfWeek(FRIDAY,FALSE,6,6));
		assert ((dayOfWeek(FRIDAY,FALSE,6,6) == FRIDAY));
    printf ("all tests passed - You are awesome!\n");
    return EXIT_SUCCESS;
}


// given the doomsday for a year, and whether or not it is a
// leap year, this function return the day of the week for any
// given month and day in the year.

int dayOfWeek (int doomsday, int leapYear, int month, int day) {
    int dayOfWeek;
		//printf("day=%d,",day);
// whether or not it is a leap year,September and December
// always have the same weeks,so the day of week is same.
    if (month ==6){
						dayOfWeek=(doomsday+(57+day))%7;
						printf("doomsday=%d,month=%d,day=%d,dayOfWeek=%d,",doomsday,month,day,dayOfWeek);
						//if(dayOfWeek==FRIDAY){printf ("dayOfWeek=%d\n",dayOfWeek);}
		}
// it was found that in leap year January,April and July;
// February and August;March and November have the same
// week,so the day of those pair weeks are same.

    return dayOfWeek;
}






