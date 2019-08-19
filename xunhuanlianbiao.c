//
//  xunhuanlianbiao.c
//  lianbiao
//
//  Created by jia jia  on 2019/8/19.
//  Copyright © 2019年 jia jia . All rights reserved.
//

#include "stdio.h"
#include "danlianbiao.c" 

//循环链表
//循环链表只是单链表将收尾连接起来了而已，所以操作有些微变动
// 链表判空的时候： L->next == L ;
//判断一个结点是不尾结点：p->next==L;

//操作1 初始化循环单链表

void InitCLinkList(LinkList *CL) // CL 是一个二级地址
{
    *CL = (LinkList)malloc(sizeof(Node));//那么*CL就是i一级地址了
    (*CL)->next = *CL;
}

//操作2 尾指针rear表示的循环链表的建立

void CreatCLinklist(LinkList CL)//CL已指向一个存在的空链表
{
    Node *rear ,*s ; //也可以写 linklist rear, s;
    char c;
    rear=CL;
    c=getchar();
    while(c!='#')
    {
        s=(Node *)malloc(sizeof(Node));
        s->data= c;
        rear->next=s;
        rear =s ;
        c=getchar();
    }
    rear->next=CL;
}

//操作3 循环单链表的合并 ，将LB合并到LA之后（不排序）
LinkList merge_H(LinkList LA, LinkList LB)
{
    Node *p,*q;
    p=LA; q=LB;
    while(p->next!=LA) p->next; // 找尾结点
    while(q->next!=LB) q->next;
    p->next = LB->next ;
    q->next = LA;
    free(LB);
    return (LA);
}

//操作3 还是合并 这次用尾结点rear来实现， 因为上面找尾结点很费事，如果直接定好位的话，就很方便，以下。

LinkList merge_R(LinkList RA , LinkList RB)
{
    Node *p;
    p=RA->next;
    RA->next = RB->next->next;
    free(RB->next);
    RB->next=p;
    return RB;
}


