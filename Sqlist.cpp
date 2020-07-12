#include "DataStructure.h"


typedef struct {
	ElemType *elem;	//�洢�ռ�Ļ�ַ
	int length; // ��ǰ����(Ԫ�ظ���)
	int listsize; //�洢����
}Sqlist;


Status InitList_sq(Sqlist &L) {
	L.elem = (ElemType*)malloc(INIT_SIZE * sizeof(ElemType));
	if (!L.elem)
	{
		return OVERFLOW;
	}
	L.length = 0;
	L.listsize = INIT_SIZE;
	return OK;
}

Status ListInsert_sq(Sqlist &L,int i,ElemType x) {
	if (i<1||i>L.length+1) //�ж��Ƿ�Խ��
	{
		return ERROR;
	}
	if (L.length>=L.listsize) //��ѯ�Ƿ�������������һ������
	{	/*
			extern void *realloc(void *mem_address, unsigned int newsize); 
				�ı�mem_address��ָ���ڴ�����Ĵ�СΪnewsize��
			
			if	������������㹻���õ��ڴ�ռ䣬
				�����ԭ�ڴ��ַ�����ϣ�������չ��
			else 
				�������ڴ���У���һ���µ������ڴ�ռ䣬���з��䣬����֮ǰ�����ݸ��ƹ�ȥ��

			����ֵ��
				void����ָ�룺�������ɹ����ɽ�����һ������ǿ��ת����
				NULL:
					1.���޿ռ�ɷ���
					2.����newsize����Ϊ0�����µ�ǰ��ַ�ռ�free
		*/
	
		ElemType* newbase = (ElemType*)realloc(L.elem, (L.listsize + INCREMENT) * sizeof(ElemType));
		if (!newbase)
		{	
			exit(OVERFLOW);
		}
		L.elem = newbase;
		L.listsize += INCREMENT;
	}
	ElemType *q = &(L.elem[i - 1]); //��ȡ��Ҫ����λ�õ�Ԫ�ص�ַ
	for (ElemType *p=&(L.elem[L.length-1]);p>=q;--p)//�����һλԪ�صĵ�ַ��
	{	
		//���Ӳ���λ�����Ԫ�أ�ͳһ������һλ
		*(p + 1) = *p;
	}
	*q = x; //��ֵ
	L.length++; //Ԫ�ظ���++
	return OK;
}

Status ListDelete_sq(Sqlist& L, int i, ElemType &x) {
	if (i<1||i>L.length)
	{
		return ERROR;
	}
	ElemType* p = &(L.elem[i - 1]); //ȡ����ɾ����ַ��ֵ
	x = *p; //����ɾ��ֵ����x ���Է���
	for (ElemType* q=&(L.elem[L.length-1]);p+1<=q;p++) //����ǰ��
	{
		*p = *(p + 1);
	}
	L.length--;
	return OK;
}

Status ListPrintf_sq(Sqlist& L) {
	ElemType* p = L.elem;
	int length = L.length;
	while (length--)
	{
		printf("%d \t", *(p++));
		if (length%5==0)
		{
			printf("\n");
		}
	}
	printf("\n");
	return OK;
}

void MergeList_Sq(Sqlist La, Sqlist Lb, Sqlist& Lc) {
	/*
		��֪˳�����Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
		�鲢La��Lb�õ��µ�˳���Lc
		Lc��Ԫ��Ҳ��ֵ�ǵݼ�����
	*/
	int LaLength = La.length;
	int LbLength = Lb.length;
	ElemType* LaP = La.elem;
	ElemType* LbP = Lb.elem;
	ElemType* LcP = Lc.elem;
	int t = 0;
	int k = 0;
	for (int i = 0; i < LaLength; i++)
	{
		if (t+1==LbLength)  //��b�Ӵ�������ʱ����a׷�������
		{
			for ( ;i < LaLength; i++)
			{
				ListInsert_sq(Lc, k++, LaP[i]);
			}
				return;
		}
		if (i+1 == LaLength) //��a�Ӵ�������ʱ����b׷�������
		{
			for (;t < LbLength; t++)
			{

				ListInsert_sq(Lc, k++, LaP[t]);
			}
				return;
		}
		if (LaP[i] <= LbP[t])
		{
			ListInsert_sq(Lc, k++, LaP[i]);
			if (LaP[i] = LbP[t])
			{
				ListInsert_sq(Lc, k++, LbP[t++]);
			}
		}
		else
		{
			ListInsert_sq(Lc, k++, LbP[t++]);
			i--;
		}
	}
}




void MergeList_Sq_Second(Sqlist La, Sqlist Lb, Sqlist& Lc) {
	Lc.listsize = Lc.length = La.length + Lb.length;
	ElemType* pc = Lc.elem = (ElemType*)malloc(Lc.length * sizeof(ElemType));
	if (!pc)
	{
		exit (OVERFLOW);
	}
	ElemType* pa = La.elem, * pb = Lb.elem;
	ElemType* pa_last = pa + La.length, *pb_last = pb + Lb.length;
	while (pa<pa_last&&pb<pb_last)
	{
		if (*pa>*pb)
		{
			*pc++ = *pb++;
		}
		else if(*pa==*pb)
		{
			*pc++ = *pa++;
			*pc++ = *pb++;
		}
		else
		{
			*pc++ = *pa++;
		}
	}
	while (pa<pa_last)
	{
		*pc++ = *pa++;
	}
	while (pb<pb_last)
	{
		*pc++ = *pb++;
	}

}









//int main() {
//	Sqlist sq1,sq2;
//	InitList_sq(sq1);
//	InitList_sq(sq2);
//	Sqlist result;
//	InitList_sq(result);
//	for (int i=1,j = 1; i <= 10&&j<10; i++,j++)
//	{
//		if (i/3==1)
//		{
//			ListInsert_sq(sq1, i++, i);
//		}
//		ListInsert_sq(sq1, i, i);
//		ListInsert_sq(sq2, j, j);
//	}
//	ListPrintf_sq(sq1);
//	ListPrintf_sq(sq2);
//
//	//MergeList_Sq(sq1, sq2, result);
//	MergeList_Sq_Second(sq1, sq2, result);
//	ListPrintf_sq(result);
//	//ElemType a=0;
//	//ListDelete_sq(sq1, 20, a);
//	//ListPrintf_sq(sq1);
//	//printf("\n\n��ɾ��Ԫ�أ���ֵΪ��%d", a);
//	//printf("\n˳���ǰԪ�ظ�����%d\t", sq1.length);
//	//printf("\n˳���ǰ���������%d", sq1.listsize);
//	return OK;
//}
