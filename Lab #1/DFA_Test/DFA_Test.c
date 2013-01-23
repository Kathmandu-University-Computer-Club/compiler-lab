//dfa trick for question no. 1.a)
//(0 + 1)* + 0*1*
//Samar @ http://www.techgaun.com
#include <stdio.h>
#include <stdlib.h>

int transition_table[2][2] = {
		{0, 1},
		{0, 1}
};
int currentState;

int checkMatch(int n)
{
	if (transition_table[currentState][n] == -1)
	{
		return -1;
	}

	if (n == 0)
	{
		currentState = 0;
	}
	else
	{
		currentState = 1;
	}
	return 1;
}

int main(int argc, char **argv)
{
	int i, nStates = 2, nFinalStates = 2, nInputs = 2, len, num, valid = 1;
	char inputString[100];

	printf("Enter the string: ");
	scanf("%s", inputString);
	i = 0;

	while (inputString[i] != '\0')
	{
		//num = (inputString[i] == '1')?1:0;
		if (inputString[i] == '1')
			num = 1;
		else if (inputString[i] == '0')
			num = 0;
		else
		{
			printf("Invalid string detected. Language consists of 0s & 1s only\n\n");
			exit(EXIT_FAILURE);
		}

		if (checkMatch(num) == -1)
		{
			printf("String does not belong to given regular language\n\n");
			valid = 0;
			exit(0);
		}

		i++;
	}

	if (valid == 1 && (currentState == 0 || currentState == 1))
	{
		printf("String %s belongs to given regular language\n\n", inputString);
	}

	return 0;
}
