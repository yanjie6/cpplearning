//#include<stdlib.h>
//#include<stdio.h>
////101003 qqw 96
////101001 as 76
////101002  rtty 56
//
//typedef struct node
//{
//	long num;
//	char name[10];
//
//	float sc;
//	struct node* next;
//}NODE, * linklist;
//
////node *head;
////linklist head;
//
//
////含有n个节点的链表，返回头指针
//linklist create(int n)
//{
//	linklist h, p, q;
//	int i;
//	h = (linklist)malloc(sizeof(NODE));
//	scanf("%ld%s%f", &h->num, h->name, &h->sc);
//	q = p = h;
//	for (i = 1; i < n; i++)
//	{
//		q = p;
//		p = (linklist)malloc(sizeof(NODE));
//		scanf("%ld%s%f", &p->num, p->name, &p->sc);
//		q->next = p;
//	}
//	p->next = NULL;
//	return h;
//}
////打印链表
//void pt(linklist head)
//{
//	linklist p = head;
//	while (p != NULL)
//	{
//		printf("%ld %s %.0f\n", p->num, p->name, p->sc);
//		p = p->next;
//	}
//}
////计算平均分数
//float average(linklist head)
//{
//	linklist p;
//	float ave = 0;
//	int c = 0;
//	p = head;
//	while (p != NULL)//while(p)
//	{
//		ave += p->sc;
//		c++;
//		p = p->next;
//	}
//	ave = ave / c;
//	return ave;
//}
//
////寻找
//linklist search(linklist head, char xm[])
//{
//	linklist p;
//	for (p = head; p; p = p->next)
//		if (strcmp(p->name, xm) == 0)
//			return p;
//	return NULL;
//}
//
//
//main()
//{
//	linklist head, p;
//	int n = 3;
//	char xm[10];
//	float ave = 0.0;
//	head = create(3);
//	pt(head);
//	ave = average(head);
//	printf("\nave =%.5.1f\n", ave);
//	printf("请输入要查找的学生姓名：");
//	scanf("%s", xm);
//	p = search(head, xm);
//	if (p != NULL)
//		printf("%ld %s %.0f\n", p->num, p->name, p->sc);
//	else
//		printf("没有这个学生\n");
//
//}