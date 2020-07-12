#include "DataStructure.h"
#include <iostream>
typedef struct JosephCircle {
	int No; //���
	unsigned int Pwd; //����
	struct JosephCircle* next;
}Node, * LinkList;

/*
	��������Ϊn����ͷ����ѭ������
	����ͷ����ַ
	��ͷ��� Pwd �ֶΣ���ʾѭ��������
*/
LinkList InitJC(int n){
	
	LinkList L = (LinkList)malloc(sizeof(Node)); //ͷ���
	LinkList result = L; //��ͷ����ַ
	LinkList head = NULL;
	L->next = NULL;
	L->No = 0;
	L->Pwd = n; //�����б���
	printf("��ʼ׼������Ϊ%d��,Joseph Circle,������ÿ�����룬���س����\n", L->Pwd);
	for (int i = 0; i < n; i++)
	{
		LinkList p= (LinkList)malloc(sizeof(Node));
		if (i==0)
		{
			head = p; //�����һ���ڵ�ĵ�ַ���������ѭ������
		}
		p->No = i + 1;
		scanf("%d", &(p->Pwd));
		L->next = p;
		L = L->next;
		L->next = NULL;
	}
	L->next = head;  //�������һ���ڵ��next�� ���Ϊ ��һ���ڵ��ַ������ѭ��
	printf("Joseph Circle ��ʼ�����\n");
	return result;
}
/*
	ɾ���Ե�ǰͷ�����ָ����1��ʼ������ɾ����n��Ԫ��
	��ʹ��ͷ��� ָ��ɾ������ ��һ���ڵ�
*/
int RmNode(LinkList& L, int n) {
	int length = L->Pwd;
	LinkList p = L;
	int pwd,no= 0;
	// ���ѭ��������Ϊ1�������һ����ֱ��ɾ������
	if (length==1)
	{
		pwd = L->next->Pwd;
		no = L->next->No;
		L->next = NULL;
		L->Pwd = 0;
		cout << "��ʱ����Ԫ�����Ϊ\t" << no << "\t������ֵΪ\t" << pwd;
		return pwd;
	}
	int BeforNeedRm = n > length ? n % length - 1 : n-1; // ��ȡ��ɾ���ڵ��ǰһ���ڵ�
	if (BeforNeedRm==0)
	{   // ==0 ���� ��ɾ���ڵ�Ϊ��һ���ڵ㣬 ��ǰһ���ڵ㼴Ϊ���һ�����
		BeforNeedRm = length ;
	}
	
	while (BeforNeedRm--)
	{
		L = L->next; // ��ȡ��ɾ���ڵ��ǰһ���ڵ�
	}
	// ��ȡ��ɾ���ڵ��������No
	pwd = L->next->Pwd; 
	no = L->next->No;
	// ɾ����ɾ���ڵ�
	L->next = L->next->next;
	// ʹ��ͷ���ָ�� ��ɾ���ڵ�� ��һ�����
	p->next = L->next;
	p->Pwd = length - 1;
	p->No = 0;
	// ��������ͷ������� ���� ԭͷ����ַ
	L = p;
	cout << "��ʱ����Ԫ�����Ϊ\t" << no << "\t������ֵΪ\t" << pwd;
	return pwd;
}
/*
	��ӡ���ѭ������
*/
Status display(LinkList L) {
	if (L->next==NULL||L->Pwd==0)
	{
		return  ERROR;
	}
	else {
		LinkList p = L->next;
		L = L->next;
		cout << "\t��ʱ�������Ϊ\t";
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
//	cout << "�����������������" << endl;
//	cin >> num;
//	LinkList L = InitJC(num);
//	cout << "�������һ��m" << endl;
//	cin >> m;
//	while (L->Pwd != 0)
//	{
//		m = RmNode(L,m);
//		display(L);
//	}
//	cout << "\n��Ϸ���� ,ף��һս��˶��������" << endl;
//}