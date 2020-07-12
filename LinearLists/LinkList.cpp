#include "DataStructure.h"
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

Status GetElem_L(LinkList p, int i, ElemType& x) {
	if (i < 0)
	{
		return ERROR;
	}
	LNode *L = p->next;
	while (i > 0 && L != NULL)
	{
		L = L->next;
		i--;
	}
	if (i == 0)
	{
		x = L->data;
		return OK;
	}
	return ERROR;
}

Status ListInsert_L(LinkList& L, int i, ElemType x) {
	LinkList p = L;
	L = L->next;
	while (L&&i>1)
	{
		L = L->next;
		i--;
	}
	if (i==1)
	{
		LNode* node = (LinkList)malloc(sizeof(LNode));
		node->data = x;
		node->next = L->next;
		L->next = node;
		L = p;
		return OK;
	}
	return ERROR;
}

Status CreatList_T(LinkList& p, int n) {
	// 尾插法 创建长度为n的链接
	LinkList L = p;
	int temp = 0;
	if (!L)
	{
		return OVERFLOW;
	}
	L->next = NULL;
	while (n--)
	{	
		L->next = (LinkList)malloc(sizeof(LNode));
		L = L->next;
		if (!L)
		{
			return OVERFLOW;
		}
		L->data = n;
		printf("\n链表输入：%d", L->data);
	}
	L->next = NULL;
}

Status PrintfLinkList(LinkList L) {
	L = L->next;
	printf("\n链表输出：");
	while (L)
	{
		printf("%d\t", L->data);
		L = L->next;
	}
	return OK;
}

Status InitLinkList(LinkList& L) {
	L = (LinkList)malloc(sizeof(LinkList));
	return OK;
}

Status DeleteLinkList(LinkList& L, int i, ElemType& x) {

	return 0;

	
} 


Status CreatList_H(LinkList& L, int n) {
	L->next = NULL;
	for (int i = 0; i < n; i++)
	{	
		LinkList p = (LinkList)malloc(sizeof(LNode)); //溢出判断未处理，可提供函数进行封装
		p->data = i;
		printf("%d,i=%d\t", p->data,i);
		p->next = L->next;
		L->next = p;
	}
	
	return OK;
}

//int main() {
//	LinkList L;
//	InitLinkList(L);
//	//CreatList_T(L, 10);
//	//PrintfLinkList(L);
//	CreatList_H(L, 10);
//	//ListInsert_L(L, 3, 10);
//	PrintfLinkList(L);
//}