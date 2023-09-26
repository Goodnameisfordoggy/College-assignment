#include <stdio.h>

int main()
{
	struct Student
	{
		long NO;
		char name[20];
		char sex;
		char address[20];
	} a = {10101, "Li Lin", 'M', "123 Beijing Road"};
	printf("NO.:%ld\nname:%s\nsex:%c\naddress%s\n", a.NO, a.name, a.sex, a.address);
	return 0;
}
