/*
 ============================================================================
 Name        : LexicalAnalyzer.c
 Author      : Samar@Techgaun.com
 Version     :
 Copyright   : 
 Description : C Lexical analyzer in C
 ============================================================================
 */

/*
Compiled in gcc
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int lines;

const char keywords[][15] = {"for", "do", "while", "if", "extern", "static", "register", "auto", "include", "define", "else", "switch", "case", "default", "break", "continue", "struct", "main", "return", "int", "float", "double", "char", "const", "enum", "union", "goto", "long", "sizeof", "volatile", "signed", "unsigned"};
char str[100], identifier[100][32], keyword[100][15], operator[100][5], number[100][15];
//int numeric[100];
int l_curly_bracket, r_curly_bracket, l_round_bracket, r_round_bracket, semicolon;

int lookahead()
{
	return 0;
}

int main(int argc, char **argv)
{
	FILE *fp, *f2, *f3;
	char ch;
	int i, j, k, len, isIdent;
	int identCount = 0, keywordCount = 0, operCount = 0, numericCount = 0;
	if (argc != 2)
	{
		printf("Usage: %s <filename>\n\n", argv[0]);
		exit(0);
	}

	fp = fopen("test.c", "r");
	if (fp == NULL)
	{
		printf("Could not open the source file\n\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	len = sizeof(keywords) / sizeof(keywords[0]);

	ch = fgetc(fp);
	while (ch != EOF)
	{

		if (ch == '\n')
		{
			lines++;
			ch = fgetc(fp);
			continue;
		}
		if (isspace(ch))
		{
			ch = fgetc(fp);
			continue;
		}
		if (ch == '\t')
		{
			ch = fgetc(fp);
			continue;
		}

		if (isdigit(ch))
		{
			i = 0;
			do
			{
				str[i++] = ch;
				ch = fgetc(fp);

			} while (isdigit(ch));
			str[i] = '\0';
			strcpy(number[numericCount++], str);
		}

		if (isalpha(ch) || (char)ch == "_")
		{
			i = 0;
			isIdent = 1;
			do
			{
				str[i++] = ch;
				ch = fgetc(fp);
			} while (isalpha(ch) || (char)ch == "_" || isdigit(ch));

			str[i] = '\0';
			for (i = 0; i < len; i++)
			{
				if (!strcmp(keywords[i], str))
				{
					strcpy(keyword[keywordCount++], str);
					isIdent = 0;
				}
			}
			if (isIdent == 1)
			{
				strcpy(identifier[identCount++], str);
			}

			if (ch == '(')
			{
				l_round_bracket++;
				ch = fgetc(fp);
				continue;
			}

		}
		else
		{
			//operators?
			str[0] = ch;
			str[1] = '\0';
			if (!strcmp(str, "{"))
			{
				l_curly_bracket++;
				ch = fgetc(fp);
				continue;
			}

			if (!strcmp(str, "}"))
			{
				r_curly_bracket++;
				ch = fgetc(fp);
				continue;
			}

			if (!strcmp(str, "("))
			{
				l_round_bracket++;
				ch = fgetc(fp);
				continue;
			}

			if (!strcmp(str, ")"))
			{
				r_round_bracket++;
				ch = fgetc(fp);
				continue;
			}

			if (!strcmp(str, ";"))
			{
				semicolon++;
				ch = fgetc(fp);
				continue;
			}
			strcpy(operator[operCount++], str);
		}
		ch = fgetc(fp);
		/*if (ch == 10)	//tab = 9, nl = 10, space = 32
		{
			str[i++] = '\0';

		}
		else
		{
			str[i] = ch;
			i++;
		}*/

	}
	printf("\nNumber of keywords: %d\nKeywords: ", keywordCount);
	for (i = 0; i < keywordCount; i++)
	{
		printf("%s  ", keyword[i]);
	}

	printf("\nNumber of identifiers: %d\nIdentifiers: ", identCount);
	for (i = 0; i < identCount; i++)
	{
		printf("%s  ", identifier[i]);
	}

	printf("\nNumber of operators: %d\nOperators: ", operCount);
	for (i = 0; i < operCount; i++)
	{
		printf("%s  ", operator[i]);
	}

	printf("\nNumber of Integers: %d\nNumbers: ", numericCount);
		for (i = 0; i < numericCount; i++)
		{
			printf("%s  ", number[i]);
		}

	printf("\nNumber of left round brackets: %d\n", l_round_bracket);
	printf("Number of right round brackets: %d\n", r_round_bracket);
	printf("Number of left curly brackets: %d\n", l_curly_bracket);
	printf("Number of right curly brackets: %d\n", r_curly_bracket);
	printf("Number of semicolon: %d\n", semicolon);
	printf("\n\n");
	return 0;

}

