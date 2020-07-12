#include "DataStructure.h"


typedef struct {
	ElemType *elem;	//存储空间的基址
	int length; // 当前长度(元素个数)
	int listsize; //存储容量
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
	if (i<1||i>L.length+1) //判断是否越界
	{
		return ERROR;
	}
	if (L.length>=L.listsize) //查询是否已满，考虑下一步扩容
	{	/*
			extern void *realloc(void *mem_address, unsigned int newsize); 
				改变mem_address所指向内存区域的大小为newsize；
			
			if	当初区域后方有足够闲置的内存空间，
				则会在原内存地址基础上，进行扩展。
			else 
				将会在内存堆中，找一块新的连续内存空间，进行分配，并将之前的内容复制过去。

			返回值：
				void类型指针：即操作成功，可进行下一步类型强制转换；
				NULL:
					1.即无空间可分配
					2.传入newsize参数为0，导致当前地址空间free
		*/
	
		ElemType* newbase = (ElemType*)realloc(L.elem, (L.listsize + INCREMENT) * sizeof(ElemType));
		if (!newbase)
		{	
			exit(OVERFLOW);
		}
		L.elem = newbase;
		L.listsize += INCREMENT;
	}
	ElemType *q = &(L.elem[i - 1]); //获取需要插入位置的元素地址
	for (ElemType *p=&(L.elem[L.length-1]);p>=q;--p)//（最后一位元素的地址）
	{	
		//将从插入位置起的元素，统一往后移一位
		*(p + 1) = *p;
	}
	*q = x; //赋值
	L.length++; //元素个数++
	return OK;
}

Status ListDelete_sq(Sqlist& L, int i, ElemType &x) {
	if (i<1||i>L.length)
	{
		return ERROR;
	}
	ElemType* p = &(L.elem[i - 1]); //取到欲删除地址的值
	x = *p; //将欲删除值赋给x 予以返回
	for (ElemType* q=&(L.elem[L.length-1]);p+1<=q;p++) //批量前移
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
		已知顺序线性表La和Lb的元素按值非递减排列
		归并La和Lb得到新的顺序表Lc
		Lc的元素也按值非递减排列
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
		if (t+1==LbLength)  //当b子串放置满时，将a追加在其后
		{
			for ( ;i < LaLength; i++)
			{
				ListInsert_sq(Lc, k++, LaP[i]);
			}
				return;
		}
		if (i+1 == LaLength) //当a子串放置完时，将b追加在其后
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
//	//printf("\n\n已删除元素，其值为：%d", a);
//	//printf("\n顺序表当前元素个数：%d\t", sq1.length);
//	//printf("\n顺序表当前最大容量：%d", sq1.listsize);
//	return OK;
//}
