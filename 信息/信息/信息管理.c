#include<stdio.h>
#include<string.h>
#define MAX_students 100
#define FILE_NAME "students.txt" 
typedef struct student
{
	char name[1000];
	int ID;
	int age;
	int grade;
}ST;

//1.����ѧ����Ϣ��¼
void input();
//2.����ѧ����Ϣ
void find();
//3.ɾ��ѧ����Ϣ
void delete();
//4.�޸�ѧ����Ϣ
void modify();
//5.��Ҫ������
void sort();
//6.��ʾ��Ϣ��¼
void display();
//��������
void load();
//��������
void read();

ST students[MAX_students];
int numstudent = 0;

int main()
{
	int choice = 1;
	while (choice != 0)
	{
		printf("0.�˳�\n");
		printf("1.����ѧ����Ϣ��¼\n");
		printf("2.����ѧ����Ϣ\n");
		printf("3.ɾ��ѧ����Ϣ\n");
		printf("4.�޸�ѧ����Ϣ\n");
		printf("5.��Ҫ������\n");
		printf("6.��ʾ��Ϣ��¼\n");
		printf("7.��������\n");
		printf("8.��������\n");
		printf("�����������\n");
		scanf_s("%d", &choice);
		printf("------------------------\n");
		switch (choice)
		{
		case 0:
			printf("�˳�����");
			break;
		case 1:
			input();
			break;
		case 2:
			find();
			break;
		case 3:
			delete();
			break;
		case 4:
			modify();
			break;
		case 5:
			sort();
			break;
		case 6:
			display();
			break;
		case 7:
			load();
			break;
		case 8:
			read();
			break;
		}
		printf("------------------------------\n");
	}
	return 0;
}
//1.�����Ϣ
void input()
{
	if (numstudent >= MAX_students)
	{
		printf("ѧ�������ﵽ����޷���Ӽ�¼");
		return;
	}
	ST student;
	printf("������������\n");
	scanf_s("%99s", student.name, (unsigned int)sizeof(student.name));
	printf("������ѧ�ţ�\n");
	scanf_s("%d", &student.ID);
	printf("���������䣺\n");
	scanf_s("%d", &student.age);
	printf("�������꼶��\n");
	scanf_s("%d", &student.grade);
	students[numstudent] = student;
	numstudent++;
	printf("ѧ����Ϣ��ӳɹ�\n");
}

//2.������Ϣ
void find()
{
	int choice;
	printf("1.��������ѯ\n");
	printf("2.��ѧ�Ų�ѯ\n");
	printf("3.�������ѯ\n");
	printf("4.���꼶��ѯ\n");
	printf("������Ҫ���еĲ�����");
	scanf_s("%d", &choice);
	if (choice == 1)
	{
		char findname[50];
		printf("������ѧ��������\n");
		scanf_s("%99s", findname, (unsigned int)sizeof(findname));
		ST student;
		for (int i = 0; i < numstudent; i++)
		{
			student = students[i];
			if (student.name == findname)
			{
				printf("������%s\n", student.name);
				printf("ѧ�ţ�%d\n", student.ID);
				printf("���䣺%d\n", student.age);
				printf("�꼶��%d\n", student.grade);
				return;
			}
			else
			{
				printf("��ѯ��������ѧ��\n");
			}
		}
	}
	else if (choice == 2)
	{
		int ID;
		printf("������ѧ�ţ�\n");
		scanf_s("%d", &ID);
		ST student;
		for (int i = 0; i < numstudent; i++)
		{
			student = students[i];
			if (student.ID == ID)
			{
				printf("������%s\n", student.name);
				printf("ѧ�ţ�%d\n", student.ID);
				printf("���䣺%d\n", student.age);
				printf("�꼶��%d\n", student.grade);
				return;
			}
			else
			{
				printf("��ѯ��������ѧ��\n");
			}
		}
	}
	else if (choice == 3)
	{
		int age;
		printf("���������䣺\n");
		scanf_s("%d", &age);
		ST student;
		for (int i = 0; i < numstudent; i++)
		{
			student = students[i];
			if (student.age == age)
			{
				printf("������%s\n", student.name);
				printf("ѧ�ţ�%d\n", student.ID);
				printf("���䣺%d\n", student.age);
				printf("�꼶��%d\n", student.grade);
			}
			else
			{
				printf("��ѯ��������ѧ��\n");
			}
		}
	}
	else if (choice == 4)
	{
		int grade;
		printf("�������꼶��\n");
		scanf_s("%d", &grade);
		ST student;
		for (int i = 0; i < numstudent; i++)
		{
			student = students[i];
			if (student.grade == grade)
			{
				printf("������%s\n", student.name);
				printf("ѧ�ţ�%d\n", student.ID);
				printf("���䣺%d\n", student.age);
				printf("�꼶��%d\n", student.grade);
				return;
			}
			else
			{
				printf("��ѯ��������ѧ��\n");
			}
		}
	}
	else
	{
		printf("��Ч����");
	}
}

