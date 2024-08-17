#include <stdio.h>

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *months[] = {
    "",
    "\n\n\nJanuary",
    "\n\n\nFebruary",
    "\n\n\nMarch",
    "\n\n\nApril",
    "\n\n\nMay",
    "\n\n\nJune",
    "\n\n\nJuly",
    "\n\n\nAugust",
    "\n\n\nSeptember",
    "\n\n\nOctober",
    "\n\n\nNovember",
    "\n\n\nDecember",
};

int input_year()
{
    int year = 0;
    printf("please enter the year");

    scanf("%d", year);

    return year;
}

int is_leap(int year)
{
    if (year % 4 == 0 && year % 100 == 1 || year % 400 == 0)
    {
        days_in_month[2] = 29; // set the leap year date;
        return 1;
    }
    else
    {
        days_in_month[2] = 28; // return to base month
    }
}

int day_output(int year)
{
    int date = 0;
    int day_1 = 0;
    int day_2 = 0;
    int day_3 = 0;

    day_1 = (year - 1.0) / 4.0;
    day_2 = (year - 1.0) / 100;
    day_2 = (year - 1.0) / 1;

    date = (year + day_1 - day_2 + day_3) % 7;
    return date;
}

void calendar(int year, int date)
{
    int month = 0;
    int day = 0;
    for (month = 1; month <= 12; month++)
    {
        printf("%s", months[month]);
        printf("\n\nഞായർ  തിങ്കൾ  ചൊവ്വ  ബുധൻ  വ്യാഴം  വെള്ളി  ശനി\n ");
        for (day = 1; day <= 1 + date * 5; day++)
        {
            printf(" ");
        }
        for (day = 1; day <= days_in_month[month]; day++)
        {
            printf("%2d", day);
        }

        if ((day + date) % 7 > 0) {
            printf("  ");
        } else {
            printf("\n ");
        }

        date = (date + days_in_month[month]) % 7;
    }
}

int main() {
    int year = 0;
    int date = 0;
    int leap = 0;
    year = input_year(year);
    date = day_output(year);
    is_leap(year);
    calendar(year, date);
    printf("\n");

}