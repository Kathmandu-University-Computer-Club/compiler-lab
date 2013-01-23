// http://www.techgaun.com
//by samar @ www.techgaun.com
#include <stdio.h>
#include <regex.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	regex_t re;
	FILE *fp;
	int r;
	short int found = 0;
	char *line = NULL;
	char inp[1024];
	size_t len = 0;
	ssize_t read;
	if (argc < 2)
	{
		printf("Usage: %s <filename>\n\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "rb")) == NULL)
	{
		perror("Unable to open the specified file.\n\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter the string to test: ");
	//scanf("%s", inp);
	fgets(inp, sizeof(inp), stdin);

	while ((read = getline(&line, &len, fp)) != -1)
	{
		
        	if ((r = regcomp(&re, line, REG_EXTENDED | REG_NEWLINE)) != 0)
		{
			printf("Invalid regular expression %s\n", line);
			regfree(&re);
			continue;
		}
		r = regexec(&re, inp, 0, NULL, 0);
		
		if (r == 0)
		{
			printf("Given string %s matched regex %s\n\n", inp, line);
			found = 1;
		}
		/*else if (r == REG_NOMATCH)
		{
			printf("Given string %s did not match regex %s\n\n", inp, line);
		}*/
		regfree(&re);
        }

	if (found == 0)
	{
		printf("No RE is matched with given string\n\n");
	}
	
	fclose(fp);
	return 0;
}