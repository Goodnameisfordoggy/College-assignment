#include <stdio.h>
int main()
{
	int x, y, max, stu_order;
	int a[4][5];
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 5; x++)
		{
			scanf("%d", &a[y][x]);
		}
	}
	/*for(y=0;y<4;y++)
	{
		for(x=0;x<5;x++)
		{
			printf("%d ",a[y][x]);
		}
		printf("\n");
	}*/
	float b[4];
	float aver;
	int j;
	for (j = 0, y = 0; j < 4, y < 4; j++, y++)
	{
		b[j] = (a[y][0] + a[y][1] + a[y][2] + a[y][3] + a[y][4]) / 5.0;
	}
	/*for(j=0;j<4;j++)
	{
		printf("%7.2f\n",b[j]);
	}*/
	aver = b[0];
	for (j = 0; j < 4; j++)
	{
		if (b[j] > aver)
		{
			aver = b[j];
			stu_order = j;
		}
	}

	printf("stu_order=%d\nmax=%7.2f", stu_order, aver);
}