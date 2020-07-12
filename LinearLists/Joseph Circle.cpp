#include "DataStructure.h"
#include <iostream>
typedef struct JosephCircle {
	int No; //编号
	unsigned int Pwd; //密码
	struct JosephCircle* next;
}Node, * LinkList;

/*
	创建长度为n，带头结点的循环链表
	返回头结点地址
	其头结点 Pwd 字段，表示循环链表长度
*/
LinkList InitJC(int n){
	
	LinkList L = (LinkList)malloc(sizeof(Node)); //头结点
	LinkList result = L; //存头结点地址
	LinkList head = NULL;
	L->next = NULL;
	L->No = 0;
	L->Pwd = n; //存贮列表长度
	printf("开始准备长度为%d的,Joseph Circle,请输入每个密码，按回车完成\n", L->Pwd);
	for (int i = 0; i < n; i++)
	{
		LinkList p= (LinkList)malloc(sizeof(Node));
		if (i==0)
		{
			head = p; //保存第一个节点的地址，用于完成循环链表
		}
		p->No = i + 1;
		scanf("%d", &(p->Pwd));
		L->next = p;
		L = L->next;
		L->next = NULL;
	}
	L->next = head;  //即将最后一个节点的next域 填充为 第一个节点地址，构成循环
	printf("Joseph Circle 初始化完成\n");
	return result;
}
/*
	删除以当前头结点所指，从1开始计数，删除第n个元素
	并使得头结点 指向被删除结点的 下一个节点
*/
int RmNode(LinkList& L, int n) {
	int length = L->Pwd;
	LinkList p = L;
	int pwd,no= 0;
	// 如果循环链表长度为1，即最后一个，直接删除即可
	if (length==1)
	{
		pwd = L->next->Pwd;
		no = L->next->No;
		L->next = NULL;
		L->Pwd = 0;
		cout << "此时出队元素序号为\t" << no << "\t其密码值为\t" << pwd;
		return pwd;
	}
	int BeforNeedRm = n > length ? n % length - 1 : n-1; // 获取需删除节点的前一个节点
	if (BeforNeedRm==0)
	{   // ==0 即是 欲删除节点为第一个节点， 其前一个节点即为最后一个结点
		BeforNeedRm = length ;
	}
	
	while (BeforNeedRm--)
	{
		L = L->next; // 获取需删除节点的前一个节点
	}
	// 获取欲删除节点的密码与No
	pwd = L->next->Pwd; 
	no = L->next->No;
	// 删除欲删除节点
	L->next = L->next->next;
	// 使得头结点指向 已删除节点的 下一个结点
	p->next = L->next;
	p->Pwd = length - 1;
	p->No = 0;
	// 将处理后的头结点数据 赋给 原头结点地址
	L = p;
	cout << "此时出队元素序号为\t" << no << "\t其密码值为\t" << pwd;
	return pwd;
}
/*
	打印输出循环链表
*/
Status display(LinkList L) {
	if (L->next==NULL||L->Pwd==0)
	{
		return  ERROR;
	}
	else {
		LinkList p = L->next;
		L = L->next;
		cout << "\t此时队伍序号为\t";
		do
		{
			cout <<L->No;
			L = L->next;
		} while (p != L);
	}
	cout << endl;
}


//int main() {
//	int num,m = 0;
//	cout << "请输入参赛人数个数" << endl;
//	cin >> num;
//	LinkList L = InitJC(num);
//	cout << "请输入第一个m" << endl;
//	cin >> m;
//	while (L->Pwd != 0)
//	{
//		m = RmNode(L,m);
//		display(L);
//	}
//	cout << "\n游戏结束 ,祝你一战成硕。嘻嘻嘻" << endl;
//}