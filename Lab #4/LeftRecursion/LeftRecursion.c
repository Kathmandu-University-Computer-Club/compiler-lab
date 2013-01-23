/*
Note that the program uses the \u syntax which is only provided by C99 version of C.
Enabled by default in gcc these days though.
Also, make sure your encoding is set to UTF-8 for the proper display of Epsilon
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char str[20], alpha[20], beta[20];

int main(int argc, char **argv)
{
	FILE *fp;
	char ch;
	char lnt;
	int i;

	fp = fopen("grammer.txt", "w");

	if (fp == NULL)
	{
		printf("Can not write grammar file. Make sure you have right permissions\n\n");
		exit(EXIT_FAILURE);
	}
	printf("Enter the grammer rules below. Tilde sign indicates end of the grammar\n\n");
	while ((ch = getchar()) != '~')
	{
		if (ch != ' ')
		{
			putc(ch, fp);
		}
	}
	//putc('\n', fp);
	fclose(fp);

	fp = fopen("grammer.txt", "r");
	//initialize();
	i = 0;
	while ((ch = getc(fp)) != EOF)
	{
		//ch = (char) ch;

		if (ch != '\n')
		{
			str[i++] = ch;
		}
		else
		{
			int j, k;
			str[i] = '\0';
			if (str[0] == str[3])
			{
				lnt = str[0];
				k = 4;
				j = 0;

				while (str[k] != '|')
				{
					if (str[k] == '\0')
						break;
					alpha[j] = str[k];
					k++; j++;
				}
				alpha[j] = '\0';
				j = 0;

				while (str[k] != '\0')
				{
					k++;
					beta[j++] = str[k];
					///k++;
				}

				printf("%c -> %s%c'\n", lnt, beta, lnt);
				printf("%c' -> %s%c' | \u03F5\n", lnt, alpha, lnt);
			}
			else
			{
				printf("%s\n", str);
			}

			//initialize();
			i = 0;

		}
	}

	fclose(fp);
	return 0;
}
