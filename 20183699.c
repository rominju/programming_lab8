/*
20183699노민주
LAB8.동적메모리2(자기참조 구조체)
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

LINK CreateNode(int a);//노드생성함수
LINK Append(LINK head, LINK cur);//노드 추가함수(맨끝에)
void Printlist(LINK head);//연결리스트 출력함수
int Countlist(LINK head);//노드개수 함수
void Medium(LINK head, int cnt);//중간위치에 있는 자료의 값 출력 함수
LINK Reverse(LINK head);//역순 함수
void Delete(LINK head, int cnt);//홀수번째 자료 삭제함수  

int main()
{
	LINK head = NULL;
	LINK cur;
	int a;
	printf("입력자료(정수값)를 입력하세요. 입력을 종료하고 싶다면 CTRL-Z와 Enter을 3번 입력하세요>>\n");
	while (1)
	{
		printf("정수값:");
		scanf("%d", &a);
		if (feof(stdin))
			break;
		cur = CreateNode(a);
		head = Append(head, cur);
	}

	printf("입력자료를 입력 순으로 출력:");
	Printlist(head);
	int cnt = Countlist(head);
	printf("\n입력된 자료의 개수를 출력:%d\n", cnt);
	printf("입력자료의 중간위치에 있는 자료의 값 출력:");
	Medium(head, cnt);
	printf("\n");
	LINK headrev = Reverse(head);
	printf("입력자료를 입력 역순으로 출력: ");
	Printlist(headrev);
	printf("\n");
	head = Reverse(headrev);
	printf("입력자료에서 홀수번째 자료를 모두 삭제\n남은자료를순서대로 출력: ");
	Delete(head, cnt);
	return 0;
}

LINK CreateNode(int a)//노드생성함수
{
	LINK cur;
	cur = (LINK)malloc(sizeof(NODE));
	cur->value = (int)malloc(sizeof(int));
	cur->value = a;
	cur->next = NULL;
	return cur;
}

LINK Append(LINK head, LINK cur)//노드 추가함수(맨끝에)
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

void Printlist(LINK head)//연결리스트 출력함수
{
	LINK nextNode = head;
	while (nextNode != NULL)
	{
		printf("%d ", nextNode->value);
		nextNode = nextNode->next;
	}
}

int Countlist(LINK head)//노드개수 함수
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

void Medium(LINK head, int cnt)//중간위치에 있는 자료의 값 출력 함수
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
		printf("중간값:%d ", nextNode->value);
		nextNode = nextNode->next;
		printf("%d", nextNode->value);
	}
}

LINK Reverse(LINK head)//역순 함수
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

void Delete(LINK head, int cnt)//홀수번째 자료 삭제함수  
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