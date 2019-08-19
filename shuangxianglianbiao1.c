//
//  shuangxiang lianbiao.c
//  lianbiao
//
//  Created by jia jia  on 2019/8/19.
//  Copyright © 2019年 jia jia . All rights reserved.
//

//双向链表 是为了快速从表里找到前驱结点，而不用去遍历表
//其实双向链表已经可以找到前驱后继了，这个时候链表本身循环意义就不大了
#include "danlianbiao.c"
#include "stdio.h"


//定义
typedef char ElemType;
typedef  struct DNode
{
    ElemType data;
    struct DNode *prior , *next;
}DNode,*DoubleList;

//操作1 前插。在p结点前面插入
int DLinkIns(DoubleList L,int i, ElemType e)
{
    DNode *s,*p;
    int k ;
    p=L ; k=0;
    while(p->next!=L&&k<i) //找插入位置
    {
        p=p->next;
        k=k+1;
    }
    if (p->next==L&&k!=i) //异常处理
    {
        printf("插入位置不合理！");
        return ERROR;
    }
    
    s=(DNode*)malloc(sizeof(DNode));//p就位，申请s结点空间
    
    if(s) // 这里的s和p都是指针  如果申请成功了 如果没申请成功的话，上边会是返回0 ，这样就不执行它
    {
        s->data=e; // 把要插入的值放到创建的结点里
        s->prior=p->prior;//s前头也指向p前面的结点
        p->prior->next= s;// p前面的结点后头指向s
        s->next = p; // s后头指向p
        p->prior= s; //p的前头指向s
        return OK ;
    }
    else return ERROR;
}

//操作2 删除结点

int DlinkDel(DoubleList L, int i , ElemType *e )
{
    DNode *p ;//指向要删除的结点
    int k ;
    p=L ; k=0;
    while (p->next!=L&&k<i)
    {
        p=p->next;
        k=k+1;}
    
    if(p->next==L&&k<i)
      {return ERROR ;}
    
    else {
        *e=p->data;
        p->prior->next = p->next;
        p->next->prior= p->prior;
        free(p);
        return OK ;
    }
   
        }


//调用函数
/*
DoubleList DL ;
Init_DLinklist(&DL);
...
*/
