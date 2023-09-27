#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
	char number[10];  // 登录号
	char name[20];	  // 书名
	char author[20];  // 作者名
	char publish[50]; // 出版单位
	char time[20];	  // 出版时间
	char fenlei[10];  // 分类名
	float price;	  // 图书价格
} mbook;
typedef struct
{
	int count;		 // 书的本数
	mbook book[100]; // 最大可有100本书
} mlibrary;
mlibrary library;
void save() // 保存图书信息。
{
	FILE *fp;
	if ((fp = fopen("c:/data.txt", "w")) == NULL)
	{
		printf("\n不能保存图书信息\n");
		return;
	}
	fwrite(&library.count, sizeof(int), 1, fp);
	fwrite(library.book, sizeof(library.book[0]), library.count, fp);
}
void putin() // 录入的图书信息
{
	int y = 1, flag = 0;
	int m;
	system("cls");
	while (y)
	{
		do
		{
			printf("\t请输入您的书籍的书号:");
			scanf("%s", library.book[library.count].number);
			for (m = 0; m < library.count; m++)
			{
				if (strcmp(library.book[library.count].number, library.book[m].number) == 0) // 判断当前录入的书号是否已经存在，如果已经存在，则提示用户输入的书号重复，需要重新输入。
				{																			 // 如果录入的书号不存在，则将当前图书信息存储到 library.book[library.count] 中，并将 library.count 值加 1。
					printf("书号重复了，请您重新输入!\n");
					flag = 1;
					break;
				}
				else
					flag = 0;
			}
		} while (flag);
		printf("\t请输入书名:");
		scanf("%s", library.book[library.count].name);
		printf("\t请输入作者名:");
		scanf("%s", library.book[library.count].author);
		printf("\t请输入出版社:");
		scanf("%s", library.book[library.count].publish);
		printf("\t请输入出版时间:");
		scanf("%s", library.book[library.count].time);
		printf("\t请输入分类名:");
		scanf("%s", library.book[library.count].fenlei);
		printf("\t请输入该书的价格:");
		fflush(stdin);
		scanf("%f", &library.book[library.count].price);
		library.count++;
		printf("\n是否继续录入(1.继续;0,退出录入):");
		fflush(stdin); // 刷新标准输入缓冲区,释放空间
		scanf("%d", &y);
		if (y != 1)
		{
			y = 0;
			break;
		}
	}
	save(); // 程序调用 save() 函数将所有录入的图书信息保存到文件中。
}
void lookup()
{
	int i;
	system("cls");
	printf("登录号    书名    作者名    出版单位    出版时间    分类名    图书价格\n");
	for (i = 0; i < library.count; i++) // 输出所有图书信息
	{
		printf("%s    %s    %s    %s    %s    %s    %6.2f\n", library.book[i].number, library.book[i].name, library.book[i].author, library.book[i].publish, library.book[i].time, library.book[i].fenlei, library.book[i].price);
	}
	fflush(stdin); // 暂停程序的执行，等待用户输入任意字符后才会继续执行,确保用户看到全部信息
	getchar();
}
void search_by_name()
{
	int i;
	char s2[20];
	int flag = 1;
	printf("\n请输入要查询的书名: ");
	fflush(stdin);
	scanf("%s", s2);
	printf("图书号    图书名    作者名    出版社    出版日期    图书价格\n");
	for (i = 0; i < library.count; i++) // 在遍历 book 数组时，寻找符合条件的图书信息(书名)
		if (strcmp(s2, library.book[i].name) == 0)
		{
			flag = 0;
			printf("%s    %s    %s    %s    %s    %6.2f\n", library.book[i].number, library.book[i].name, library.book[i].author, library.book[i].publish, library.book[i].time, library.book[i].price);
		}
	if (flag)
	{
		printf("cannot found!");
	}
	fflush(stdin);
	getchar();
}
void search_by_author()
{
	char s3[20];
	int i;
	int flag = 1;
	printf("请输入要查询的书的作者: ");
	fflush(stdin);
	scanf("%s", s3);
	printf("图书号    图书名    作者名    出版社    出版日期    分类名    图书价格\n");
	for (i = 0; i < library.count; i++) // 在遍历 book 数组时，寻找符合条件的图书信息(作者)
		if (strcmp(s3, library.book[i].author) == 0)
		{
			flag = 0;
			printf("%s    %s    %s    %s    %s    %s    %6.2f\n", library.book[i].number, library.book[i].name, library.book[i].author, library.book[i].publish, library.book[i].time, library.book[i].fenlei, library.book[i].price);
		}
	if (flag)
	{
		printf("cannot found!");
	}
	fflush(stdin);
	getchar();
}
void search() // 查询方式集合
{
	int a;
	system("cls"); /*进行清屏*/
	printf("\t\t******************************\n");
	printf("\t\t开始查询\n");
	printf("\t\t1---------------根据书名\n");
	printf("\t\t2---------------根据作者\n");
	printf("\t\t0---------------退出\n");
	printf("\t\t******************************\n");
	printf("\t\t请选择你想要的查询方式:");
	fflush(stdin);
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		search_by_name();
		break;
	case 2:
		search_by_author();
		break;
	case 0:
		return;
	}
}
void del() // 删除指定登录号的图书信息
{
	int i;
	char number[10];
	system("cls"); /*清屏*/
	printf("\n   请输入您想要删除的图书书号:");
	fflush(stdin);
	scanf("%s", number);
	for (i = 0; i < library.count; i++) // 遍历 book 数组，查找指定登录号的图书信息。如果找到了符合条件的图书信息，则将该图书信息从 book 数组中删除；如果没有找到符合条件的图书，则输出错误提示信息
	{
		if (strcmp(number, library.book[i].number) == 0)
			break;
	}
	if (i != library.count)
	{
		for (; i < library.count - 1; i++)
		{
			strcpy(library.book[i].name, library.book[i + 1].name);
			strcpy(library.book[i].number, library.book[i + 1].number);
			strcpy(library.book[i].publish, library.book[i + 1].publish);
			strcpy(library.book[i].author, library.book[i + 1].author);
			strcpy(library.book[i].time, library.book[i + 1].time);
			strcpy(library.book[i].fenlei, library.book[i + 1].fenlei);
			library.book[i].price = library.book[i + 1].price;
		}
		library.count--;
	}
	else
		printf("\n cannot found!\n");
	save(); // 将删除的图书信息保存到文件中。
	fflush(stdin);
	getchar();
}
void update() // 更新指定登录号的图书信息
{
	int i;
	char number[10];
	system("cls"); /*清屏*/
	printf("\n   请输入您想要更新的图书书号:");
	fflush(stdin);
	scanf("%s", number);
	for (i = 0; i < library.count; i++) // 遍历输出当前全部图书信息
	{
		if (strcmp(number, library.book[i].number) == 0)
		{
			printf("图书号    图书名    作者名    出版社    出版日期    分类名    图书价格\n");
			printf("%s    %s    %s    %s    %s    %s    %6.2f\n", library.book[i].number, library.book[i].name, library.book[i].author, library.book[i].publish, library.book[i].time, library.book[i].fenlei, library.book[i].price);
			break;
		}
	}
	if (i != library.count) // 信息逐条修改操作
	{
		mbook book;
		printf("\n\t\t请输入修改后此图书的信息\n");
		printf("\t请输入图书号:");
		scanf("%s", book.number);
		printf("\t请输入图书名:");
		scanf("%s", book.name);
		printf("\t请输入作者名:");
		scanf("%s", book.author);
		printf("\t请输入出版社:");
		scanf("%s", book.publish);
		printf("\t请输入出版时间:");
		scanf("%s", book.time);
		printf("\t请输入分类名:");
		scanf("%s", book.fenlei);
		printf("\t请输入该书的价格:");
		fflush(stdin);
		scanf("%f", &book.price);
		strcpy(library.book[i].name, book.name);
		strcpy(library.book[i].number, book.number);
		strcpy(library.book[i].publish, book.publish);
		strcpy(library.book[i].author, book.author);
		strcpy(library.book[i].time, book.time);
		strcpy(library.book[i].fenlei, book.fenlei);
		library.book[i].price = book.price;
		save();
	}
	else
		printf("\n cannot found!\n");
	fflush(stdin);
	getchar();
}
int main()
{
	int a;
	do // 用户界面格式控制
	{
		system("cls");
		printf("\n\n\n\n\n\t\t\t\t图书信息管理系统\t\t\t\t\n");
		printf("\t\t**********************************************\n");
		printf("\t\t*\t1 ------------------图书信息录入     *\n");
		printf("\t\t*\t2 ------------------图书信息浏览     *\n");
		printf("\t\t*\t3 ------------------图书信息查询     *\n");
		printf("\t\t*\t4 ------------------图书信息删除     *\n");
		printf("\t\t*\t5 ------------------图书信息修改     *\n");
		printf("\t\t*\t0 ------------------退出图书信息系统 *\n");
		printf("\t\t**********************************************\n");
		printf("\t         制作人: HDJ \n");
		printf("\t\tPlease Enter Choose: ");
		fflush(stdin);
		scanf("%d", &a);
		switch (a)
		{
		case 1: // 图书信息录入
			putin();
			break;
		case 2: // 图书信息浏览
			lookup();
			break;
		case 3: // 按照需求搜索图书信息
			search();
			break;
		case 4: // 删除指定登录号的图书信息
			del();
			break;
		case 5: // 修改指定登录号的图书信息
			update();
			break;
		case 0: // 退出系统
			printf("\n\n退出\n\n");
			break;
		default:
			printf("\n序号不对\n");
		}
	} while (a != 0);
	save(); // 保存用户信息
}