//3.ɾ��ѧ����Ϣ
void delete()
{
	int ID;
	printf("������Ҫɾ����ѧ��ѧ�ţ�");
	scanf_s("%d", &ID);
	ST student;
	for (int i = 0; i < numstudent; i++)
	{
		student = students[i];
		if (student.ID == ID)
		{
			students[i] = students[numstudent - 1];
			numstudent--;
			return;
		}
		else
		{
			printf("δ�ҵ���ѧ�ŵ�ѧ����ɾ��ʧ��\n");
		}
	}
}
//4.�޸���Ϣ
void modify()
{
	int ID;
	printf("������Ҫ�޸���Ϣ��ѧ��������");
	scanf_s("%d", &ID);
	int choice = 1;
	for (int i = 0; i < numstudent; i++)
	{
		if (students[i].ID == ID)
		{
			printf("1.�޸�����\n");
			printf("2.�޸�ѧ��\n");
			printf("3.�޸�����\n");
			printf("4.�޸��꼶\n");
			scanf_s("%d", &choice);
			printf("------------------------\n");
			switch (choice)
			{
			case 1:
				printf("�������޸ĵ����֣�\n");
				scanf_s("%99s", students[i].name, (unsigned int)sizeof(students[i].name));
				break;
			case 2:
				printf("�������޸ĵ�ѧ�ţ�\n");
				scanf_s("%d", &students[i].ID);
				break;
			case 3:
				printf("�������޸ĵ����䣺\n");
				scanf_s("%d", &students[i].age);
				break;
			case 4:
				printf("�������޸ĵ��꼶��\n");
				scanf_s("%d", &students[i].grade);
				break;
			}
			printf("--------------------");

			return;
		}
		else
		{
			printf("δ�ҵ�����ѧ�����޸�ʧ��\n");
		}
	}
}


//5.����
void sort()
{
	ST student;
	int choice = 1;
	for (int i = 0; i < numstudent; i++)
	{
		printf("1.����������\n");
		printf("2.��ѧ������\n");
		printf("3.����������\n");
		printf("4.���꼶����\n");
		scanf_s("%d", &choice);
		printf("------------------------\n");
		switch (choice)
		{
		case 1:     //����
			for (int i = 0; i < numstudent - 1; i++)
			{
				for (int j = 0; j < numstudent - i - 1; j++)
				{
					if (students[i].name > students[i + 1].name)
					{
						student = students[i];
						students[i] = students[i + 1];
						students[i + 1] = student;
					}
				}
			}
			break;
		case 2:      //ѧ��
			for (int i = 0; i < numstudent - 1; i++)
			{
				for (int j = 0; j < numstudent - i - 1; j++)
				{
					if (students[i].ID > students[i + 1].ID)
					{
						student = students[i];
						students[i] = students[i + 1];
						students[i + 1] = student;
					}
				}
			}
			break;
		case 3:     //����
			for (int i = 0; i < numstudent - 1; i++)
			{
				for (int j = 0; j < numstudent - i - 1; j++)
				{
					if (students[i].age > students[i + 1].age)
					{
						student = students[i];
						students[i] = students[i + 1];
						students[i + 1] = student;
					}
				}
			}
			break;
		case 4:     //�꼶
			for (int i = 0; i < numstudent - 1; i++)
			{
				for (int j = 0; j < numstudent - i - 1; j++)
				{
					if (students[i].grade > students[i + 1].grade)
					{
						student = students[i];
						students[i] = students[i + 1];
						students[i + 1] = student;
					}
				}
			}
			break;
		}
		printf("--------------------");
		return;
	}
	printf("�ɹ�����\n");
}

//6.��ʾѧ����Ϣ
void display()
{
	printf("������ ѧ�ţ� ���䣺 �꼶��\n");
	for (int i = 0; i < numstudent; i++)
	{
		ST student = students[i];
		printf("%s %d %d %d\n", student.name, student.ID, student.age, student.grade);
	}

}
//��������
void load()
{
	
	FILE* file = fopen("C:\\Users\\����\\Desktop\\a.txt.txt", "w");
	for (int i = 0; i < numstudent; i++)
	{
		fprintf(file,"%s",students[i].name);
		fprintf(file, "%d", students[i].ID);
		fprintf(file, "%d", students[i].age);
		fprintf(file,"%d",students[i].grade);
    }
	fclose(file);
	printf("��Ϣ����ɹ�\n");
}

//������Ϣ
void read()
{
	FILE* file = fopen("C:\\Users\\����\\Desktop\\a.txt.txt", "r");
	for (int i = 0; i < numstudent; i++)
	{
		fscanf_s(file, "%s", &students[i].name,(unsigned int)sizeof(students[i].name));
		fscanf_s(file, "%d", &students[i].ID);
		fscanf_s(file, "%d", &students[i].age);
		fscanf_s(file, "%d", &students[i].grade);
	}
	fclose(file);
}