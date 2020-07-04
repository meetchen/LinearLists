#include "DataStructure.h"
typedef struct {
	ElemType data;
	LNode* next;
}LNode, * LinkList;

Status GetElem_L(LinkList L, int i, ElemType& x) {
	if (i < 0)
	{
		return ERROR;
	}
	L = L->next;
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
	
	while (L||i>0)
	{
		L = L->next;
		i--;
	}
	if (i==0)
	{

	}
	LNode* node = (LinkList)malloc(sizeof(LNode));
}