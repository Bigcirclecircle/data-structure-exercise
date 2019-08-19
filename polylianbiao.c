//
//  polyshunxvbiao.c
//  lianbiao
//
//  Created by jia jia  on 2019/8/19.
//  Copyright © 2019年 jia jia . All rights reserved.
//

#include "danlianbiao.c"
#include "stdio.h"

//表示多项式
typedef struct Polynode
{
    float coef; //系数
    int exp ; // 指数
    struct Polynode *next;
}Polynode,*Polylist;

//顺序存储

/*
 typedef struct
 {
 float coef;
 float expn;
 
 }ElemType;
 
 */
//不存指数也可以，用下标隐含表示，项数少并且指数高的话，还是要保存

//尾插法建立一元多项式单链表

void PolyCreate(Polylist head)
{
    Polynode *rear ,*s ;
    int c,e;
    rear=head; //此时为空指针
    scanf("%d,%d",&c,&e);
    while(c!=0) // ==0时 代表多项式输入结束
    {
        s=(Polynode*)malloc(sizeof(Polynode));
        s->coef =c;
        s->exp = e;
        rear->next=s ;
        rear=s ;
     scanf("%d,%d",&c,&e);
    }
    rear->next = NULL; //单链表 最后一个结点next置NULL
}

//一元多项式相加 实质是同指数项相加，系数合并，如果和等于零就删除结点
//指数不同就合并链表


//一元多项式加法

void polyadd(Polylist polya,Polylist polyb)

{
    Polynode *p,*q,*pre,*temp;//p指a链， q指b链
    p=polya->next;
    q=polyb->next;
    pre=polya ;//和多项式的尾结点，a的y头结点作为和多项式链的头结点
    
    while (p!=NULL&&q!=NULL) {
        if(p->exp < q->exp)
        {
            pre->next=p;
            pre=p;
            p=p->next;
        }
        else if (p->exp > q->exp)
        {
            pre->next=q;
            pre=q;
            q=q->next;
        }
        else {
            if(p->exp + q->exp ==0)
            {
                temp=p;
                p=p->next;
                free(temp);
                temp=q;
                 q=q->next;
                free(temp);
            }
            else{
                p->coef=p->coef+q->coef;
                pre->next=p;
                pre=p;
                p=p->next;
                temp=q;
                q=q->next;
                free(temp);
            }
                
            }
    
    }
    
    if(p!=NULL) pre->next=p;
    else pre->next =q ;
}
