/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

int count(int *A, int number, int len)
{
	int i, count = 0;
	for (i = 0; i < len; i++)
	{
		if (A[i] == number)
			count++;
	}
	return count;
}
int findSingleOccurenceNumber(int *A, int len) {

	if (len <= 0 || A == nullptr)
		return -1;
	int i, count_numbers[100], index;
	for (i = 0; i < len; i++)
		count_numbers[i] = count(A, A[i], len);
	for (i = 0; i < len; i++)
	{
		if (count_numbers[i] == 1)
			index = i;
	}
	return A[index];

}
