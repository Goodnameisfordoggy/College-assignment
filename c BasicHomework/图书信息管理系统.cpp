#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
	char number[10];  // ��¼��
	char name[20];	  // ����
	char author[20];  // ������
	char publish[50]; // ���浥λ
	char time[20];	  // ����ʱ��
	char fenlei[10];  // ������
	float price;	  // ͼ��۸�
} mbook;
typedef struct
{
	int count;		 // ��ı���
	mbook book[100]; // ������100����
} mlibrary;
mlibrary library;
void save() // ����ͼ����Ϣ��
{
	FILE *fp;
	if ((fp = fopen("c:/data.txt", "w")) == NULL)
	{
		printf("\n���ܱ���ͼ����Ϣ\n");
		return;
	}
	fwrite(&library.count, sizeof(int), 1, fp);
	fwrite(library.book, sizeof(library.book[0]), library.count, fp);
}
void putin() // ¼���ͼ����Ϣ
{
	int y = 1, flag = 0;
	int m;
	system("cls");
	while (y)
	{
		do
		{
			printf("\t�����������鼮�����:");
			scanf("%s", library.book[library.count].number);
			for (m = 0; m < library.count; m++)
			{
				if (strcmp(library.book[library.count].number, library.book[m].number) == 0) // �жϵ�ǰ¼�������Ƿ��Ѿ����ڣ�����Ѿ����ڣ�����ʾ�û����������ظ�����Ҫ�������롣
				{																			 // ���¼�����Ų����ڣ��򽫵�ǰͼ����Ϣ�洢�� library.book[library.count] �У����� library.count ֵ�� 1��
					printf("����ظ��ˣ�������������!\n");
					flag = 1;
					break;
				}
				else
					flag = 0;
			}
		} while (flag);
		printf("\t����������:");
		scanf("%s", library.book[library.count].name);
		printf("\t������������:");
		scanf("%s", library.book[library.count].author);
		printf("\t�����������:");
		scanf("%s", library.book[library.count].publish);
		printf("\t���������ʱ��:");
		scanf("%s", library.book[library.count].time);
		printf("\t�����������:");
		scanf("%s", library.book[library.count].fenlei);
		printf("\t���������ļ۸�:");
		fflush(stdin);
		scanf("%f", &library.book[library.count].price);
		library.count++;
		printf("\n�Ƿ����¼��(1.����;0,�˳�¼��):");
		fflush(stdin); // ˢ�±�׼���뻺����,�ͷſռ�
		scanf("%d", &y);
		if (y != 1)
		{
			y = 0;
			break;
		}
	}
	save(); // ������� save() ����������¼���ͼ����Ϣ���浽�ļ��С�
}
void lookup()
{
	int i;
	system("cls");
	printf("��¼��    ����    ������    ���浥λ    ����ʱ��    ������    ͼ��۸�\n");
	for (i = 0; i < library.count; i++) // �������ͼ����Ϣ
	{
		printf("%s    %s    %s    %s    %s    %s    %6.2f\n", library.book[i].number, library.book[i].name, library.book[i].author, library.book[i].publish, library.book[i].time, library.book[i].fenlei, library.book[i].price);
	}
	fflush(stdin); // ��ͣ�����ִ�У��ȴ��û����������ַ���Ż����ִ��,ȷ���û�����ȫ����Ϣ
	getchar();
}
void search_by_name()
{
	int i;
	char s2[20];
	int flag = 1;
	printf("\n������Ҫ��ѯ������: ");
	fflush(stdin);
	scanf("%s", s2);
	printf("ͼ���    ͼ����    ������    ������    ��������    ͼ��۸�\n");
	for (i = 0; i < library.count; i++) // �ڱ��� book ����ʱ��Ѱ�ҷ���������ͼ����Ϣ(����)
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
	printf("������Ҫ��ѯ���������: ");
	fflush(stdin);
	scanf("%s", s3);
	printf("ͼ���    ͼ����    ������    ������    ��������    ������    ͼ��۸�\n");
	for (i = 0; i < library.count; i++) // �ڱ��� book ����ʱ��Ѱ�ҷ���������ͼ����Ϣ(����)
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
void search() // ��ѯ��ʽ����
{
	int a;
	system("cls"); /*��������*/
	printf("\t\t******************************\n");
	printf("\t\t��ʼ��ѯ\n");
	printf("\t\t1---------------��������\n");
	printf("\t\t2---------------��������\n");
	printf("\t\t0---------------�˳�\n");
	printf("\t\t******************************\n");
	printf("\t\t��ѡ������Ҫ�Ĳ�ѯ��ʽ:");
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
void del() // ɾ��ָ����¼�ŵ�ͼ����Ϣ
{
	int i;
	char number[10];
	system("cls"); /*����*/
	printf("\n   ����������Ҫɾ����ͼ�����:");
	fflush(stdin);
	scanf("%s", number);
	for (i = 0; i < library.count; i++) // ���� book ���飬����ָ����¼�ŵ�ͼ����Ϣ������ҵ��˷���������ͼ����Ϣ���򽫸�ͼ����Ϣ�� book ������ɾ�������û���ҵ�����������ͼ�飬�����������ʾ��Ϣ
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
	save(); // ��ɾ����ͼ����Ϣ���浽�ļ��С�
	fflush(stdin);
	getchar();
}
void update() // ����ָ����¼�ŵ�ͼ����Ϣ
{
	int i;
	char number[10];
	system("cls"); /*����*/
	printf("\n   ����������Ҫ���µ�ͼ�����:");
	fflush(stdin);
	scanf("%s", number);
	for (i = 0; i < library.count; i++) // ���������ǰȫ��ͼ����Ϣ
	{
		if (strcmp(number, library.book[i].number) == 0)
		{
			printf("ͼ���    ͼ����    ������    ������    ��������    ������    ͼ��۸�\n");
			printf("%s    %s    %s    %s    %s    %s    %6.2f\n", library.book[i].number, library.book[i].name, library.book[i].author, library.book[i].publish, library.book[i].time, library.book[i].fenlei, library.book[i].price);
			break;
		}
	}
	if (i != library.count) // ��Ϣ�����޸Ĳ���
	{
		mbook book;
		printf("\n\t\t�������޸ĺ��ͼ�����Ϣ\n");
		printf("\t������ͼ���:");
		scanf("%s", book.number);
		printf("\t������ͼ����:");
		scanf("%s", book.name);
		printf("\t������������:");
		scanf("%s", book.author);
		printf("\t�����������:");
		scanf("%s", book.publish);
		printf("\t���������ʱ��:");
		scanf("%s", book.time);
		printf("\t�����������:");
		scanf("%s", book.fenlei);
		printf("\t���������ļ۸�:");
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
	do // �û������ʽ����
	{
		system("cls");
		printf("\n\n\n\n\n\t\t\t\tͼ����Ϣ����ϵͳ\t\t\t\t\n");
		printf("\t\t**********************************************\n");
		printf("\t\t*\t1 ------------------ͼ����Ϣ¼��     *\n");
		printf("\t\t*\t2 ------------------ͼ����Ϣ���     *\n");
		printf("\t\t*\t3 ------------------ͼ����Ϣ��ѯ     *\n");
		printf("\t\t*\t4 ------------------ͼ����Ϣɾ��     *\n");
		printf("\t\t*\t5 ------------------ͼ����Ϣ�޸�     *\n");
		printf("\t\t*\t0 ------------------�˳�ͼ����Ϣϵͳ *\n");
		printf("\t\t**********************************************\n");
		printf("\t         ������: HDJ \n");
		printf("\t\tPlease Enter Choose: ");
		fflush(stdin);
		scanf("%d", &a);
		switch (a)
		{
		case 1: // ͼ����Ϣ¼��
			putin();
			break;
		case 2: // ͼ����Ϣ���
			lookup();
			break;
		case 3: // ������������ͼ����Ϣ
			search();
			break;
		case 4: // ɾ��ָ����¼�ŵ�ͼ����Ϣ
			del();
			break;
		case 5: // �޸�ָ����¼�ŵ�ͼ����Ϣ
			update();
			break;
		case 0: // �˳�ϵͳ
			printf("\n\n�˳�\n\n");
			break;
		default:
			printf("\n��Ų���\n");
		}
	} while (a != 0);
	save(); // �����û���Ϣ
}
