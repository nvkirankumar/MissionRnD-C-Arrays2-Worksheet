/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int validate(int day, int month, int year)
{
	int ldate[13] = { 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30, 31 };

	if (year % 4 == 0)
		ldate[1] = 29;

	if (day <= ldate[month - 1] && (month >= 1 && month <= 12))
		return 1;
	else
		return 0;
}

int compare(char *dob1, char *dob2) {

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
	c1 = validate(day1, month1, year1);
	c2 = validate(day2, month2, year2);

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

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int c = 0, i, flag = 0;
	for (i = 0; i < len; i++)
	{
		flag = compare(Arr[i].date, date);
		if (flag == 2)
			c++;
	}
	return c;
}
