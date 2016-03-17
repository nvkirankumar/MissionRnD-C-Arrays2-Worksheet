/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int check(int day, int month, int year)
{
	int ldate[13] = { 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30, 31 };

	if (year % 4 == 0)
		ldate[1] = 29;

	if (day <= ldate[month - 1] && (month >= 1 && month <= 12))
		return 1;
	else
		return 0;
}


int compare_dates(char *dob1, char *dob2) {

	int day1 = 0, day2 = 0, month1 = 0, month2 = 0, year1 = 0, year2 = 0, i, c1 = 0, c2 = 0;

	for (i = 0; dob1[i] >= '0' && dob1[i] <= '9'; i++)
	{
		day1 = day1 * 10 + dob1[i] - '0';
		day2 = day2 * 10 + dob2[i] - '0';
	}i++;
	for (i = i; dob1[i] >= '0' && dob1[i] <= '9'; i++)
	{
		month1 = month1 * 10 + dob1[i] - '0';
		month2 = month2 * 10 + dob2[i] - '0';
	}i++;
	for (i = i; dob1[i] >= '0' && dob1[i] <= '9'; i++)
	{
		year1 = year1 * 10 + dob1[i] - '0';
		year2 = year2 * 10 + dob2[i] - '0';
	}i++;
	//printf("%d-%d-%d\n%d-%d-%d",day1,month1,year1,day2,month2,year2);
	c1 = check(day1, month1, year1);
	c2 = check(day2, month2, year2);

	if (c1 == 0 || c2 == 0)
		return -1;
	else if (year1 > year2)
		return 2;
	else if (year1 < year2)
		return 1;
	else if (month1 < month2)
		return 1;
	else if (month1 > month2)
		return 2;
	else if (day1 > day2)
		return 2;
	else if (day1 < day2)
		return 1;
	else
		return 0;
}


struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	
	if (A == NULL || B == NULL)
		return NULL;
	
	struct transaction *res = (struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));

	int i, j, flag = -1, k = 0, tmp = 0;

	for (i = 0; i < ALen; i++)
	{
		for (j = 0; j < BLen; j++)
		{
			flag = compare_dates(A[i].date, B[j].date);
			if (flag == 0)
			{
				tmp = 1;
				res[k] = A[i];
				k++;

			}
		}
	}

	if (tmp == 0)
		return NULL;

	return res;
}