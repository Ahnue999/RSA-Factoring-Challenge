#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

void getnum(FILE *fp);
int factor(long unsigned int n);

int main(int argc, char **argv)
{
	FILE *fp;

	if (argc != 2)
	{
		printf("wrong usage");
		return (0);
	}

	fp = fopen(argv[1], O_RDONLY);
	if (fp == NULL)
	{
		printf("Unable to open\n");
		exit(11);
	}
	getnum(fp);
	fclose(fp);

	return (0);
}

void getnum(FILE *fp)
{
	char *lineptr;
	size_t n;
	long unsigned int f;

	while (getline(&lineptr, &n, fp) != -1)
	{
		f = atoi(lineptr);
		factor(f);
		printf("got number");
	}
	free(lineptr);
}

int factor(long unsigned int n)
{
	long unsigned int i, j;

	printf("searching");
	for (i = 2; i <= n; i++)
	{
		for (j = 1; j <= n / i; j++)
		{
			if (i * j == n)
			{
				printf("%lu=%lu*%lu\n", n, i, j);
				return (1);
			}

		}
	}
	printf("error\n");
	return (0);
}
