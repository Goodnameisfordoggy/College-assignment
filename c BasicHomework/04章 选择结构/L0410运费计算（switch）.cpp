#include <stdio.h>
main()
{
	int s, a, g;
	float freight;
	// s路程 a单价  g重量 freight总运费
	scanf("%d,%d,%d", &a, &g, &s);
	switch (s / 250)
	{
	case 0:
		freight = a * g * s * (1 - 0);
		break;
	case 1:
		freight = a * g * s * (1 - 0.02);
		break;
	case 2:
	case 3:
		freight = a * g * s * (1 - 0.05);
		break;
	case 4:
	case 5:
	case 6:
	case 7:
		freight = a * g * s * (1 - 0.08);
		break;
	case 8:
	case 9:
	case 10:
	case 11:
		freight = a * g * s * (1 - 0.10);
		break;
	case 12:
		freight = a * g * s * (1 - 0.15);
		break;
	}
	printf("freight=%10.2f", freight);
	return 0;
}