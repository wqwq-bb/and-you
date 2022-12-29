//1.界面
//2.数据结构的设计
	//需求和数据结构揉和一起 
//3.交互
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct student
{
	char name[20];
	int age;
	char sex[5];
	char tel[20];
};
//分结构去写，用某一种数据结构去实现什么东西时，单独去写一种数据结构
//先把数据结构写对了再进行下一步

struct Node
{
	//int data;
	struct student data;
	struct Node* next;

};


// struct Node* list = createList();
struct Node* list;
struct Node* pMove = NULL;


//创建链表
struct Node* createList()
{
	//结构体变量表示表头
	//指针----> 变量    动态内存申请
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));//动态内存，便于存储变量
	//表头：做差异化处理-  数据域  data  不做初始化
	headNode->next = NULL;

	return headNode;
}

//创建结点
struct Node* createNode(struct student data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;

}
//插入结点
void insertNodeByHead(struct Node* headNode, struct student data)
{
	struct Node* newNode = createNode(data);
	// 头插法
	newNode->next = headNode->next;
	headNode->next = newNode;
	// 尾插法
	/*
	struct Node* posNode = headNode->next;
	while(posNode != NULL) {
		posNode = posNode->next;
	}
	posNode->next = newNode;
	*/
	// 插入自动排序, 按年龄的自然顺序
	struct Node* posNodefront = headNode;
	struct Node* posNode = headNode->next;
	while(1){
	if(posNode = NULL)
	 {
	posNode = posNode->next;
	posNode = newNode;
	break;
	 }
	 else if (posNode->data.age > posNode->next->data.age)
	 {
		posNodefront->next=posNodefront->next->next;
		posNode->next=posNode->next->next;
		posNodefront->next->next=posNode;
	 }
	}
	 

}

//修改信息
correctNode(char name[20],int age,char sex[5],char tel[20])
{
	struct Node* pMove = headNode->next;
	if (pMove == NULL)
		return NULL;
	while (strcmp(pMove->data.name, name))
	{
		pMove = pMove->next;
	}
	pMove->data.age = age;
	pMove->data.name = name;
	pMove->data.sex = sex;
	pMove->data.tel = tel;


	return pMove;

}


//指定位置删除
void deleteAppoinNode(struct Node* headNode, char* name)
{
	struct Node* posNode = headNode->next;
	struct Node* posNodefront = headNode;
	while (strcmp(posNode->data.name, name))//当两个字符串相等是，返回值为0（strcmp）
	{
		posNode = posNode->next;
		posNodefront = posNodefront->next;
		if (posNode == NULL)
		{
			printf("没有找到相关信息，无法删除");
			break;
		}
	}
	posNodefront->next = posNode->next;
	free(posNode);
}

//查找功能
struct Node* searchInforByData(struct Node* headNode, char* name)
{
	struct Node* pMove = headNode->next;
	if (pMove == NULL)
		return NULL;
	while (strcmp(pMove->data.name, name))
	{
		pMove = pMove->next;
	}
	return pMove;
}

//打印链表
void printList(struct Node* headNode)
{
	struct Node* pMove = headNode->next;
	//涉及到数据的设计
	printf("姓名\t年龄\t性别\t电话\n");
	while (pMove)
	{
		printf("%s\t%d\t%s\t%s\n", pMove->data.name, 
		pMove->data.age, pMove->data.sex, pMove->data.tel);

		pMove = pMove->next;

	}
	printf("\n");
}

//数据的设计----->学生信息抽象出

void menu()
{
	//所有操作同步到文件
	printf("---------------------------【学生管理系统】--------------------\n");
	printf("\t\t0.退出系统\n");
	printf("\t\t1.录入信息\n");
	printf("\t\t2.浏览信息\n");
	printf("\t\t3.修改信息\n");
	printf("\t\t4.删除信息\n");
	printf("\t\t5.查找信息\n");

	printf("\t\t5.浏览信息(男生)\n");
	printf("\t\t5.浏览信息(女生)\n");
	printf("\t\t5.浏览信息(按电话排序)\n");
	// 插入自动排序, 按年龄的自然顺序

	printf("----------------------------------------------------------------\n");


}

//用户的交互，根据所选的菜单项，做相应的事情
void KeyDown()
{
	int choice = 0;
	struct student data;
	scanf("%d", &choice);
	switch (choice)
	{
	case 0:
		printf("正常退出\n");
		system("pause");
		exit(0);
		break;

	case 1:
		printf("------------------------------【录入信息】---------------------------\n");
		printf("请输入学生姓名，年龄，性别，电话：\n ");

		scanf("%s%d%s%s", data.name, &data.age, data.sex, data.tel);
		insertNodeByHead(list, data);
		break;
	case 2:
		printf("------------------------------【浏览信息】---------------------------\n");
		printList(list);
		break;
	case 3:
		printf("------------------------------【修改信息】---------------------------\n");
		printf("请输入修改的学生姓名，年龄，性别，电话");
		scanf("%s%d%s%s", data.name, &data.age, data.sex, data.tel);
		break;
	case 4:
		printf("------------------------------【删除信息】---------------------------\n");
		printf("请输入删除的学生姓名");
		scanf("%s", data.name);
		deleteAppoinNode(list, data.name);
		break;
	case 5:
		printf("------------------------------【查找信息】---------------------------\n");
		printf("请输入查找的学生姓名");
		scanf("%s", data.name);
		pMove = searchInforByData(list, data.name);
		if (pMove = NULL)
		{
			printf("未找到相关信息，无法查询");
			system("pause");
		}
		else
		{
			printf("姓名\t年龄\t性别\t电话\n");
			printf("%s\t%d\t%s\t%s\n",
				pMove->data.name, pMove->data.age, pMove->data.sex, pMove->data.tel);
		}
		break;
	default:
		printf("选择错误，重新输入\n");
		system("pause");
		break;
	}
}



int main()
{
	SetConsoleOutputCP(65001);

	// struct Node* list = createList();
	list = createList();
	while (1)
	{
		menu();
		KeyDown();
		system("pause");
		system("cls");

	}


	system("pause");
	return 0;


}