#include <stdio.h>
#pragma warning(disable : 4996)
#include <string.h>
// Li Li Li Zhang Zhang Zhang Zhang Sun Sun Sun
struct person
{
	char name[20];
	int ticket;
} li = {"Li", 0}, zhang = {"Zhang", 0}, sun = {"Sun", 0};
int main()
{
	int i;
	char put_name[20], temp[20];
	for (i = 0; i < 10; i++)
	{
		scanf("%s", &put_name);
		if (strcmp(li.name, put_name) == 0)
		{
			li.ticket++;
		}
		if (strcmp(zhang.name, put_name) == 0)
		{
			zhang.ticket++;
		}
		if (strcmp(sun.name, put_name) == 0)
		{
			sun.ticket++;
		}
	}
	printf("\nResult:\n");
	printf("%5s:%d\n%5s:%d\n%5s:%d\n", li.name, li.ticket, zhang.name, zhang.ticket, sun.name, sun.ticket);
	return 0;
}