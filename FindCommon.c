#include <stdio.h>
#include<stdlib.h>

/*链表结构体定义（带头结点）*/
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, *LinkList;

/*基础工具函数*/

//1.初始化链表（带头结点）
LinkList InitList(void) {
	LinkList L = (LinkList)malloc(sizeof(LNode));
	if (!L) { printf("内存分配失败！\n");exit(1); }
	L->next = NULL;
	return L;
}

//2.尾插法插入元素
void Insert(LinkList L, int x) {
	LNode* p = L;
	while (p->next)p = p->next;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (!s) { printf("内存分配失败\n");exit(1); }
	s->data = x;
	s->next = NULL;
	p->next = s;
}

//3.打印链表
void Print(LinkList L) {
	LNode* p = L->next;
	while (p) {
		printf("&d->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

//4.求链表长度（不含头结点）
int Length(LinkList L) {
	int len = 0;
	LNode* p = L->next;
	while (p) { len++;p = p->next; }
	return len;
}

//5.销毁链表
void DestroyList(LinkList L) {
	LNode* p = L;
	while (p) {
		LNode* t = p;
		p = p->next;
		free(t);
	}
}

/*408核心算法：求第一个公共结点
算法思想：先分别求两链表长度，让较长的先走差步
		 然后同步遍历，第一个相等的结点即为公共结点
时间复杂度：O(lenA+lenB)
空间复杂度：O(1)*/

LNode* FindCommon(LinkList A, LinkList B) {
	//边界防护
	if (!A || !B)return NULL;

	int lenA = Length(A), lenB = Length(B);
	LNode* p = A->next;
	LNode* q = B->next;

	//对齐起点
	while (lenA > lenB) { p = p->next;lenA--; }
	while (lenB > lenA) { q = q->next;lenB--; }

	//同步遍历寻找公共结点
	while (p != NULL && p != q) {
		p = p->next;
		q = q->next;
	}
	return p;//若没有公共结点，此时p为NULL
}

/*主函数测试*/
int main(void) {
    printf("用例1：有公共结点（Y 字形）\n");

    // 创建公共部分 6->7->8
    LinkList common = InitList();
    Insert(common, 6);
    Insert(common, 7);
    Insert(common, 8);

    // 创建A链表 1->2->3->6->7->8
    LinkList A = InitList();
    Insert(A, 1);
    Insert(A, 2);
    Insert(A, 3);
    LNode* tailA = A;
    while (tailA->next) tailA = tailA->next;
    tailA->next = common->next; // 拼接公共部分

    // 创建B链表 4->5->6->7->8
    LinkList B = InitList();
    Insert(B, 4);
    Insert(B, 5);
    LNode* tailB = B;
    while (tailB->next) tailB = tailB->next;
    tailB->next = common->next; // 拼接公共部分

    printf("A: "); Print(A);
    printf("B: "); Print(B);

    LNode* res = FindCommon(A, B);
    if (res) printf("第一个公共结点 = %d\n\n", res->data);
    else     printf("无公共结点\n\n");

    // 安全释放：必须先断开连接，防止重复释放公共结点
    tailA->next = NULL;
    tailB->next = NULL;
    DestroyList(A);
    DestroyList(B);
    DestroyList(common);

    printf("用例2：无公共结点\n");
    LinkList C = InitList();
    Insert(C, 1);
    Insert(C, 2);
    LinkList D = InitList();
    Insert(D, 9);
    Insert(D, 8);
    Insert(D, 7);

    printf("C: "); Print(C);
    printf("D: "); Print(D);

    res = FindCommon(C, D);
    if (res) printf("第一个公共结点 = %d\n", res->data);
    else     printf("无公共结点（返回 NULL）\n");

    DestroyList(C);
    DestroyList(D);

    return 0;
}
