#include <stdio.h>
int main()
{
	char a[100];
	gets(a);
	int i, word = 1, num;
	for (i = 1; a[i] != '\0'; i++)
	{
		if (a[i] != ' ' && a[i - 1] == ' ')
		{
			word++;
		}
	}
	printf("num=%d", word);
	return 0;
}