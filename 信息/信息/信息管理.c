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

//1.输入学生信息记录
void input();
//2.查找学生信息
void find();
//3.删除学生信息
void delete();
//4.修改学生信息
void modify();
//5.按要求排序
void sort();
//6.显示信息记录
void display();
//保存数据
void load();
//加载数据
void read();

ST students[MAX_students];
int numstudent = 0;

int main()
{
	int choice = 1;
	while (choice != 0)
	{
		printf("0.退出\n");
		printf("1.输入学生信息记录\n");
		printf("2.查找学生信息\n");
		printf("3.删除学生信息\n");
		printf("4.修改学生信息\n");
		printf("5.按要求排序\n");
		printf("6.显示信息记录\n");
		printf("7.保存数据\n");
		printf("8.加载数据\n");
		printf("请输入操作：\n");
		scanf_s("%d", &choice);
		printf("------------------------\n");
		switch (choice)
		{
		case 0:
			printf("退出程序");
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
//1.添加信息
void input()
{
	if (numstudent >= MAX_students)
	{
		printf("学生数量达到最大，无法添加记录");
		return;
	}
	ST student;
	printf("请输入姓名：\n");
	scanf_s("%99s", student.name, (unsigned int)sizeof(student.name));
	printf("请输入学号：\n");
	scanf_s("%d", &student.ID);
	printf("请输入年龄：\n");
	scanf_s("%d", &student.age);
	printf("请输入年级：\n");
	scanf_s("%d", &student.grade);
	students[numstudent] = student;
	numstudent++;
	printf("学生信息添加成功\n");
}

//2.查找信息
void find()
{
	int choice;
	printf("1.按姓名查询\n");
	printf("2.按学号查询\n");
	printf("3.按年龄查询\n");
	printf("4.按年级查询\n");
	printf("请输入要进行的操作：");
	scanf_s("%d", &choice);
	if (choice == 1)
	{
		char findname[50];
		printf("请输入学生姓名：\n");
		scanf_s("%99s", findname, (unsigned int)sizeof(findname));
		ST student;
		for (int i = 0; i < numstudent; i++)
		{
			student = students[i];
			if (student.name == findname)
			{
				printf("姓名：%s\n", student.name);
				printf("学号：%d\n", student.ID);
				printf("年龄：%d\n", student.age);
				printf("年级：%d\n", student.grade);
				return;
			}
			else
			{
				printf("查询不到该名学生\n");
			}
		}
	}
	else if (choice == 2)
	{
		int ID;
		printf("请输入学号：\n");
		scanf_s("%d", &ID);
		ST student;
		for (int i = 0; i < numstudent; i++)
		{
			student = students[i];
			if (student.ID == ID)
			{
				printf("姓名：%s\n", student.name);
				printf("学号：%d\n", student.ID);
				printf("年龄：%d\n", student.age);
				printf("年级：%d\n", student.grade);
				return;
			}
			else
			{
				printf("查询不到该名学生\n");
			}
		}
	}
	else if (choice == 3)
	{
		int age;
		printf("请输入年龄：\n");
		scanf_s("%d", &age);
		ST student;
		for (int i = 0; i < numstudent; i++)
		{
			student = students[i];
			if (student.age == age)
			{
				printf("姓名：%s\n", student.name);
				printf("学号：%d\n", student.ID);
				printf("年龄：%d\n", student.age);
				printf("年级：%d\n", student.grade);
			}
			else
			{
				printf("查询不到该名学生\n");
			}
		}
	}
	else if (choice == 4)
	{
		int grade;
		printf("请输入年级：\n");
		scanf_s("%d", &grade);
		ST student;
		for (int i = 0; i < numstudent; i++)
		{
			student = students[i];
			if (student.grade == grade)
			{
				printf("姓名：%s\n", student.name);
				printf("学号：%d\n", student.ID);
				printf("年龄：%d\n", student.age);
				printf("年级：%d\n", student.grade);
				return;
			}
			else
			{
				printf("查询不到该名学生\n");
			}
		}
	}
	else
	{
		printf("无效操作");
	}
}

//3.删除学生信息
void delete()
{
	int ID;
	printf("请输入要删除的学生学号：");
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
			printf("未找到该学号的学生，删除失败\n");
		}
	}
}
//4.修改信息
void modify()
{
	int ID;
	printf("请输入要修改信息的学生姓名：");
	scanf_s("%d", &ID);
	int choice = 1;
	for (int i = 0; i < numstudent; i++)
	{
		if (students[i].ID == ID)
		{
			printf("1.修改名字\n");
			printf("2.修改学号\n");
			printf("3.修改年龄\n");
			printf("4.修改年级\n");
			scanf_s("%d", &choice);
			printf("------------------------\n");
			switch (choice)
			{
			case 1:
				printf("请输入修改的名字：\n");
				scanf_s("%99s", students[i].name, (unsigned int)sizeof(students[i].name));
				break;
			case 2:
				printf("请输入修改的学号：\n");
				scanf_s("%d", &students[i].ID);
				break;
			case 3:
				printf("请输入修改的年龄：\n");
				scanf_s("%d", &students[i].age);
				break;
			case 4:
				printf("请输入修改的年级：\n");
				scanf_s("%d", &students[i].grade);
				break;
			}
			printf("--------------------");

			return;
		}
		else
		{
			printf("未找到该名学生，修改失败\n");
		}
	}
}


//5.排序
void sort()
{
	ST student;
	int choice = 1;
	for (int i = 0; i < numstudent; i++)
	{
		printf("1.按姓名排序\n");
		printf("2.按学号排序\n");
		printf("3.按年龄排序\n");
		printf("4.按年级排序\n");
		scanf_s("%d", &choice);
		printf("------------------------\n");
		switch (choice)
		{
		case 1:     //姓名
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
		case 2:      //学号
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
		case 3:     //年龄
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
		case 4:     //年级
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
	printf("成功排序\n");
}

//6.显示学生信息
void display()
{
	printf("姓名： 学号： 年龄： 年级：\n");
	for (int i = 0; i < numstudent; i++)
	{
		ST student = students[i];
		printf("%s %d %d %d\n", student.name, student.ID, student.age, student.grade);
	}

}
//保存数据
void load()
{
	
	FILE* file = fopen("C:\\Users\\李离\\Desktop\\a.txt.txt", "w");
	for (int i = 0; i < numstudent; i++)
	{
		fprintf(file,"%s",students[i].name);
		fprintf(file, "%d", students[i].ID);
		fprintf(file, "%d", students[i].age);
		fprintf(file,"%d",students[i].grade);
    }
	fclose(file);
	printf("信息保存成功\n");
}

//加载信息
void read()
{
	FILE* file = fopen("C:\\Users\\李离\\Desktop\\a.txt.txt", "r");
	for (int i = 0; i < numstudent; i++)
	{
		fscanf_s(file, "%s", &students[i].name,(unsigned int)sizeof(students[i].name));
		fscanf_s(file, "%d", &students[i].ID);
		fscanf_s(file, "%d", &students[i].age);
		fscanf_s(file, "%d", &students[i].grade);
	}
	fclose(file);
}