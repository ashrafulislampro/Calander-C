#include <stdio.h>

int getFirstDayofYear(int year)
{
    int day = (year * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) % 7;
    return day;
}

int main()
{
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int i, j, weekday = 0, spaceCounter, year;

    printf("Enter your favorite year : ");
    scanf("%d", &year);
    // get the first day of the year
    weekday = getFirstDayofYear(year);
    // check if it is a leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        daysInMonth[1] = 29;
    }
    printf("\n\n ------------- Welcome to %d ------------- \n\n", year);

    for (i = 0; i < 12; i++)
    {
        printf("\n\n ---------------- %s ----------------\n\n", months[i]);
        printf("\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n\n");
        for (spaceCounter = 1; spaceCounter <= weekday; spaceCounter++)
        {
            printf("      ");
        }
        for (j = 1; j <= daysInMonth[i]; j++)
        {
            printf("%6d", j);
            weekday++;
            if (weekday > 6)
            {
                printf("\n");
                weekday = 0;
            }
        }
    }
    printf("\n\n\n");
    return 0;
}