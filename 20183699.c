/*
20183699�����
LAB8.�����޸�2(�ڱ����� ����ü)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

struct node
{
	int value;
	struct node*next;
};
typedef struct node NODE;
typedef NODE* LINK;

LINK CreateNode(int a);//�������Լ�
LINK Append(LINK head, LINK cur);//��� �߰��Լ�(�ǳ���)
void Printlist(LINK head);//���Ḯ��Ʈ ����Լ�
int Countlist(LINK head);//��尳�� �Լ�
void Medium(LINK head, int cnt);//�߰���ġ�� �ִ� �ڷ��� �� ��� �Լ�
LINK Reverse(LINK head);//���� �Լ�
void Delete(LINK head, int cnt);//Ȧ����° �ڷ� �����Լ�  

int main()
{
	LINK head = NULL;
	LINK cur;
	int a;
	printf("�Է��ڷ�(������)�� �Է��ϼ���. �Է��� �����ϰ� �ʹٸ� CTRL-Z�� Enter�� 3�� �Է��ϼ���>>\n");
	while (1)
	{
		printf("������:");
		scanf("%d", &a);
		if (feof(stdin))
			break;
		cur = CreateNode(a);
		head = Append(head, cur);
	}

	printf("�Է��ڷḦ �Է� ������ ���:");
	Printlist(head);
	int cnt = Countlist(head);
	printf("\n�Էµ� �ڷ��� ������ ���:%d\n", cnt);
	printf("�Է��ڷ��� �߰���ġ�� �ִ� �ڷ��� �� ���:");
	Medium(head, cnt);
	printf("\n");
	LINK headrev = Reverse(head);
	printf("�Է��ڷḦ �Է� �������� ���: ");
	Printlist(headrev);
	printf("\n");
	head = Reverse(headrev);
	printf("�Է��ڷῡ�� Ȧ����° �ڷḦ ��� ����\n�����ڷḦ������� ���: ");
	Delete(head, cnt);
	return 0;
}

LINK CreateNode(int a)//�������Լ�
{
	LINK cur;
	cur = (LINK)malloc(sizeof(NODE));
	cur->value = (int)malloc(sizeof(int));
	cur->value = a;
	cur->next = NULL;
	return cur;
}

LINK Append(LINK head, LINK cur)//��� �߰��Լ�(�ǳ���)
{
	LINK nextNode = head;
	if (head == NULL)
	{
		head = cur;
		return head;
	}
	while (nextNode->next != NULL)
	{
		nextNode = nextNode->next;
	}
	nextNode->next = cur;
	return head;
}

void Printlist(LINK head)//���Ḯ��Ʈ ����Լ�
{
	LINK nextNode = head;
	while (nextNode != NULL)
	{
		printf("%d ", nextNode->value);
		nextNode = nextNode->next;
	}
}

int Countlist(LINK head)//��尳�� �Լ�
{
	int cnt = 0;
	LINK nextNode = head;
	while (nextNode != NULL)
	{
		nextNode = nextNode->next;
		cnt++;
	}
	return cnt;
}

void Medium(LINK head, int cnt)//�߰���ġ�� �ִ� �ڷ��� �� ��� �Լ�
{
	LINK nextNode = head;
	if (cnt % 2 == 1)
	{
		for (int i = 1; i < (cnt + 1) / 2; i++)
			nextNode = nextNode->next;
		printf("%d", nextNode->value);
	}
	else
	{
		for (int i = 1; i < cnt / 2; i++)
			nextNode = nextNode->next;
		printf("�߰���:%d ", nextNode->value);
		nextNode = nextNode->next;
		printf("%d", nextNode->value);
	}
}

LINK Reverse(LINK head)//���� �Լ�
{
	LINK p, q, r;
	p = head;
	r = NULL;
	q = NULL;
	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->next;
		q -> next = r;
	}
	return q;
}

void Delete(LINK head, int cnt)//Ȧ����° �ڷ� �����Լ�  
{
	LINK nextNode = head;
	LINK remove = head;
	head = head->next;
	for (int i = 1; i <cnt; i++)
	{
		if (i % 2 == 0)
		{
			remove = remove->next;
			nextNode->next = remove->next;

		}
		else
		{
			remove = remove->next;
			nextNode = nextNode->next;
		}
	}
	Printlist(head);
}