#include <stdio.h>
#include <string.h>
int main()
{
	char a[3][10];
	char string[10];
	int i;
	for (i = 0; i < 3; i++)
	{
		gets(a[i]);
	}
	if (strcmp(a[0], a[1]) > 0)
	{
		strcpy(string, a[0]);
	}
	else
	{
		strcpy(string, a[1]);
	}
	if (strcmp(a[2], string) > 0)
	{
		strcpy(string, a[2]);
	}
	printf("%s", string);
}
